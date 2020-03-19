//
// Created by james on 2019-04-28.
//

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <applicationdata.h>

#include <QThread>
#include <QDebug>


class MyThread : public QThread
{
Q_OBJECT
public:
signals:
	void don();
public:
	MyThread();

	void run();

};

MyThread::MyThread()
{
}

void MyThread::run()
{
	qDebug() << "Before sleep";
	sleep(1);

	emit(don());
	qDebug() << "After sleep";
}

int main(int argc, char *argv[])
{
	QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

	QGuiApplication app(argc, argv);

	MyThread myThread;

	QQmlApplicationEngine engine;
	QQmlContext *context = engine.rootContext();

	context->setContextProperty("thread", &myThread);

	engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
	if (engine.rootObjects().isEmpty())
		return -1;

	return app.exec();
}
