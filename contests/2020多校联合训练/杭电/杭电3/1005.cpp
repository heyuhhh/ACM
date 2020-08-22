// Author : heyuhhh
// Created Time : 2020/07/28 12:40:16
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
const int N = 1e5 + 5, MOD = 1e9 + 7;

int f[N], sz[N][2];
int block;
int find(int x) {
    return f[x] == x ? f[x] : f[x] = find(f[x]);
}

int cnt[2];
int a[N];

int calc2(int x) {
    return 1ll * x * (x - 1) / 2 % MOD;
}
int calc3(int x = block) {
    if (x < 3) return 0;
    return 1ll * x * (x - 1) * (x - 2) / 6 % MOD;
}

void run() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        f[i] = i;
    }
    cnt[0] = cnt[1] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        --a[i];
        ++cnt[a[i]];
        sz[i][a[i]] = 1;
        sz[i][!a[i]] = 0;
    }
    block = cnt[1];
    int ans = (1ll * calc2(cnt[1]) * cnt[0] % MOD + calc3()) % MOD;
    cout << ans << '\n';
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        int fu = find(u), fv = find(v);
        if (fu == fv) continue;
        int SZ_u_0 = sz[fu][0], SZ_u_1 = sz[fu][1];
        int SZ_v_0 = sz[fv][0], SZ_v_1 = sz[fv][1];
        // dbg(SZ_u_0, SZ_u_1);
        // dbg(SZ_v_0, SZ_v_1);
        ans -= 1ll * SZ_u_1 * SZ_v_1 % MOD * (cnt[0] - SZ_u_0 - SZ_v_0) % MOD;
        ans %= MOD;
        ans -= 1ll * SZ_u_1 * (cnt[1] - SZ_u_1 - SZ_v_1) % MOD * SZ_v_0 % MOD;
        ans %= MOD;
        ans -= 1ll * SZ_v_1 * (cnt[1] - SZ_u_1 - SZ_v_1) % MOD * SZ_u_0 % MOD;
        ans %= MOD;
        ans -= 1ll * SZ_u_1 * SZ_v_1 % MOD * (cnt[1] - SZ_u_1 - SZ_v_1) % MOD;
        ans %= MOD;
        if (ans < 0) ans += MOD;
        cout << ans << '\n';
        f[fu] = fv;
        sz[fv][0] += sz[fu][0];
        sz[fv][1] += sz[fu][1];
    }
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