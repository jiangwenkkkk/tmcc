//
// Created by james on 2020-06-20.
//

#include <cstddef>

class Screen{
public:
	void *operator new(size_t size);
	void operator delete(void* , size_t );
	Screen(){
		next = nullptr;
	}
private:
	Screen *next;
	static Screen *freeStore;
	static const int screenChunk;
};

Screen *Screen::freeStore = 0;
const int Screen::screenChunk = 24;

/*
 * new 分配了一块内存，然后通过freeStore来控制内存的释放。
 * 如果内存不够了， 就再分配一个组，
 * 如果要释放一个对象，就把空间添加到空闲空间里面
 */
void *Screen::operator new( size_t size )
{
	Screen *p;
	if ( !freeStore ) {
// 链表空: 抓取一块存储区
// 这里调用全局 new
		size_t chunk = screenChunk * size;
		freeStore = p =
				reinterpret_cast< Screen* >( new char[ chunk ] );
// 现在把已经分配的内存串起来
		for ( ;
				p != &freeStore[ screenChunk - 1 ];
				++p )
			p->next = p+1;
		p->next = 0;
	}
	p = freeStore;
	freeStore = freeStore ->next;
	return p;
}
//下面是Screen 成员操作符delete()的一种可能的实现
void Screen::operator delete( void *p, size_t )
{
// 将被删除的对象插入到空闲链表尾
	( static_cast< Screen* >( p ) )->next = freeStore;
	freeStore = static_cast< Screen* >( p );
}


int main()
{
	auto p = new Screen;
}

/*
 * 通过new操作符的重载发现，
 * new操作符重载完后只是返回了一块够一个对象大小的内存地址，
 * 然后编译器自动调用对象的构造函数
 */