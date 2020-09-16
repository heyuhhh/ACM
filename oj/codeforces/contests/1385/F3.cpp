// Author : heyuhhh
// Created Time : 2020/09/14 15:23:53
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
    int n, k;
    cin >> n >> k;
    vector<vector<int>> G(n);
    vector<int> d(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        ++d[u], ++d[v];
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    if (k == 1) {
        cout << n - 1 << '\n';
        return;
    }
    queue<int> q;
    vector<int> in(n);
    vector<int> leaf(n);
    for (int i = 0; i < n; i++) {
        if (d[i] == 1) {
            ++leaf[G[i][0]];
            d[i] = 0;
        }
    }
    for (int i = 0; i < n; i++) {
        if (leaf[i] >= k) {
            q.push(i);
            in[i] = 1;
        }
    }
    int ans = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        in[u] = 0;
        ++ans;
        leaf[u] -= k;
        d[u] -= k;
        if (leaf[u] >= k) {
            q.push(u);
            in[u] = 1;
        }
        if (d[u] == 1) {
            d[u] = 0;
            for (auto& v : G[u]) if (d[v]) {
                ++leaf[v];
                if (leaf[v] >= k && !in[v]) {
                    q.push(v);
                    in[v] = 1;
                }
            }
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