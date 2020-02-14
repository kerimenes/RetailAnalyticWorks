#include "mainwindow.h"
#include <QApplication>

#include <QFile>
static void setStyleSheets(const QString &file)
{
	QString styleSheet;
	QFile f(file);
	if (f.open(QIODevice::ReadOnly))
		styleSheet = f.readAll();
	f.close();
	if (!styleSheet.isEmpty())
		qApp->setStyleSheet(styleSheet);
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	setStyleSheets(":/stylesheets/dark.qss");
	MainWindow w;
	w.show();

	return a.exec();
}
