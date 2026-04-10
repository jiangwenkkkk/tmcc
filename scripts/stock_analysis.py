#!/usr/bin/env python3
"""
A股市场走势与国际形势分析脚本
每个工作日北京时间 9:00 和 14:58 运行，分析市场行情并生成报告。
"""

import json
import os
import sys
import urllib.request
import urllib.error
from datetime import datetime, timezone, timedelta

# 北京时间
BJT = timezone(timedelta(hours=8))


def fetch_json(url, timeout=15):
    """从 URL 获取 JSON 数据。"""
    req = urllib.request.Request(
        url,
        headers={
            "User-Agent": (
                "Mozilla/5.0 (Windows NT 10.0; Win64; x64) "
                "AppleWebKit/537.36 (KHTML, like Gecko) "
                "Chrome/120.0.0.0 Safari/537.36"
            ),
            "Referer": "https://finance.sina.com.cn",
        },
    )
    try:
        with urllib.request.urlopen(req, timeout=timeout) as resp:
            return json.loads(resp.read().decode("utf-8"))
    except Exception as exc:
        print(f"[WARN] 请求 {url} 失败: {exc}", file=sys.stderr)
        return None


def fetch_text(url, timeout=15):
    """从 URL 获取文本数据。"""
    req = urllib.request.Request(
        url,
        headers={
            "User-Agent": (
                "Mozilla/5.0 (Windows NT 10.0; Win64; x64) "
                "AppleWebKit/537.36 (KHTML, like Gecko) "
                "Chrome/120.0.0.0 Safari/537.36"
            ),
            "Referer": "https://finance.sina.com.cn",
        },
    )
    try:
        with urllib.request.urlopen(req, timeout=timeout) as resp:
            raw = resp.read()
            for enc in ("utf-8", "gbk", "gb2312"):
                try:
                    return raw.decode(enc)
                except UnicodeDecodeError:
                    continue
            return raw.decode("utf-8", errors="replace")
    except Exception as exc:
        print(f"[WARN] 请求 {url} 失败: {exc}", file=sys.stderr)
        return None


# ---------------------------------------------------------------------------
# 数据获取
# ---------------------------------------------------------------------------

def parse_sina_hq(text):
    """解析新浪行情接口返回的文本（var hq_str_... = "...";）。"""
    results = {}
    if not text:
        return results
    for line in text.strip().split("\n"):
        line = line.strip()
        if "=" not in line:
            continue
        var_part, val_part = line.split("=", 1)
        code = var_part.split("_")[-1].strip()
        fields = val_part.strip().strip('"').strip(";").strip('"').split(",")
        results[code] = fields
    return results


def get_a_share_indices():
    """获取A股主要指数行情（上证指数、深证成指、创业板指）。"""
    codes = "s_sh000001,s_sz399001,s_sz399006"
    url = f"https://hq.sinajs.cn/list={codes}"
    text = fetch_text(url)
    data = parse_sina_hq(text)

    indices = []
    name_map = {
        "s_sh000001": "上证指数",
        "s_sz399001": "深证成指",
        "s_sz399006": "创业板指",
    }
    for code, name in name_map.items():
        fields = data.get(code)
        if fields and len(fields) >= 4:
            indices.append({
                "name": name,
                "price": fields[1],
                "change": fields[2],
                "change_pct": fields[3],
            })
    return indices


def get_international_indices():
    """获取国际主要指数行情。"""
    codes = (
        "int_dji,"        # 道琼斯
        "int_nasdaq,"     # 纳斯达克
        "int_sp500,"      # 标普500
        "int_hangseng,"   # 恒生指数
        "int_nikkei,"     # 日经225
        "b_FSSTI"         # 富时新加坡
    )
    url = f"https://hq.sinajs.cn/list={codes}"
    text = fetch_text(url)
    data = parse_sina_hq(text)

    name_map = {
        "int_dji": "道琼斯工业指数",
        "int_nasdaq": "纳斯达克综合指数",
        "int_sp500": "标普500指数",
        "int_hangseng": "恒生指数",
        "int_nikkei": "日经225指数",
        "b_FSSTI": "富时新加坡STI",
    }

    indices = []
    for code, name in name_map.items():
        fields = data.get(code)
        if fields and len(fields) >= 2:
            # 国际指数格式略有不同
            try:
                indices.append({
                    "name": name,
                    "price": fields[0] if len(fields) > 0 else "N/A",
                    "change": fields[1] if len(fields) > 1 else "N/A",
                    "change_pct": fields[2] if len(fields) > 2 else "N/A",
                })
            except (IndexError, ValueError):
                indices.append({"name": name, "price": "N/A", "change": "N/A", "change_pct": "N/A"})
    return indices


