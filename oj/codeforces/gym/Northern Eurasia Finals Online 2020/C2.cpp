// Author : heyuhhh
// Created Time : 2021/02/27 11:26:12
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
    vector<vector<int>> ans(n);
    function<void(int)> solve = [&] (int u) {
        for (auto v : G[u]) {
            solve(v);
        }
        sort(all(G[u]), [&] (int A, int B) {
            return sz(ans[A]) < sz(ans[B]);
        });
        for (auto v : G[u]) {
            if (ans[u].empty()) {
                ans[u] = ans[v];
            } else {
                vector<int> tmp = ans[u];
                for (auto e : ans[v]) {
                    ans[u].emplace_back(e);
                    reverse(all(tmp));
                    ans[u].insert(ans[u].end(), all(tmp));
                }
            }
        }
        if (u != 0) ans[u].insert(ans[u].begin(), u);
    };
    solve(0);
    cout << sz(ans[0]) << '\n';
    for (int i = 0; i < sz(ans[0]); i++) {
        if (i) cout << ' ';
        cout << ans[0][i] + 1;
    }
    cout << '\n';
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