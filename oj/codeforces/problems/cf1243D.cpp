/*
 * Author:  heyuhhh
 * Created Time:  2020/3/5 16:55:05
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
const int N = 1e5 + 5;

int n, m;
map <int, bool> mp[N];
set <int> s;
queue <int> q;

void run() {
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        mp[u][v] = mp[v][u] = true;
    }
    for(int i = 1; i <= n; i++) s.insert(i);
    int t = 0;
    while(!s.empty()) {
        auto tmp = s.begin();
        q.push(*tmp);
        s.erase(tmp);
        ++t;
        while(!q.empty()) {
            int u = q.front(); q.pop();
            for(auto it = s.begin(), nxt = it; it != s.end(); it = nxt) {
                int v = *it;
                ++nxt;
                if(mp[u].find(v) == mp[u].end()) {
                    q.push(v);
                    s.erase(it);   
                }
            }           
        }
    }
    cout << t - 1 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
