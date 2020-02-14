#ifndef TEMPLATEWIDGET_H
#define TEMPLATEWIDGET_H

#include <QWidget>
#include "qcustomplot.h"

#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QLegend>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include <QtCharts/QPieSeries>

class TemplateWidget : public QWidget
{
	Q_OBJECT
public:
	enum BarType {
		GRAPHIC = 0,
		DONAT = 1
	};
	explicit TemplateWidget(const QString &title, BarType type = GRAPHIC, QWidget *parent = nullptr);

	void setVerticalsValues();
	void doShow();
	void addXBarSet(const QString &name, int id, QList<int> values);
	void addXBarInfo(const QStringList &infos);
	void addYBarRange(int min, int max);
signals:

public slots:
protected:
	QCustomPlot *cplot;
	QtCharts::QChart *chart;
	QtCharts::QBarSeries *series;
	QtCharts::QBarCategoryAxis *axisX;
	QtCharts::QValueAxis *axisY;
	BarType type;

};

#endif // TEMPLATEWIDGET_H
