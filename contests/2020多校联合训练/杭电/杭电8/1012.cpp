// Author : heyuhhh
// Created Time : 2020/08/14 09:40:35
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
const int N = 4000 + 5;

int n;
int l[N], r[N];
vector<int> D;
vector<int> G[N];
int zero;
int find(int x) {
    return lower_bound(all(D), x) - D.begin();
}

int dp[N][N], Min[N];
int ans;

void dfs(int u, int fa) {
    int sum = 0;
    for (auto v : G[u]) if (v != fa) {
        dfs(v, u);
        sum += Min[v];
    }
    for (int i = l[u]; i <= r[u]; i++) {
        dp[u][i] = sum + 1;
        for (auto v : G[u]) if (v != fa) {
            if (Min[v] == dp[v][i]) --dp[u][i];
        }
        Min[u] = min(Min[u], dp[u][i]);
    }
}

void run() {
    cin >> n;
    D.clear();
    for (int i = 0; i < n; i++) {
        G[i].clear();
    }
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    D.push_back(0);
    for (int i = 0; i < n; i++) {
        cin >> l[i] >> r[i];
        D.push_back(l[i]);
        D.push_back(r[i]);
    }
    sort(all(D));
    D.erase(unique(all(D)), D.end());
    for (int i = 0; i < n; i++) {
        l[i] = find(l[i]);
        r[i] = find(r[i]);
    }
    zero = find(0);
    for (int i = 0; i < n; i++) {
        Min[i] = INF;
    }
    memset(dp, INF, sizeof(dp));
    dfs(0, -1);
    int ans = dp[0][zero] - 1;
    for (int i = l[0]; i <= r[0]; i++) {
        if (D[i] != 0) {
            ans = min(ans, dp[0][i]);
        }
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