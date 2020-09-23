// Author : heyuhhh
// Created Time : 2020/09/06 09:59:17
#include<bits/stdc++.h>
#define MP make_pair
#define fi first
#define se second
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
void err(int x) {cerr << x;}
void err(long long x) {cerr << x;}
void err(double x) {cerr << x;}
void err(char x) {cerr << '"' << x << '"';}
void err(const string &x) {cerr << '"' << x << '"';}
void _print() {cerr << "]\n";}
template<typename T, typename V>
  void err(const pair<T, V> &x) {cerr << '{'; err(x.first); cerr << ','; err(x.second); cerr << '}';}
template<typename T>
  void err(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), err(i); cerr << "}";}
template <typename T, typename... V>
  void _print(T t, V... v) {err(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifdef Local
#define dbg(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define dbg(x...)
#endif
//head
const int N = 1e5 + 5;
void run() {
    int n, m;
    cin >> n >> m;
    vector<int> p(n);
    for (int i = 0; i < n; i++)
        cin >> p[i];
    vector<int> h(n);
    for (int i = 0; i < n; i++)
        cin >> h[i];
    vector<vector<int>> G(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    vector<int> size(n);
    function<void(int, int)> dfs = [&](int u, int fa) {
        size[u] = p[u];
        for (auto v : G[u]) {
            if (v != fa) {
                dfs(v, u);
                size[u] += size[v];
            }
        }
    };
    dfs(0, 0);
    for (int i = 0; i < n; i++) {
        if ((size[i] + h[i]) % 2) {
            cout << "NO" << '\n';
            return;
        }
    }
    // x + y = size[v], x - y = h[v]
    bool f = false;
    function<void(int, int, int, int)> dfs2 = [&](int u, int fa, int x, int y) {
        if (x < 0 || y < 0) 
            f = true;
        if (f) return;
        assert(x + y == size[u] && x - y == h[u]);
        vector<int> sons;
        for (auto v : G[u]) if (v != fa) {
            sons.push_back(v);
        }
        sort(all(sons), [&](int A, int B) {
            return h[A] < h[B];
        });
        y -= p[u];
        if (y < 0)
            x += y, y = 0;
        for (auto& v : sons) if (!f) {
            int nx = (size[v] + h[v]) / 2;
            int ny = size[v] - nx;
            y -= ny;
            if (y < 0)
                x += y, y = 0;
            x -= nx;
            dfs2(v, u, nx, ny);
        }
        if (x < 0 || y < 0) f = true;
    };
    int x = (h[0] + m) / 2, y = m - x;
    dfs2(0, 0, x, y);
    if (f) {
        cout << "NO" << '\n';
        return;
    }
    cout << "YES" << '\n';
}
int main() {
#ifdef Local
    freopen("input.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    int T; cin >> T; while(T--)
    run();
    return 0;
}