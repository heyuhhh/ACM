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

	ll h, w;
	cin >> h >> w;

	vvl clues(h+2, vl(w+2));
	FOR(i,0,h+2) {
		FOR(j,0,w+2) {
			cin >> clues[i][j];
		}
	}

	vector<vb> mines(h, vb(w));
	FOR(i,0,h) {
		FOR(j,0,w) {
			if(clues[i][j]) {
				mines[i][j] = true;
				FOR(ii,0,3) {
					FOR(jj,0,3) {
						clues[i+ii][j+jj]--;
					}
				}
			}
		}
	}

	FOR(i,0,h+2) {
		FOR(j,0,w+2) {
			if(clues[i][j]) {
				cout << "impossible" << endl;
				return 0;
			}
		}
	}
	FOR(i,0,h) {
		FOR(j,0,w) {
			cout << (mines[i][j] ? 'X' : '.');
		}
		cout << endl;
	}
}
