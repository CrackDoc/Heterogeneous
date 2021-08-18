#include "Heterogeneous.h"
#include <QtWidgets/QApplication>
#include <QObject>
//#pragma comment( linker, "/subsystem:windows /entry:mainCRTStartup" )

int main(int argc, char* argv[])
{
	QApplication a(argc, argv);
	CHeterogeneous w;
	QObject::connect(&w, SIGNAL(SignalQuit()), &a, SLOT(quit()));
	w.show();
	return a.exec();
}

