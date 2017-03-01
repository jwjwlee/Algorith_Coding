#include <iostream>
#include <cstdio>
#include <algorithm>
#define INF 987654321
using namespace std;

int main()
{
	double x1, x2, x3, x4, y1, y2, y3, y4, minx, maxx, miny, maxy;

	scanf("%lf %lf %lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
	minx = min(min(x1, x2), min(x3, x4));
	maxx = max(max(x1, x2), max(x3, x4));
	miny = min(min(y1, y2), min(y3, y4));
	maxy = max(max(y1, y2), max(y3, y4));

	double m1, m2;
	if ((x2 - x1) == 0) m1 = INF;
	else m1 = (y2 - y1) / (x2 - x1);

	if ((x4 - x3) == 0) m2 = INF;
	else m2 = (y4 - y3) / (x4 - x3);
	if (m1 == m2) {
		printf("0\n");
		return 0;
	}

	double x, y;
	if (m1 == INF) x = x1;
	else if (m2 == INF) x = x3;
	else x = (((m1 * x1) - (m2 * x3) + y3 - y1)) / (m1 - m2);

	if (m1 == 0) y = y1;
	else if (m2 == 0) y = y3;
	else y = ((m2 * y1) - (m1 * y3) + (m1 * m2 * x3) - (m1 * m2 * x1)) / (m2 - m1);
	if (x > minx && x < maxx && y > miny && y < maxy) printf("1\n");
	else printf("0\n");

	return 0;
}