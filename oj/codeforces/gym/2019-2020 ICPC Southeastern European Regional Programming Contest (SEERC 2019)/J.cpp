// Author : heyuhhh
// Created Time : 2020/10/05 15:57:55
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
    int m = n * (n - 1) / 2;
    vector<vector<int>> G(n);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        --u, --v;
        G[u].emplace_back(w);
        G[v].emplace_back(w);
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        sort(all(G[i]));
        for (int j = 1; j < sz(G[i]); j += 2) {
            ans += G[i][j];
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