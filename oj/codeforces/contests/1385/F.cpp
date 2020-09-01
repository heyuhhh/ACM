// Author : heyuhhh
// Created Time : 2020/07/18 10:35:29
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
    int n, k; cin >> n >> k;
    vector<int> d(n);
    vector<vector<int>> G(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        --u, -- v;
        G[u].push_back(v);
        G[v].push_back(u);
        ++d[u], ++d[v];
    }
    vector<int> de(n);
    vector<bool> del(n);
    auto gao = [&] (int u) {
        for (auto v : G[u]) {
            if (!del[v]) {
                ++de[v];
            }
        }
        return 0;
    };
    auto calc = [&] (int u) {
        for (auto v : G[u]) {
            if (!del[v]) {
                return MP(de[v], u);
            }
        }
    };
    set<pii> lvs;
    for (int i = 0; i < n; i++) {
        if (d[i] == 1) {
            gao(i);
        }
    }
    for (int i = 0; i < n; i++) {
        if (d[i] == 1) {
            lvs.insert(calc(i));
        }
    }
    int ans = 0;
    while (sz(lvs) >= k) {
        int p = k;
        vector<int> tmp;
        while (p--) {
            auto it = lvs.begin();
            int u = it->se;
            dbg(u + 1);
            for (auto v : G[u]) {
                if (!del[v] && --d[v] == 1) {
                    tmp.push_back(v);
                }
                if (!del[v]) {
                    --de[v];
                }
            }
            del[u] = true;
            lvs.erase(it);
        }
        for (auto i : tmp) {
            lvs.insert(calc(i));
        }
        ++ans;
    }
    cout << ans << '\n';
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