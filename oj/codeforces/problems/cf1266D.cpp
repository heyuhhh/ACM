/*
 * Author:  heyuhhh
 * Created Time:  2020/3/7 15:04:42
 */
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <iomanip>
#include <assert.h>
#define MP make_pair
#define fi first
#define se second
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define INF 0x3f3f3f3f
#define Local
#ifdef Local
  #define dbg(args...) do { cout << #args << " -> "; err(args); } while (0)
  void err() { std::cout << '\n'; }
  template<typename T, typename...Args>
  void err(T a, Args...args) { std::cout << a << ' '; err(args...); }
  template <template<typename...> class T, typename t, typename... A> 
  void err(const T <t> &arg, const A&... args) {
  for (auto &v : arg) std::cout << v << ' '; err(args...); }
#else
  #define dbg(...)
#endif
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
//head
const int N = 1e5 + 5, M = 3e5 + 5;

int n, m;
ll d[N];
vector <int> pos, neg;

void run() {
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int u, v, w; cin >> u >> v >> w;   
        d[u] += w, d[v] -= w;
    }
    for(int i = 1; i <= n; i++) {
        if(d[i] > 0) pos.push_back(i);
        if(d[i] < 0) neg.push_back(i);
    }
    vector <pair<pii, ll>> ans;
    while(!pos.empty()) {
        int i = pos.back(), j = neg.back();
        pos.pop_back(), neg.pop_back();
        ll t = min(d[i], -d[j]);
        d[i] -= t, d[j] += t;
        if(d[i] > 0) pos.push_back(i);
        if(d[j] < 0) neg.push_back(j);
        ans.push_back(MP(MP(i, j), t));
    }
    cout << sz(ans) << '\n';
    for(auto it : ans) {
        cout << it.fi.fi << ' ' << it.fi.se << ' ' << it.se << '\n';   
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
