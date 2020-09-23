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


int ggt(int a, int b){ if (!a) return b; return ggt(b % a, a);}
bool ptest(int a){
	for(int i = 2; i < min(a-1,int(sqrt(a))+30); i++)
		if (! (a%i)) return false;
	return true;
}

int main(){
	int tc; cin >> tc;
	while (tc --> 0){
		double da,db; cin >> da >> db;
		int a = da * 100000 + 0.1;
		int b = db * 100000 + 0.1;
		int g = ggt(a,b);
		a /= g;
		b /= g;

		if (a == 1 || b == 1) a*=2,b*=2;

		if (ptest(a) && ptest(b)) cout << a  << " " << b << endl; else cout << "impossible" << endl;
	}	
}
