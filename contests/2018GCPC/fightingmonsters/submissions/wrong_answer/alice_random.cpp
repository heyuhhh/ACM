#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld =long double;

using vl = vector<ll>;
using vvl = vector<vl>;

using pll = pair<ll,ll>;

const ll oo = 0x3f3f3f3f3f3f3f3fLL;
const ld eps = 1e-9;

#define sz(c) ll((c).size())
#define all(c) (c).begin(), (c).end()
#define pb push_back
#define xx first
#define yy second

#define FOR(i,a,b) for(ll i = (a); i < (b); i++)
#define FORD(i,a,b) for(ll i = (b)-1; i >= a; i--)

#define TR(X) ({ if(0) cerr << "DBG: " << (#X) << " = " << (X) << endl; })

bool simulate(int a, int b){
	while(a > 0 && b > 0){
		TR(a);
		TR(b);
		int c = a - b;
		a = b;
		b = c;
	}
	return (a == 1 || b == 1);
}

int main(){
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;
	vector<ll> mons(N);

	for(auto& i : mons) cin >> i;

	std::random_device rd;
	std::mt19937 eng(rd());
	std::uniform_int_distribution<> distr(0, N-1);

	FOR(i, 0, 50000000){
		int a = distr(eng);
		int b = distr(eng);
		if(a == b) continue;

		if(simulate(mons[a], mons[b])){
			cout << b+1 << " " << a+1 << endl;
			return 0;
		}
	}

	cout << "impossible" << endl;

}
