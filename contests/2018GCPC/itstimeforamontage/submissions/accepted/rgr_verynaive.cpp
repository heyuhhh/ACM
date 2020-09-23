#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using vl = vector<ll>;
using vvl = vector<vl>;
using pll = pair<ll,ll>;
using vpll = vector<pll>;
using vb = vector<bool>;
using vs = vector<string>;
const ll oo = 0x3f3f3f3f3f3f3f3fLL;
const ld eps = 1e-9;
#define sz(c) ll((c).size())
#define all(c) begin(c),end(c)
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define xx first
#define yy second
#define FOR(i,a,b) for(ll i = (a); i < (b); i++)
#define FORD(i,a,b) for(ll i = ll(b)-1; i >= (a); i--)
#define TR(X) ({ if(1) cerr << "TR: " << (#X) << " = " << (X) << endl; })

int main() {
	cin.sync_with_stdio(0);

	ll n;
	cin >> n;

	vl h(n);
	for(ll& h_i : h) {
		cin >> h_i;
	}

	vl v(n);
	for(ll& v_i : v) {
		cin >> v_i;
	}

	ll res = 0;
	do {
		int works = 0;
		FOR(i,0,n) {
			ll diff = h[i] + res - v[i];
			if(diff > 0 && !works) {
				works = 1;
			} else if(diff < 0 && !works) {
				works = -1;
			}
		}
		if(works >= 0) {
			cout << res << endl;
			exit(0);
		}
	} while(++res);
}
