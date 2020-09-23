#include <bits/stdc++.h>

using namespace std;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const double PI = 2.0 * acos(0.0);


typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<string> vs;

#define sz(c) int((c).size())
#define all(c) (c).begin(), (c).end()
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define FORS(i,a,b,s) for (int i = (a); i < (b); i=i+(s))
#define FORD(i,a,b) for (int i = int(b)-1; i >= (a); i--)
#define FORIT(i,c) for (__typeof__((c).begin()) i = (c).begin(); i != (c).end(); i++)

typedef long double coord;

struct pt{
	coord x,y;
	pt():x(0),y(0){};
	pt(coord _x,coord _y):x(_x),y(_y){};

	pt operator+(const pt& p) { return pt(x+p.x,y+p.y); }
	pt operator-(const pt& p) { return pt(x-p.x,y-p.y); }
	pt operator*(const coord f) { return pt(x*f,y*f); }
	pt operator/(const coord f) { return pt(x/f,y/f); }
    bool operator <(const pt& p) const {
            return x < p.x || (x == p.x && y < p.y);
    }
	coord operator*(const pt& p) { return x*p.x+y*p.y; }
};
double len(pt p) { return sqrt(double(p*p)); }

double phi(pt p) { return atan2((double)p.y,p.x); }
pt points[2]; // results
void boundaryPoints(pt P, pt M, double r){ // circle is given by center point M and radius r
	double dx,dy;
	dx = M.x; dy = M.y;
	P.x -= dx; P.y -= dy;
	double rq = r*r,ypq = P.y*P.y, xpq = P.x*P.x;
	if(P.y == 0){
		points[0].x = points[1].x = rq/P.x;
		points[0].y = r*sqrt(1-rq/(xpq));
		points[1].y = -points[0].y;
	}
	else{
		points[0].x = (P.y*sqrt(rq*ypq+rq*xpq-rq*rq)+rq*P.x)/(ypq+xpq);
		points[0].y = (rq - points[0].x*P.x)/P.y;
		points[1].x = -(P.y*sqrt(rq*ypq+rq*xpq-rq*rq)-rq*P.x)/(ypq+xpq);
		points[1].y = (rq - points[1].x*P.x)/P.y;
	}
	points[0].x += dx; points[1].x += dx;
	points[0].y += dy; points[1].y += dy;
}

int main(){
	pt s,d; cin >> s.x >> s.y >> d.x >> d.y;
	pt c; double r; cin >> c.x >> c.y >> r; cin >> c.x >> c.y >> r;

	boundaryPoints(s,c,r); pt st[] = {points[0], points[1]};
	boundaryPoints(d,c,r); pt dt[] = {points[0], points[1]};

	double ml = oo;
	FOR(i,0,2) FOR(j,0,2){
		pt a = st[i] - c;
		pt b = dt[j] - c;
		double sa = atan2(a.x,a.y) + PI;
		double da = atan2(b.x,b.y) + PI;
		double diff = max(sa,da) - min(sa,da); if (diff > PI) diff = 2*PI - diff;
		double l = len(s - st[i]) + len(d - dt[j]) + diff *r;

		ml = min(ml,l);
	}
	cout << fixed << setprecision(6) << ml << endl;
}
