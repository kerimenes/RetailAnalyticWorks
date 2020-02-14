#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <templatewidget.h>

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::on_b_tempButton_clicked()
{
	TemplateWidget *t = new TemplateWidget("New Template");
	t->doShow();
}
