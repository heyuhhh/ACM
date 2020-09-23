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

ll find_border_bottom(vl &numbers, ll bottom, ll top) {
  while(top - bottom > 1) {
    ll mid = (bottom + top) / 2;
    if(!check_solution(numbers, mid))
      bottom = mid;
    else
      top = mid;
  }

  return top;
}

ll find_border_top(vl &numbers, ll bottom, ll top) {
  while(top - bottom > 1) {
    ll mid = (bottom + top) / 2;
    if(check_solution(numbers, mid))
      bottom = mid;
    else
      top = mid;
  }

  return top;
}

ll find_poss(vl &numbers, ll bottom, ll top) {
  ll counter = 0, counter_stop = 10000;
  queue<pll> q;
  q.push({bottom, top});
  while(!q.empty()) {
    tie(bottom, top) = q.front();
    q.pop();
    ll mid = (bottom + top) / 2;
    if(check_solution(numbers, mid)) return mid;
  
    if(counter++ >= counter_stop) return -1;

    if(mid > bottom && mid != top)
      q.push({bottom, mid});
    if(mid + 1 < top)
      q.push({mid, top});

  }
  return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
  ll n;
  cin >> n;
  vl numbers(n);
  FOR(i,0,n) cin >> numbers[i];
  ll solutions = 0;
  ll bottom = -1, mid, top = numbers[0] + 1;
  mid = find_poss(numbers, bottom, top);
  if(mid == -1) {
    cout << 0 << endl;
    return 0;
  }


  bottom = find_border_bottom(numbers, bottom, mid);
  top = find_border_top(numbers, mid, top);
  cout << top - bottom << endl;
	return 0;
}
