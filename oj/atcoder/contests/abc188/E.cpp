// Author : heyuhhh
// Created Time : 2021/01/10 20:30:09
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
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<vector<int>> G(n), rG(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        G[u].emplace_back(v);
        rG[v].emplace_back(u);
    }
    vector<int> buy(n, INF), sell(n);
    for (int i = 0; i < n; i++) {
        buy[i] = min(buy[i], a[i]);
        for (auto j : G[i]) {
            buy[j] = min(buy[j], buy[i]);
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        sell[i] = max(sell[i], a[i]);
        for (auto j : rG[i]) {
            sell[j] = max(sell[j], sell[i]);
        }
    }
    int ans = -2e9;
    for (int i = 0; i < n; i++) {
        for (auto j : G[i]) {
            ans = max(ans, sell[j] - buy[i]);
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
    run();
    return 0;
}