// Author : heyuhhh
// Created Time : 2020/08/03 12:14:49
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
int _;
void run() {
    ++_;
    int n;
    cin >> n;
    map<int, int> mp;
    vector<vector<int>> G(2 * n);
    int tot = 0;
    vector<int> d(2 * n);
    for (int i = 1; i <= n; i++) {
        int u, v;
        cin >> u >> v;
        if (mp.find(u) == mp.end()) {
            mp[u] = tot++;
        }
        if (mp.find(v) == mp.end()) {
            mp[v] = tot++;
        }
        G[mp[u]].push_back(mp[v]);
        G[mp[v]].push_back(mp[u]);
        ++d[mp[u]], ++d[mp[v]];
    }
    vector<bool> vis(tot);
    int sum = 0, cnt = 0;
    function <void(int)> dfs = [&] (int u) {
        vis[u] = true;
        sum += d[u];
        ++cnt;
        for (auto v : G[u]) {
            if (!vis[v]) {
                dfs(v);
            }
        }
    };
    int ans = 0;
    for (int i = 0; i < tot; i++) {
        if (!vis[i]) {
            cnt = sum = 0;
            dfs(i);
            sum /= 2;
            if (sum < cnt) {
                ans += sum;
            } else {
                ans += cnt;
            }
        }
    }
    cout << "Case #" << _ << ": ";
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