#include <bits/stdc++.h>
using namespace std;

struct point {
	double x, y;
};

tuple<double,double,double> find_tangents(point a, point c, double r) {
	double dist = hypot(a.x-c.x,a.y-c.y);
	double alpha = atan2(a.y-c.y,a.x-c.x);
	double beta = acos(r/dist);
	double tangent_length = sin(beta)*dist;
	return make_tuple(tangent_length,alpha-beta,alpha+beta);
}

int main() {
	point a, b, c;
	double r;
	cin >> a.x >> a.y >> b.x >> b.y;
	cin >> c.x >> c.y >> r;
	cin >> c.x >> c.y >> r;
	
	double p, phi1, phi2, q, psi1, psi2;
	tie(p,phi1,phi2) = find_tangents(a,c,r);
	tie(q,psi1,psi2) = find_tangents(b,c,r);
	
	double res = 1e10;
	for (double phi: {phi1,phi2}) for (double psi: {psi1,psi2}) {
		double gamma = abs(fmod(phi-psi,2*M_PI));
		gamma = min(gamma,2*M_PI-gamma);
		res = min(res, p + gamma*r + q);
	}
	cout << res << endl;
}
