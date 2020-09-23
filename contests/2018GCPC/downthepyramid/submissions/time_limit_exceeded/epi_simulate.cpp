#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vl = vector<ll>;
using vvl = vector<vl>;
using pll = pair<ll,ll>;
using vb = vector<bool>;
const ll oo = 0x3f3f3f3f3f3f3f3fLL;
#define sz(c) ll((c).size())
#define all(c) begin(c),end(c)
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define xx first
#define yy second
#define has(c,i) ((c).find(i) != end(c))
#define FOR(i,a,b) for(ll i = (a); i < (b); i++)
#define FORD(i,a,b) for(ll i = ll(b) - 1; i >= (a); i--)
#define DBG(x) ({if(1) cerr << "DBG: " << (#x) << " = " << (x) << endl; })

bool check_solution(vl &numbers, ll start_num) {
  FOR(i,0,sz(numbers)) {
    start_num = numbers[i] - start_num;
    if(start_num < 0) return false;
  }
  return true;
}


int main() {
	ios_base::sync_with_stdio(false);
  ll n;
  cin >> n;
  vl numbers(n);
  FOR(i,0,n) cin >> numbers[i];
  ll solutions = 0;
  FOR(i,0,numbers[0] + 1) {
    if(check_solution(numbers, i)) solutions++;
  }
  cout << solutions << endl;
	return 0;
}
