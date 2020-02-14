#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();

protected slots:
	void clicked(bool b);
private slots:
	void on_b_tempButton_clicked();

private:
	Ui::MainWindow *ui;
	QList<QPushButton*> pbs;
};

#endif // MAINWINDOW_H