def get_sector_performance():
    """获取A股主要板块表现（简化版，使用板块指数）。"""
    # 行业板块代表性ETF/指数
    codes = (
        "sh512010,"   # 医药ETF
        "sh512660,"   # 军工ETF
        "sh512800,"   # 银行ETF
        "sh515030,"   # 新能源车ETF
        "sh512480,"   # 半导体ETF
        "sh515790,"   # 光伏ETF
        "sh512690,"   # 酒ETF
        "sh512170"    # 医疗ETF
    )
    url = f"https://hq.sinajs.cn/list={codes}"
    text = fetch_text(url)
    data = parse_sina_hq(text)

    name_map = {
        "sh512010": "医药ETF",
        "sh512660": "军工ETF",
        "sh512800": "银行ETF",
        "sh515030": "新能源车ETF",
        "sh512480": "半导体ETF",
        "sh515790": "光伏ETF",
        "sh512690": "酒ETF",
        "sh512170": "医疗ETF",
    }

    sectors = []
    for code, name in name_map.items():
        fields = data.get(code)
        if fields and len(fields) >= 4:
            try:
                cur = float(fields[3])
                prev_close = float(fields[2])
                change_pct = ((cur - prev_close) / prev_close * 100) if prev_close else 0
                sectors.append({
                    "name": name,
                    "price": f"{cur:.3f}",
                    "change_pct": f"{change_pct:+.2f}%",
                    "change_pct_val": change_pct,
                })
            except (IndexError, ValueError):
                pass
    sectors.sort(key=lambda x: x.get("change_pct_val", 0), reverse=True)
    return sectors


def get_hot_stocks():
    """获取涨幅居前的个股（通过新浪涨幅榜接口）。"""
    url = "https://vip.stock.finance.sina.com.cn/quotes_service/api/json_v2.php/Market_Center.getHQNodeData?page=1&num=20&sort=changepercent&asc=0&node=hs_a&symbol=&_s_r_a=sort"
    data = fetch_json(url)
    if not data:
        return []
    stocks = []
    for item in data[:15]:
        try:
            stocks.append({
                "code": item.get("code", ""),
                "name": item.get("name", ""),
                "price": item.get("trade", ""),
                "change_pct": f"{float(item.get('changepercent', 0)):+.2f}%",
                "turnover": item.get("turnoverratio", ""),
                "volume": item.get("volume", ""),
            })
        except (ValueError, TypeError):
            pass
    return stocks


def get_exchange_rates():
    """获取主要汇率。"""
    codes = "fx_susdcny,fx_seurcny,fx_sjpycny,fx_sgbpcny"
    url = f"https://hq.sinajs.cn/list={codes}"
    text = fetch_text(url)
    data = parse_sina_hq(text)

    name_map = {
        "fx_susdcny": "美元/人民币",
        "fx_seurcny": "欧元/人民币",
        "fx_sjpycny": "日元/人民币",
        "fx_sgbpcny": "英镑/人民币",
    }

    rates = []
    for code, name in name_map.items():
        fields = data.get(code)
        if fields and len(fields) >= 1:
            rates.append({"name": name, "price": fields[0] if fields[0] else "N/A"})
    return rates


# ---------------------------------------------------------------------------
# 分析与报告
# ---------------------------------------------------------------------------

