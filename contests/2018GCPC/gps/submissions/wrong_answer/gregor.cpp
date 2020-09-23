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

const double earthR = 6371; // earth radius in kilometre

struct pt{
	double x,y,z;
	pt():x(0),y(0),z(0){};
	//pt(double _x,double _y,double _z):x(_x),y(_y),z(_z){};
	pt(double lat,double lon, double r){
		double phi = -1*(lat - 90) / 180 * PI;
		double theta = lon / 180 * PI;
		x = double(r) * sin(phi) * cos(theta);
		y = double(r) * sin(phi) * sin(theta);
		z = double(r) * cos(phi);
	};

	pt operator+(const pt& p) { pt r; r.x = x+p.x; r.y = y+p.y; r.z = z+p.z; return r; }
	pt operator-(const pt& p) { pt r; r.x = x-p.x; r.y = y-p.y; r.z = z-p.z; return r; }
	pt operator*(const double f) { pt r; r.x = x*f; r.y = y*f; r.z = z*f; return r; }
	pt operator/(const double f) { pt r; r.x = x/f; r.y = y/f; r.z = z/f; return r; }
	double operator*(const pt& p) { return x*p.x+y*p.y+z*p.z; }


	pt rotateYZ(double a){
		a /= 180 / PI;
	    pt r;
		r.x = x;
		r.y = y*cos(a) - z*sin(a);
		r.z = y*sin(a) + z*cos(a);
		return r;
	};

	pt rotateXY(double a){
		a /= 180 / PI;
	    pt r;
		r.x = x*cos(a) - y*sin(a);
		r.y = x*sin(a) + y*cos(a);
		r.z = z;
		return r;
	};
};

double len(pt p) { return sqrt(p*p); }
double dist(pt a, pt b){ return len(a-b); }

pt closestpt(pt a0, pt a1) {
	if ((a1 - a0) * (a1*-1) > 0) return a1;                                                                                                                                                         
    if ((a0 - a1) * (a0*-1) > 0) return a0;
	pt d=a1-a0;
	return a0+(d*(d*(a0*-1))/(d*d));
}


int main(){
	int s;
	cin >> s;
	// coordinates of observer
	double lon,lat; cin >> lon >> lat;
	pt obs(lat,lon, earthR);


	while (s --> 0){
		// satellite
		double satLon, satIncl, satR, cover, v; cin >> satLon >> satIncl >> satR >> cover;
		double coverLon = cover*360; if (coverLon > 180) coverLon -= 360;
		pt planarToLon (0,coverLon,satR);
		pt rotatedToIncl = planarToLon.rotateYZ(satIncl);
		pt rotatedToLon = rotatedToIncl.rotateXY(satLon);
		
		// check whether the straight line between rotatedToLon and obs
		double distToCenter = len(closestpt(obs,rotatedToLon));
		
		if (distToCenter < earthR) cout << "no signal" << endl; else cout << fixed << setprecision(20) << dist(obs,rotatedToLon) / 299792458 * 1000 << endl; 
	}
}
