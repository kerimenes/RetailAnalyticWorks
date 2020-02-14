#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <templatewidget.h>

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	setWindowTitle("YUBÇU Retail Analysis");
	this->setStyleSheet(
				"#centralWidget { "
				" border-image: url(:/stylesheets/retail.png) 0 0 0 0 stretch stretch;"
				"}");
	ui->b_f_m_ratio->setStyleSheet( "background-color: transparent; color:black;" );
	ui->b_sh1->setStyleSheet( "background-color: transparent; color:black;" );
	ui->b_sh2->setStyleSheet( "background-color: transparent; color:black;" );
	ui->b_sh3->setStyleSheet( "background-color: transparent; color:black;" );
	ui->b_sh4->setStyleSheet( "background-color: transparent; color:black;" );
	ui->b_sh5->setStyleSheet( "background-color: transparent; color:black;" );
	ui->b_sh6->setStyleSheet( "background-color: transparent; color:black;" );
	ui->b_sh7->setStyleSheet( "background-color: transparent; color:black;" );
	ui->b_sh8->setStyleSheet( "background-color: transparent; color:black;" );
	ui->b_tempButton->setStyleSheet( "background-color: transparent; color:black;" );

	connect(ui->b_f_m_ratio, SIGNAL(clicked(bool)), SLOT(clicked(bool)));
	connect(ui->b_sh1, SIGNAL(clicked(bool)), SLOT(clicked(bool)));
	connect(ui->b_sh2, SIGNAL(clicked(bool)), SLOT(clicked(bool)));
	connect(ui->b_sh3, SIGNAL(clicked(bool)), SLOT(clicked(bool)));
	connect(ui->b_sh4, SIGNAL(clicked(bool)), SLOT(clicked(bool)));
	connect(ui->b_sh5, SIGNAL(clicked(bool)), SLOT(clicked(bool)));
	connect(ui->b_sh6, SIGNAL(clicked(bool)), SLOT(clicked(bool)));
	connect(ui->b_sh7, SIGNAL(clicked(bool)), SLOT(clicked(bool)));
	connect(ui->b_sh8, SIGNAL(clicked(bool)), SLOT(clicked(bool)));
}

MainWindow::~MainWindow()
{
	delete ui;
}
#include <jsontoprotobuf.h>
#include <demographic/demographic.h>
#include <helper.h>
void MainWindow::clicked(bool b)
{
	QPushButton *btn = qobject_cast<QPushButton*> (QObject::sender());
	if (btn->text().contains("2")) {
		JsonToProtobuf *jbuf = new JsonToProtobuf("person.json", 1);
		QList<retail::yca::Person> pers = jbuf->getPersonList();
		DemographicManager *man = new DemographicManager();
		man->Reload(pers);
		auto x=man->GetResult("customers");
		TemplateWidget *t = new TemplateWidget("New Template");
		t->addYBarRange(0, 65);
		t->addXBarSet("male", 0, helper::VectorToQList(x.male_ages));
		t->addXBarSet("female", 1, helper::VectorToQList(x.female_ages));
		t->addXBarInfo({"0-18", "18-25", "25-35", "35-45", "45+"});
		t->doShow();
	}
}

void MainWindow::on_b_tempButton_clicked()
{
	TemplateWidget *t = new TemplateWidget("New Template");
	t->doShow();
}
