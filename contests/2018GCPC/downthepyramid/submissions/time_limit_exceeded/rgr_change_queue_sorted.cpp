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

	int n;
	cin >> n;

	vector<int> a(n);
	for(int& i : a) {
		cin >> i;
	}

	vector<pair<int,int>> b;
	for(int i = 0; i <= n; i++) {
		int left = i ? a[i-1] : INT_MAX;
		int right = n-i ? a[i] : INT_MAX;
		b.eb(0, min(left, right));
	}

	set<pair<int,int>> todo;
	for(int i = 0; i <= n; i++) {
		todo.emplace(b[i].yy - b[i].xx, i);
	}

	vector<int> has(n+1, INT_MAX);
	while(sz(todo)) {
		auto it = todo.begin();
		int diff = it->xx, i = it->yy;
		todo.erase(it);
		has[i] = INT_MAX;

		if(diff < 0) {
			cout << 0 << endl;
			exit(0);
		}

		if(i) {
			bool x = b[i-1].xx < a[i-1] - b[i].yy;
			bool y = b[i-1].yy > a[i-1] - b[i].xx;
			if(x || y) {
				todo.erase({has[i-1], i-1});
				if(x) {
					b[i-1].xx = a[i-1] - b[i].yy;
				}
				if(y) {
					b[i-1].yy = a[i-1] - b[i].xx;
				}
				todo.emplace(has[i-1] = b[i-1].yy - b[i-1].xx, i-1);
			}
		}

		if(n-i) {
			bool x = b[i+1].xx < a[i] - b[i].yy;
			bool y = b[i+1].yy > a[i] - b[i].xx;
			if(x || y) {
				todo.erase({has[i+1], i+1});
				if(x) {
					b[i+1].xx = a[i] - b[i].yy;
				}
				if(y) {
					b[i+1].yy = a[i] - b[i].xx;
				}
				todo.emplace(has[i+1] = b[i+1].yy - b[i+1].xx, i+1);
			}
		}
	}

	cout << b[0].yy - b[0].xx + 1 << endl;
}
