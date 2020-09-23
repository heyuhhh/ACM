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

	vl a(n);
	for(ll& a_i : a) {
		cin >> a_i;
	}

	vl s = {0};
	FOR(i,0,n) {
		s.pb(a[i] - s[i]);
	}

	ll k_min = s[0];
	for(ll i = 2; i < sz(s); i += 2) {
		k_min = min(k_min, s[i]);
	}

	ll k_max = s[1];
	for(ll i = 3; i < sz(s); i += 2) {
		k_max = min(k_max, s[i]);
	}

	cout << max(0ll, k_max+k_min+1) << endl;
}
