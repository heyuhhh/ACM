#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include <bits/stdc++.h>
using namespace std;

typedef double DB;
const DB PI = acosl(-1);
const DB INF = 1e10;
const DB EPS = 1e-8;

void Bug(bool b) { if (!b) while (1); }
inline DB sqr(DB x) { return x * x; }

struct PT {
	DB x, y;
	PT() {}
	PT(DB x, DB y) : x(x), y(y) {}
	void in() { 
		int _x, _y;
		cin >> _x >> _y; 
		x = _x, y = _y;
		Bug(abs(_x) <= 1000000);
		Bug(abs(_y) <= 1000000);
	}
	bool operator<(const PT& p) const{
		if (fabs(x - p.x) > EPS) return x < p.x;
		return y + EPS < p.y;
	}
	bool operator==(const PT&p) const {
		return fabs(p.x - x) < EPS && fabs(p.y - y) < EPS;
	}
};

PT operator+(PT p1, PT p2) { return PT(p1.x + p2.x, p1.y + p2.y); }
PT operator-(PT p1, PT p2) { return PT(p1.x - p2.x, p1.y - p2.y); }
PT operator*(PT p, DB c) { return PT(p.x * c, p.y * c); }
PT operator/(PT p, DB c) { return PT(p.x / c, p.y / c); }

DB dis(PT p) { return sqrt(sqr(p.x) + sqr(p.y)); }
DB vect(PT p1, PT p2) { return p1.x * p2.y - p2.x * p1.y; }
DB scal(PT p1, PT p2) { return p1.x * p2.x + p1.y * p2.y; }
DB vect(PT p, PT p1, PT p2) { return vect(p1 - p, p2 - p); }
DB scal(PT p, PT p1, PT p2) { return scal(p1 - p, p2 - p); }

int convex_hull(PT *p, int n, PT *q) {
	sort(p, p+n);
	n = unique(p, p+n) - p;
	if (n == 1) {
		q[0] = p[0];
		return 1;
	}
	int m = 0;
	for (int i = 0; i < n; i++) {
		while (m>1 && vect(q[m-2], q[m-1], p[i]) < EPS) m--;
		q[m++] = p[i];
	}
	int k = m;
	for (int i = n-2; i >= 0; i--) {
		while (m>k && vect(q[m-2], q[m-1], p[i]) < EPS) m--;
		q[m++] = p[i];
	}
	return --m;
}

bool z(DB x){ return fabs(x) < EPS; }
struct Line{
	DB a, b, c;
	Line (PT x, PT y) {
		a = x.y - y.y;
		b = y.x - x.x;
		c = -(a * x.x + b * x.y);
	}
	PT slope(){ return PT(a, b);}
}; 

PT cross(Line a, Line b){
	DB det = a.a * b.b - b.a * a.b;
	return PT((a.c * b.b - a.b * b.c) / det, (a.a * b.c - a.c * b.a) / det);
}

bool bad(Line a, Line b, Line c){
	if(vect(a.slope(), b.slope()) <= 0) return false;
	PT crs = cross(a, b);
	return crs.x * c.a + crs.y * c.b >= c.c;
}

deque<Line> dq;

bool solve(vector<Line> &v){
	dq.clear();
	for(auto &i : v){
		if(!dq.empty() && z(vect(dq.back().slope(), i.slope()))) continue;
		while(dq.size() >= 2 && bad(dq[dq.size() - 2], dq.back(), i)) dq.pop_back();
		while(dq.size() >= 2 && bad(i, dq[0], dq[1])) dq.pop_front();
		dq.push_back(i);
	}
	while(dq.size() > 2 && bad(dq[dq.size() - 2], dq.back(), dq[0])) dq.pop_back();
	while(dq.size() > 2 && bad(dq.back(), dq[0], dq[1])) dq.pop_front();
	for(int i = 0; i < dq.size(); i++){
		Line cur = dq[i], nxt = dq[(i+1)%dq.size()];
		if (vect(cur.slope(), nxt.slope()) < EPS) return 0;
	}
	return 1;
}

const int N = 110000;
vector<Line> VL;
PT P[N], Q[N], R[N], V[N];

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	cout.setf(ios::fixed); cout << setprecision(10);
	int ncase;
	int sum = 0, sumM = 0;
	for (cin >> ncase, Bug(ncase<=30); ncase--; ) {
		int n; cin >> n;
		Bug(n>=3 && n <= 50000);
		sum += n;
		for (int i = 0; i < n; i++) P[i].in();
		DB s = 0;
		for (int i = 0; i < n; i++) s += vect(P[i], P[(i + 1) % n]);
		if (s < 0) reverse(P, P+n);
		int m; cin >> m;
		Bug(1 <= m && m <= 100000);
		sumM += m;
		for (int i = 0; i < m; i++) Q[i].in();
		m = convex_hull(Q, m, R);
		for (int i = 0; i < m; i++) Q[i] = R[i];
		if (m <= 1) {
			cout << 0.0 << endl;
			continue;
		}
		DB ans = 1e100;
		for (int T = 0; T < 2; T++) {
			for (int i = 0; i < n; i++) P[i] = PT(-P[i].x, -P[i].y);
			for (int i = 0, j = 0; i < n; i++) {
				while (vect(P[(i+1)%n]-P[i], Q[(j-1+m)%m]-Q[j]) < -EPS || vect(P[(i+1)%n]-P[i], Q[(j+1)%m]-Q[j]) < -EPS) {
					j = (j+1)%m;
				}
				V[i] = Q[j];
			}
			DB st = 0, en = 1e10;
			for (int times = 0; times < 70; times++) {
				DB md = (st + en) / 2;
				VL.clear();
				for (int i = 0; i < n; i++) {
					VL.push_back(Line(P[i]*md - V[i], P[(i+1)%n]*md - V[i]));
				}
				if (solve(VL)) en = md;
				else st = md;
			}
			ans = min(ans, st);
		}
		cout << ans << endl;
	}
	Bug(sum<=100000);
	Bug(sumM<=300000);
}

