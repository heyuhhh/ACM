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


int main(){
	ll b; cin >> b;
	FOR(d,3,70){
		ll rb = b;
		int l = 0;
		while (rb > 0) {
			l++;
			ll r = 1;
			FOR(i,0,d-1) r *= l;
			rb -=  r;
		}
		if (rb == 0) { cout << d << " " << l << endl; return 0;}
	}

	cout << "impossible" << endl;
}
