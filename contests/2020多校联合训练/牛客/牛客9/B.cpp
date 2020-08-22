// Author : heyuhhh
// Created Time : 2020/08/08 23:09:47
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
//head
const int N = 1e5 + 5;

int n;
int a[N];
vector<pii> G[N];

pair<ll, ll> dfs(int u, int fa, ll w) {
    ll res = a[u], need = w;
    vector<pair<ll, ll>> vec;
    for (auto it : G[u]) {
        int v = it.fi, w = it.se;
        if (v != fa) {
            vec.push_back(dfs(v, u, w));
        }
    }
    sort(all(vec), [&](pair<ll, ll> A, pair<ll, ll> B) {
        int x = (A.se < A.fi);
        int y = (B.se < B.fi);
        if (x != y) return (x == 1);
        if (x == 1) return A.se < B.se;
        return A.fi > B.fi;
    });
    for (auto it : vec) {
        ll x = it.fi, y = it.se;// x:能留下来的，y:需要消耗的
        if (res >= y) {
            res -= y;
            res += x;
        } else {
            need += y - res;
            res = x;
        }
    }
    if (res >= w) {
        res -= w;
    } else {
        need += w - res;
        res = 0;
    }
    return MP(res, need);
}

void run() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        G[i].clear();
    }
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        G[u].push_back(MP(v, w));
        G[v].push_back(MP(u, w));
    }
    pair<ll, ll> rt = dfs(1, 0, 0);
    cout << rt.se << '\n';
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