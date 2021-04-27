// Author : heyuhhh
// Created Time : 2021/02/25 17:34:13
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
    for (int i = 1; i < n; i++) {
        int f;
        cin >> f;
        --f;
        G[f].emplace_back(i);
    }
    vector<vector<int>> nG(1 << n);
    vector<bool> in(1 << n);
    queue<int> que;
    que.emplace(1);
    in[1] = true;
    while (!que.empty()) {
        int u = que.front(); que.pop();
        cout << u << '\n';
        for (int i = 0; i < n; i++) if (u >> i & 1) {
            for (auto v : G[i]) if (!(u >> v & 1)) {
                int nv = (u | (1 << v));
                nG[u].emplace_back(v);
                nG[nv].emplace_back(v);
                if (!in[nv]) {
                    in[nv] = true;
                    que.emplace(nv);    
                }
            }
        }
    }
    
    vector<bool> vis(1 << n);
    int ans = 0;
    function<void(int)> dfs = [&] (int u) {
        vis[u] = true;
        for (auto v : nG[u]) {
            int nv = (u | (1 << v));
            if (!vis[nv]) {
                ++ans;
                dfs(nv);
            }
        }
    };
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