def analyze_market(a_indices, intl_indices, sectors, hot_stocks, rates):
    """基于获取的数据生成分析报告。"""
    now = datetime.now(BJT)
    time_str = now.strftime("%Y-%m-%d %H:%M:%S")

    report_lines = [
        f"# 📊 A股市场与国际形势分析报告",
        f"",
        f"> 🕐 报告生成时间：{time_str}（北京时间）",
        f"",
    ]

    # --- A股大盘 ---
    report_lines.append("## 🇨🇳 A股大盘走势\n")
    if a_indices:
        report_lines.append("| 指数 | 最新价 | 涨跌 | 涨跌幅 |")
        report_lines.append("|------|--------|------|--------|")
        for idx in a_indices:
            report_lines.append(
                f"| {idx['name']} | {idx['price']} | {idx['change']} | {idx['change_pct']}% |"
            )
        report_lines.append("")

        # 简要分析
        report_lines.append("### 大盘分析\n")
        for idx in a_indices:
            try:
                pct = float(idx["change_pct"])
                if pct > 1:
                    emoji = "🟢📈"
                    desc = "强势上涨，市场情绪偏多"
                elif pct > 0:
                    emoji = "🟢"
                    desc = "小幅上涨，多空博弈"
                elif pct > -1:
                    emoji = "🔴"
                    desc = "小幅下跌，观望情绪浓"
                else:
                    emoji = "🔴📉"
                    desc = "明显下跌，市场情绪偏空"
                report_lines.append(f"- {emoji} **{idx['name']}**：{desc}（{pct:+.2f}%）")
            except ValueError:
                report_lines.append(f"- **{idx['name']}**：数据解析中")
        report_lines.append("")
    else:
        report_lines.append("⚠️ A股数据暂时无法获取，可能非交易时段。\n")

    # --- 板块表现 ---
    report_lines.append("## 📦 板块表现（ETF追踪）\n")
    if sectors:
        report_lines.append("| 板块 | 最新价 | 涨跌幅 |")
        report_lines.append("|------|--------|--------|")
        for s in sectors:
            report_lines.append(f"| {s['name']} | {s['price']} | {s['change_pct']} |")
        report_lines.append("")

        # 板块建议
        report_lines.append("### 板块观察\n")
        top = [s for s in sectors if s.get("change_pct_val", 0) > 0.5]
        bottom = [s for s in sectors if s.get("change_pct_val", 0) < -0.5]
        if top:
            report_lines.append(f"- 🔥 **领涨板块**：{', '.join(s['name'] for s in top[:3])} — 资金流入明显, 可关注相关龙头。")
        if bottom:
            report_lines.append(f"- ❄️ **领跌板块**：{', '.join(s['name'] for s in bottom[:3])} — 资金流出，短期规避。")
        if not top and not bottom:
            report_lines.append("- 板块涨跌分化不大，市场处于横盘整理状态。")
        report_lines.append("")
    else:
        report_lines.append("⚠️ 板块数据暂时无法获取。\n")

    # --- 国际市场 ---
    report_lines.append("## 🌍 国际市场\n")
    if intl_indices:
        report_lines.append("| 指数 | 最新价 | 涨跌 | 涨跌幅 |")
        report_lines.append("|------|--------|------|--------|")
        for idx in intl_indices:
            report_lines.append(
                f"| {idx['name']} | {idx['price']} | {idx['change']} | {idx['change_pct']}% |"
            )
        report_lines.append("")
    else:
        report_lines.append("⚠️ 国际指数数据暂时无法获取。\n")

    # --- 汇率 ---
    report_lines.append("## 💱 主要汇率\n")
    if rates:
        report_lines.append("| 币种 | 汇率 |")
        report_lines.append("|------|------|")
        for r in rates:
            report_lines.append(f"| {r['name']} | {r['price']} |")
        report_lines.append("")
    else:
        report_lines.append("⚠️ 汇率数据暂时无法获取。\n")

    # --- 个股推荐 ---
    report_lines.append("## 🔍 今日涨幅居前个股（仅供参考）\n")
    if hot_stocks:
        report_lines.append("| 代码 | 名称 | 最新价 | 涨跌幅 | 换手率 |")
        report_lines.append("|------|------|--------|--------|--------|")
        for s in hot_stocks[:10]:
            report_lines.append(
                f"| {s['code']} | {s['name']} | {s['price']} | {s['change_pct']} | {s['turnover']}% |"
            )
        report_lines.append("")
    else:
        report_lines.append("⚠️ 个股排行数据暂时无法获取。\n")

    # --- 投资建议 ---
    report_lines.append("## 💡 综合分析与建议\n")

    # 基于指数涨跌给出建议
    overall_sentiment = "neutral"
    if a_indices:
        try:
            sh_pct = float(a_indices[0]["change_pct"])
            if sh_pct > 0.5:
                overall_sentiment = "bullish"
            elif sh_pct < -0.5:
                overall_sentiment = "bearish"
        except (ValueError, IndexError):
            pass

    if overall_sentiment == "bullish":
        report_lines.extend([
            "### 市场情绪：偏多 🟢\n",
            "- 大盘整体偏强，可适当加仓。",
            "- 关注领涨板块中的龙头个股，追踪主力资金流向。",
            "- 建议关注换手率适中（3%-8%）的活跃股票。",
            "- 设好止盈位，不盲目追高。",
        ])
    elif overall_sentiment == "bearish":
        report_lines.extend([
            "### 市场情绪：偏空 🔴\n",
            "- 大盘走弱，建议控制仓位，以观望为主。",
            "- 可关注防御性板块（银行、消费等）。",
            "- 避免追涨杀跌，等待企稳信号。",
            "- 可适当关注超跌反弹机会，但需严格止损。",
        ])
    else:
        report_lines.extend([
            "### 市场情绪：震荡 ⚖️\n",
            "- 市场处于震荡整理阶段，建议保持半仓操作。",
            "- 精选个股，关注业绩确定性强的标的。",
            "- 可采取高抛低吸策略。",
            "- 密切关注政策面和资金面变化。",
        ])

    # 板块推荐
    if sectors:
        top_sectors = [s for s in sectors if s.get("change_pct_val", 0) > 0][:3]
        if top_sectors:
            report_lines.append("\n### 推荐关注板块\n")
            for s in top_sectors:
                report_lines.append(f"- **{s['name']}**（涨幅 {s['change_pct']}）— 短线资金关注度高")

    report_lines.extend([
        "",
        "---",
        "",
        "⚠️ **免责声明**：本报告由自动化程序生成，数据来源于公开市场数据。",
        "所有分析和建议仅供参考，不构成任何投资建议。投资有风险，入市需谨慎。",
        "请结合自身情况和专业顾问意见做出投资决策。",
    ])

    return "\n".join(report_lines)


