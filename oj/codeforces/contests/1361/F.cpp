/*
 * Author:  heyuhhh
 * Created Time:  2020/6/5 17:05:23
 */
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <iomanip>
#include <assert.h>
#include <functional>
#include <numeric>
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
  void err() { std::cout << std::endl; }
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
const int N = 5e5 + 5;

void run() {
    int n; cin >> n;
    vector <int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    for (int k = 20; k >= 0; k--) {
        int t = 1 << k;
        vector <vector <pii>> G(t + n);
        for (int i = 0; i < n; i++) {
            G[a[i] & (t - 1)].push_back(MP(i + t, 2 * i));
            G[i + t].push_back(MP(a[i] & (t - 1), 2 * i));
            G[b[i] & (t - 1)].push_back(MP(i + t, 2 * i + 1));
            G[i + t].push_back(MP(b[i] & (t - 1), 2 * i + 1));
        }
        bool ok = true;
        for (int i = 0; i < t + n; i++) {
            if (sz(G[i]) & 1) {
                ok = false;
                break;
            }
        }
        if (ok == false) continue;
        
        vector <bool> del(2 * n);
        vector <int> ans;
        function <void(int, int)> dfs = [&] (int u, int from) {
            while (sz(G[u])) {
                auto it = G[u].back(); G[u].pop_back();
                int v = it.fi, id = it.se;
                if (!del[id]) {
                    del[id] = true;
                    dfs(v, id);
                }
            }
            if (from != -1) ans.push_back(from);
        };   
        
        ans.clear();
        for (int i = 0; i < n + t; i++) {
            if (sz(G[i])) {
                dfs(i, -1);
                break;
            }
        }
        if (sz(ans) < 2 * n) {
            continue;
        }
        cout << k << '\n';
        for (auto it : ans) {
            cout << it + 1 << ' ';   
        }
        cout << '\n';
        break;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
