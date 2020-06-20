/*
 * Author:  heyuhhh
 * Created Time:  2020/6/19 8:34:31
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
const int N = 2e5 + 5;

vector <int> rG[N];
int n, m;

void run() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        rG[i].clear();
    }
    for (int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        rG[v].push_back(u);
    }
    vector <int> path(n + 1, 0);
    vector <int> ans;
    for (int i = 1; i <= n; i++) {
        for (auto j : rG[i]) {
            path[i] = max(path[j] + 1, path[i]);
        }
        if (path[i] == 2) {
            path[i] = -1;
            ans.push_back(i);
        }
    }
    cout << sz(ans) << '\n';
    for (auto it : ans) {
        cout << it << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    int T; cin >> T; while(T--)
    run();
    return 0;
}
