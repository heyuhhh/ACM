/*
 * Author:  heyuhhh
 * Created Time:  2020/6/18 19:30:23
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
const int N = 2e6 + 5;

int v[N], prime[N];
int num;
void init() {
    for(int i = 2; i < N; i++) {
        if(v[i] == 0) {
            v[i] = i;
            prime[++num] = i;
        }
        for(int j = 1; j <= num && prime[j] * i < N; j++) {
            v[prime[j] * i] = prime[j] ;
        }
    }
} 

int n, k;
int a[N];
int Match[N];

struct MaxMatch {
    int n;
    vector<int> G[N];
    int vis[N], left[N], clk;

    void init(int n) {
        this->n = n;
        for (int i = 1; i <= n; i++) G[i].clear();
        fill(vis + 1, vis + n + 1, -1);
    }
    
    void adde(int u, int v) {
        G[u].push_back(v);
        G[v].push_back(u);
    }
    
    bool dfs(int u) {
        for (int v: G[u])
            if (vis[v] != clk) {
                vis[v] = clk;
                if (Match[v] == -1 || dfs(Match[v])) {
                    Match[u] = v;
                    Match[v] = u;
                    return true;
                }
            }
        return false;
    }

    int solve() {
        int res = 0;
        for (int i = 1; i <= n; i++) {
            if ((a[i] & 1) && a[i] > 1) {
                ++clk;
                res += dfs(i);
            }
        }
        for (int i = 1; i <= n; i++) {
            if (a[i] == 1) {
                ++clk;
                res += dfs(i);
            }
        }
        int x = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i] == 1 && Match[i] < 0) {
                ++x;
                Match[i] = 0;
            }
        }
        return res + x / 2;
    }
    
} MM;

void run() {
    cin >> n >> k;
    MM.init(n);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        Match[i] = -2;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (v[a[i] + a[j]] == a[i] + a[j]) {
                Match[i] = Match[j] = -1;
                if (a[i] == 1 && a[j] == 1) continue;
                MM.adde(i, j);
            }
        }
    }
    int t = MM.solve();
    if (t < k) {
        int noMat = 0;
        for (int i = 1; i <= n; i++) {
            if (Match[i] == -2) {
                ++noMat;
            }
        }
        int r = n - 2 * t - noMat;
        cout << 2 * t + min(r, k - t) << '\n';
    } else {
        cout << 2 * k << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    init();
    int T; cin >> T; while(T--)
    run();
    return 0;
}
