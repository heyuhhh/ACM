/*
 * Author:  heyuhhh
 * Created Time:  2020/6/16 9:21:10
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
const int N = 1e5 + 5;

int n;
vector <int> G[N];
int in[N], out[N];
int least[N], most[N];
int sz[N];

void dfs0(int u, int fa) {
    sz[u] = 1;
    for (auto v : G[u]) if (v != fa) {
        dfs0(v, u);
        sz[u] += sz[v];
    }
}

void dfs(int u, int fa) {
    int all1 = 0, all2 = 0;
    for (auto v : G[u]) if (v != fa) {
        dfs(v, u);
        all1 += least[v];
        all2 += most[v];
    }
    least[u] = max(least[u], all1);
    most[u] = min(most[u], all2 + (most[u] != 0));
}

bool check(int x) {
    for (int i = 1; i <= n; i++) {
        if (in[i] != -1) {
            least[i] = in[i];
        } else {
            least[i] = 0;
        }
        if (out[i] != -1) {
            most[i] = x - out[i];
        } else {
            most[i] = sz[i];
        }
        most[i] = min(most[i], sz[i]);
    }
    dfs(1, 0);
    for (int i = 1; i <= n; i++) {
        most[i] = min(most[i], sz[i]);
        if (least[i] > most[i]) {
            return false;
        }
    }
    return least[1] <= x && x <= most[1];
}

void run() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        G[i].clear();
        in[i] = out[i] = -1;
    }
    for (int i = 1; i < n; i++) {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs0(1, 0);
    int A; cin >> A;
    for (int i = 1; i <= A; i++) {
        int x, y; cin >> x >> y;
        in[x] = max(in[x], y);
    }
    int B; cin >> B;
    for (int i = 1; i <= B; i++) {
        int x, y; cin >> x >> y;
        out[x] = max(out[x], y);
    }
    for (int i = 1; i <= n; i++) {
        if (out[i] > n - sz[i] || in[i] > sz[i]) {
            cout << -1 << '\n';
            return;
        }
    }
    int l = 0, r = n + 1, mid;
    while (l < r) {
        mid = (l + r) >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    int ans = (r == n + 1 ? -1 : r);
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    int T; cin >> T; while(T--)
    run();
    return 0;
}
