// Author : heyuhhh
// Created Time : 2020/09/10 10:37:45
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
struct node{
    int u, t;
    bool operator < (const node& A) const {
        return t > A.t;
    }
};
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
        G[u].push_back(v);
        G[v].push_back(u);
    }
    if (k == 1) {
        cout << n - 1 << '\n';
        return;
    }
    int rt = 0;
    // for (int i = 0; i < n; i++)
    //     if (d[i] > 1) 
    //         rt = i;
    vector<int> sons(n), up(n);
    function<void(int, int)> dfs = [&] (int u, int fa) {
        up[u] = fa;
        for (auto v : G[u]) if (v != fa) {
            dfs(v, u);
            ++sons[u];
        }
    };
    dfs(rt, -1);
    priority_queue<node> que;
    for (int i = 0; i < n; i++)
        if (d[i] == 1 && up[i] != -1)
            que.push(node{i, sons[up[i]]});
    int ans;
    for (ans = 0;; ++ans) {
        int now = k;
        while (!que.empty() && now--) {
            node cur = que.top(); que.pop();
            int u = cur.u, t = cur.t;
            int fa = up[u];
            if (fa == rt) continue;
            if (fa != -1 && --d[fa] <= 1) {
                int ffa = up[fa];
                if (ffa != -1) {
                    que.push(node{fa, sons[ffa]});
                } else {
                    que.push(node{fa, 0});
                }
            }
        }
        if (now > 0)
            break;
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