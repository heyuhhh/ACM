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

	ll maindiff = v[0] - h[0];
	if(maindiff < 0) {
		cout << "0\n";
		return 0;
	}

	FOR(i,0,n) {
		h[i] += maindiff;
		if(h[i] > v[i]) {
			cout << maindiff << endl;
			return 0;
		}
		if(h[i] < v[i]) {
			cout << maindiff+1 << endl;
			return 0;
		}
	}
	cout << maindiff+1 << endl;
}
