// Author : heyuhhh
// Created Time : 2020/08/18 13:03:39
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
void run() {
    int n;
    cin >> n;
    vector<vector<int>> G(n);
    vector<int> f(n, -1);
    vector<int> size(n);
    ll ans = 0;
    for (int i = 1; i < n; i++) {
        int fa; cin >> fa;
        --fa;
        f[i] = fa;
        G[fa].push_back(i);
    }
    function<void(int)> dfs = [&](int u) {
        size[u] = 1;
        for (auto v : G[u]) {
            dfs(v);
            size[u] += size[v];
        }
        ans += size[u];
    };
    dfs(0);
    ll Max = 0;
    function<void(int, ll)> dfs2 = [&](int u, ll val) {
        Max = max(Max, val);
        for (auto v : G[u]) {
            dfs2(v, val + n - size[v]);
        }
    };
    dfs2(0, 0);
    ans += Max;
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