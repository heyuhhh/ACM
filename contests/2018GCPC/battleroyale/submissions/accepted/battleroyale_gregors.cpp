#include <iostream>
#include <cmath>
#include <utility>
using namespace std;

typedef pair<double,double> Point;
#define x first
#define y second

double dist(Point &p1, Point &p2)
{
	return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}

double correctAngle(double w)
{
	if (w > 2 * M_PI) 
		w -= 2 * M_PI;
	else if (w < 0) 
		w += 2 * M_PI;
	return w;
}

void tangents(Point &p, Point &c, double &r, double &tangLen, double &w1, double &w2)
{
	double d = dist(p,c);
	tangLen = sqrt(d * d - r * r);
	double z = atan2(p.y - c.y, p.x - c.x);
	double delta = atan(tangLen/r);
	w1 = correctAngle(z + delta);
	w2 = correctAngle(z - delta);
}

double arcLen(double r, double w1, double w2)
{
	double d = correctAngle(w1 - w2);
	return r * min(d, 2 * M_PI - d);
}

int main()
{
	Point src, dst, c;
	double r;
	cin >> src.x >> src.y >> dst.x >> dst.y >> c.x >> c.y >> r >> c.x >> c.y >> r;
	double tangLen1, w1, w2;
	tangents(src, c, r, tangLen1, w1, w2);
	double tangLen2, z1, z2;
	tangents(dst, c, r, tangLen2, z1, z2);
	double a = min(min(arcLen(r,w1,z1),arcLen(r,w1,z2)), min(arcLen(r,w2,z1),arcLen(r,w2,z2)));
	double res = tangLen1 + a + tangLen2;
	res = round(res * 1e6) / 1e6;
	printf("%.6f\n", res);
}
