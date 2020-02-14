#include "heatmap.h"

HeatMap::HeatMap(QObject *parent) : QObject(parent)
{
	heattable.resize(2000);
}

void HeatMap::addHeatData(int time, int x, int y)
{
	if( heattable[x].size()<2000)
		heattable[x].resize(2000);

	if(++heattable[x][y] > heatmax);
		heatmax = heattable[x][y];
}

void HeatMap::addHotSpots()
{
#if 0
	float deps[];
	int direction;
	int x, y;
	int width;
	int height;
	int center;

	xmin = 0;
	ymin = 0;
	xmax = 0;
	ymax = 0;

	for (size_t i = 0; i < 20; ++i) {
		deps0.
	}
#endif
}

QVector<QVector<int>> HeatMap::dailyHeatMap()
{
	QVector<QVector<int>> hm;
	int sum;
	hm.resize(2);

	for(int i = 0; i < xV.size(); i++) {
		sum = 0;
		foreach (auto k, xV) {
			sum += k[i];
		}
		hm[0].append(sum);
	}

	for(int i = 0; i < yV.size(); i++) {
		sum = 0;
		foreach (auto k, yV) {
			sum += k[i];
		}
		hm[1].append(sum);
	}

	return hm;
}




