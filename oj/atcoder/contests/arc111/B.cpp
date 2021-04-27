// Author : heyuhhh
// Created Time : 2021/01/10 16:30:05
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
const int N = 400000;
void run() {
    int n;
    cin >> n;
    vector<vector<int>> G(N + n);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        a += n, b += n;
        G[i].emplace_back(a);
        G[i].emplace_back(b);
        G[a].emplace_back(i);
        G[b].emplace_back(i);
    }
    vector<bool> vis(N + n);
    int L = 0, R = 0;
    function<void(int, int)> dfs = [&] (int u, int dep) {
        vis[u] = true;
        if (dep) ++R;
        else ++L;
        for (auto v : G[u]) if (!vis[v]) {
            dfs(v, dep ^ 1);
        }
    };
    int ans = 0;
    for (int i = 0; i < n; i++) if (!vis[i]) {
        dfs(i, 0);
        ans += min(L, R);
        L = R = 0;
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
    run();
    return 0;
}