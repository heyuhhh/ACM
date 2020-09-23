#include <bits/stdc++.h>
using namespace std;

struct point {
	double x, y, z;
	
	point(double lat, double lon) {
		lat *= M_PI/180, lon *= M_PI/180;
		x = cos(lat) * cos(lon);
		y = cos(lat) * sin(lon);
		z = sin(lat);
	}
	point(double x, double y, double z): x(x), y(y), z(z) { }
};

point operator*(double k, point a) { return point(k*a.x, k*a.y, k*a.z); }
point operator+(point a, point b) { return point(a.x+b.x, a.y+b.y, a.z+b.z); }
point operator-(point a, point b) { return point(a.x-b.x, a.y-b.y, a.z-b.z); }
double operator*(point a, point b) { return a.x*b.x + a.y*b.y + a.z*b.z; }
point operator|(point a, point b) { return point(a.y*b.z - a.z*b.y, a.z*b.x - a.x*b.z, a.x*b.y - a.y*b.x); }

point rotate(point p, point n, double alpha) { return cos(alpha) * p + sin(alpha) * (n|p); }

const double earth_radius = 6371, light_speed = 299792.458;

int main() {
	int n; cin >> n;
	
	double lon, lat;
	cin >> lon >> lat;
	point me(lat, lon);

	while (n--) {
		double lon, psi, r, t;
		cin >> lon >> psi >> r >> t;
		
		point sat(0, lon);
		point normal = psi <= 180 ? point(90-psi, lon-90) : point(psi-270, lon+90);
		sat = r/earth_radius * rotate(sat, normal, 2*t*M_PI);
		
		if (sat*me < 1-1e-9) {
			cout << "no signal" << endl;
		} else {
			double dist = sqrt((sat-me)*(sat-me));
			cout << fixed << setprecision(20) << dist*earth_radius/light_speed << endl;
		}
	}
}
