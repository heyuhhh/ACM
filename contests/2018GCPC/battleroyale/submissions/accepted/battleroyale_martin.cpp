#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <sstream>
#include <stack>
#include <queue>
#include <map>
#include <climits>
#include <cstdio>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <functional>
#include <bitset>
#include <cctype>
#include <cassert>
using namespace std;
#ifdef DEBUG
#define db(a) (cout << (#a) << " = " << (a) << endl)
#else
#define db(a)
#endif
using ll = long long;

struct Point
{
	double x;
	double y;
};

struct Circle
{
	Point mid;
	double r;
};

double dist(const Point& p1, const Point& p2)
{
	return sqrt((p2.x - p1.x) * (p2.x - p1.x) + (p2.y - p1.y) * (p2.y - p1.y));
}

double dot(const Point& a, const Point& b)
{
	return a.x * b.x + a.y * b.y;
}

double length_circle_segment(const Circle& c, const double alpha)
{
	return static_cast<double>(c.r) * alpha;
}

double angle(const Point& a, const Point& o, const Point& b)
{
	double oa = dist(o, a);
	double ob = dist(o, b);
	Point v1 = {(o.x - a.x) / oa, (o.y - a.y) / ob};
	Point v2 = {(o.x - b.x) / ob, (o.y - b.y) / ob};
	return acos(dot(v1, v2));
}

Point mid_point(const Point& p1, const Point& p2)
{
	return {(p1.x+p2.x)/2.0, (p1.y+p2.y)/2.0};
}

vector<Point> intersect_circles(const Circle& c1, const Circle& c2)
{
	vector<Point> ret;
	double c = dist(c1.mid, c2.mid);
	db(c);
	if(c == 0.0) return ret;
	double x = ((c1.r * c1.r) + (c * c) - (c2.r * c2.r)) / (2.0 * c);
	db(x);
	if((c1.r * c1.r) - (x * x) < 0.0) return ret;
	double y = sqrt((c1.r * c1.r) - (x * x));
	db(y);
	Point e1 = {(c2.mid.x - c1.mid.x) / c, (c2.mid.y - c1.mid.y) / c};
	Point e2 = {-e1.y, e1.x};
	Point q1 = {c1.mid.x + x * e1.x + y * e2.x, c1.mid.y + x * e1.y + y * e2.y};
	Point q2 = {c1.mid.x + x * e1.x - y * e2.x, c1.mid.y + x * e1.y - y * e2.y};
	ret.push_back(q1);
	if(y != 0.0) ret.push_back(q2);
	return ret;
}

vector<Point> tangents(const Point& p, const Circle& c)
{	
	Point M = mid_point(p, c.mid);
	Circle Mc = {M.x, M.y, dist(p, M)};
	db(Mc.mid.x); db(Mc.mid.y); db(Mc.r);
	auto B = intersect_circles(Mc, c);
	db(B.size());
	assert(B.size() == 2);
	return B;
}

// unused
bool inside_circle(const Point& p, const Circle& c)
{
	return dist(p, c.mid) <= c.r;
}

/* Notes
 * Touching the cirlces is okay.
 * The red circle is completly inside the blue circle.
		If not the arc segments might leave the blue circle even though all the tangent points are inside.
 * The line segment start-end is always intersected by the red circle.
		Otherwise circle line-segment intersection code is required.
*/

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  Circle blue, red;
	Point start, end;
	cin >> start.x >> start.y;
	cin >> end.x >> end.y;
	cin >> blue.mid.x >> blue.mid.y >> blue.r;
	cin >> red.mid.x >> red.mid.y >> red.r;
		
	auto left = tangents(start, red);
	db(left[0].x);
	db(left[0].y);
	db(left[1].x);
	db(left[1].y);
	auto right = tangents(end, red);
	double distance = numeric_limits<double>::max();
	for(const auto& l : left) for(const auto& r : right)
	{		
		db(dist(start, l));
		db(180.0 * angle(l, red.mid, r) / acos(-1.0));
		db(length_circle_segment(red, angle(l, red.mid, r)));
		db(dist(r, end));
		double dis = dist(start, l);
		dis += length_circle_segment(red, angle(l, red.mid, r));
		dis += dist(r, end);
		db(dis);
		distance = min(distance, dis);
	}
	cout << std::fixed << std::setprecision(10) << distance << "\n";
  return 0;
}