def create_github_issue(title, body):
    """通过 GitHub API 创建 Issue。"""
    token = os.environ.get("GITHUB_TOKEN", "")
    repo = os.environ.get("GITHUB_REPOSITORY", "")

    if not token or not repo:
        print("缺少 GITHUB_TOKEN 或 GITHUB_REPOSITORY 环境变量", file=sys.stderr)
        print("--- 报告内容 ---")
        print(body)
        return False

    url = f"https://api.github.com/repos/{repo}/issues"
    payload = json.dumps({
        "title": title,
        "body": body,
        "labels": ["stock-analysis", "auto-generated"],
    }).encode("utf-8")

    req = urllib.request.Request(
        url,
        data=payload,
        method="POST",
        headers={
            "Authorization": f"Bearer {token}",
            "Accept": "application/vnd.github.v3+json",
            "Content-Type": "application/json",
            "User-Agent": "stock-analysis-bot",
        },
    )

    try:
        with urllib.request.urlopen(req, timeout=30) as resp:
            result = json.loads(resp.read().decode("utf-8"))
            print(f"✅ Issue 创建成功: {result.get('html_url', 'N/A')}")
            return True
    except urllib.error.HTTPError as exc:
        error_body = exc.read().decode("utf-8") if exc.fp else ""
        print(f"❌ 创建 Issue 失败: {exc.code} {exc.reason}\n{error_body}", file=sys.stderr)
        return False
    except Exception as exc:
        print(f"❌ 创建 Issue 异常: {exc}", file=sys.stderr)
        return False


def ensure_labels_exist():
    """确保 Issue 标签存在。"""
    token = os.environ.get("GITHUB_TOKEN", "")
    repo = os.environ.get("GITHUB_REPOSITORY", "")
    if not token or not repo:
        return

    labels = [
        {"name": "stock-analysis", "color": "0075ca", "description": "股票分析报告"},
        {"name": "auto-generated", "color": "e4e669", "description": "自动生成的内容"},
    ]

    for label in labels:
        url = f"https://api.github.com/repos/{repo}/labels"
        payload = json.dumps(label).encode("utf-8")
        req = urllib.request.Request(
            url,
            data=payload,
            method="POST",
            headers={
                "Authorization": f"Bearer {token}",
                "Accept": "application/vnd.github.v3+json",
                "Content-Type": "application/json",
                "User-Agent": "stock-analysis-bot",
            },
        )
        try:
            urllib.request.urlopen(req, timeout=10)
        except urllib.error.HTTPError:
            pass  # 标签可能已存在


def main():
    now = datetime.now(BJT)
    date_str = now.strftime("%Y-%m-%d")
    if now.hour < 12:
        time_label = "开盘"
    elif now.hour >= 14:
        time_label = "收盘前"
    else:
        time_label = "盘中"

    print(f"📊 开始获取市场数据... ({date_str} {time_label})")

    # 并行获取各类数据
    a_indices = get_a_share_indices()
    intl_indices = get_international_indices()
    sectors = get_sector_performance()
    hot_stocks = get_hot_stocks()
    rates = get_exchange_rates()

    print(f"  A股指数: {len(a_indices)} 条")
    print(f"  国际指数: {len(intl_indices)} 条")
    print(f"  板块数据: {len(sectors)} 条")
    print(f"  热门个股: {len(hot_stocks)} 条")
    print(f"  汇率数据: {len(rates)} 条")

    # 生成分析报告
    report = analyze_market(a_indices, intl_indices, sectors, hot_stocks, rates)

    # 创建 GitHub Issue
    title = f"📊 {date_str} {time_label}分析 | A股走势与国际市场报告"
    ensure_labels_exist()
    success = create_github_issue(title, report)

    if not success:
        # 回退：输出到 stdout 以便在 Actions 日志中查看
        print("\n" + "=" * 60)
        print(report)
        print("=" * 60)
        sys.exit(1)


if __name__ == "__main__":
    main()
