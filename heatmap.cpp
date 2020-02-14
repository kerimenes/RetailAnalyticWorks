#include "heatmap.h"

HeatMap::HeatMap(QObject *parent) : QObject(parent)
{
	xV.resize(24);
	yV.resize(24);

}

void HeatMap::addHeatData(int time, int x, int y)
{
	if(xV[time].size() < 2000)
		xV[time].resize(2000);
	if(yV[time].size() < 2000)
		yV[time].resize(2000);

	++xV[time][x];
	++yV[time][y];
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




