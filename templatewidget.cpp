#include "templatewidget.h"

using namespace QtCharts;

/*
 * people.json
 *
 * [
 *	{
 *	},
 *  {
 *  }
 * ]
 * */

TemplateWidget::TemplateWidget(const QString &title, BarType type, QWidget *parent)
	: QWidget(parent)
{
	setWindowTitle(title);
	this->type = type;

	chart = new QChart();
	chart->setTitle(title);
	series = new QBarSeries();
	axisX = NULL;
	axisY = NULL;
}

/**
 * @brief TemplateWidget::addXBarSet
 * @param name
 * @param id
 * @param values
 * veri tiplerini ekliyoruz. Ne tip'te veri birden fazla tipte veri tanıtabilirsiniz.
 * yaş cinsiyet vesaire id generic olsun die eklendi
 */
void TemplateWidget::addXBarSet(const QString &name, int id, QList<int> values)
{
	QBarSet *set;
	if (!name.isEmpty())
		set = new QBarSet(name);
	else set = new QBarSet(QString::number(id));

	foreach (int v, values) {
		*set << v;
	}
	series->append(set);
}

void TemplateWidget::addXBarInfo(const QStringList &infos)
{
	axisX = new QBarCategoryAxis();
	axisX->append(infos);
}

void TemplateWidget::addYBarRange(int min, int max)
{
	axisY = new QValueAxis();
	axisY->setRange(min, max);
}

void TemplateWidget::doShow()
{
	if (type == GRAPHIC) {
		chart->addSeries(series);
		chart->setAnimationOptions(QChart::SeriesAnimations);
		if (axisX) {
			chart->addAxis(axisX, Qt::AlignBottom);
			series->attachAxis(axisX);
		}
		if (axisY) {
			chart->addAxis(axisY, Qt::AlignLeft);
			series->attachAxis(axisY);
		}

		chart->legend()->setVisible(true);
		chart->legend()->setAlignment(Qt::AlignBottom);

		QChartView *chartView = new QChartView(chart);
		chartView->setRenderHint(QPainter::Antialiasing);
		QVBoxLayout *l = new QVBoxLayout;
		l->addWidget(chartView);
		setLayout(l);
		show();
	} else if (type == DONAT) {
#if 0
		QPieSeries *series = new QPieSeries();
		series->setHoleSize(0.35);
		series->append("Protein 4.2%", 4.2);
		QPieSlice *slice = series->append("Fat 15.6%", 15.6);
		slice->setExploded();
		slice->setLabelVisible();
		series->append("Other 23.8%", 23.8);
		series->append("Carbs 56.4%", 56.4);
#endif
	}
}
