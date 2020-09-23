#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using vl = vector<ll>;
using pll = pair<ll,ll>;

#define sz(c) ll((c).size())
#define all(c) (c).begin(), (c).end()
#define pb push_back
#define xx first
#define yy second

#define FOR(i,a,b) for(ll i = (a); i < (b); i++)

#define TR(X) ({ if(1) cerr << "DBG: " << (#X) << " = " << (X) << endl; })

const bool DEBUG = false;

const ll N = 500;
const ll Q = 100000;

ll parent[N*N];
ll findheight[N*N];

ll height[N*N];
ll res[Q];
set<ll> mountaineers[N*N];
inline ll linearize(ll x, ll y){ return x*N+y; }

ll currentHeight = 0;

void merge(set<ll>& from, set<ll>& to){
	for(auto& m : from){
		if(DEBUG){cerr << "From: " << m << endl;}
		if(to.count(m)){
			if(DEBUG){cerr << "found!" << endl;}
			to.erase(m);
			res[m] = currentHeight;
		} else {
			if(DEBUG){cerr << "not found" << endl;}
			to.insert(m);
		}
	}
	from.clear();
}


// Find; Repräsentant des Teilbaums eines Elementes finden
ll Find(ll x) {
  if (x != parent[x]){
	  ll par = Find(parent[x]);
	  parent[x] = par;
	  //cerr << "moving from " << x << " to " << par << "(" << sz(mountaineers[x]) << ")"<< endl;
	  merge(mountaineers[x], mountaineers[par]);
  }
  return parent[x];
}

// Union; zwei Teilbäume verschmelzen
// Rückgabe: true, falls Verschmelzung stattgefunden
bool Union(ll xt, ll yt) {
  ll x = Find(xt); ll y = Find(yt);
  if (x == y) return false;
  if (findheight[x] > findheight[y]) {
    parent[y] = x;
	merge(mountaineers[y], mountaineers[x]);

  } else {
    parent[x] = y;
	merge(mountaineers[x], mountaineers[y]);
    if (findheight[x] == findheight[y]) findheight[y]++;
  }
  return true;
}


int main(){
	ios_base::sync_with_stdio(false);

	ll m, n, nu;
	cin >> m >> n >> nu;
	iota(parent, parent+N*N, 0);

	FOR(i, 0, m) FOR(j, 0, n) cin >> height[linearize(i, j)];


	FOR(i, 0, nu){
		ll xs, ys, xe, ye;
		cin >> xs >> ys >> xe >> ye;
		xs--; ys--; xe--; ye--;
		if(xs == xe && ys == ye){
			res[i] = height[linearize(xs, ys)];
		} else {
			mountaineers[linearize(xs, ys)].insert(i);
			mountaineers[linearize(xe, ye)].insert(i);
		}
	}

	//Do the magic
	set<pair<ll, pair<ll,ll>>> q;
	FOR(i, 0, m) FOR(j, 0, n) q.insert(make_pair(height[linearize(i, j)], make_pair(i, j)));

	vector<pll> dd = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

	for(auto act : q){
		ll h = act.xx, x = act.yy.xx, y = act.yy.yy;

		currentHeight = h;
		for(pll& d : dd){
			ll nx = x + d.xx;
			ll ny = y + d.yy;

			if(nx <0 || ny < 0 || nx >= m || ny >= n) continue;
			if(height[linearize(nx, ny)] > h) continue;
			if(DEBUG){
			cerr << "(" << x << ", " << y << ") -";
			cerr << "(" << nx << ", " << ny << ")" << endl;
			}
			Union(linearize(nx, ny), linearize(x, y));
		}
	}

	FOR(i, 0, nu){
		cout << res[i] << endl;
	}

}
