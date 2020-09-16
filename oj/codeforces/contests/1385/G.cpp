// Author : heyuhhh
// Created Time : 2020/09/15 20:41:28
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
    vector<vector<int>> a(2, vector<int>(n));
    vector<int> cnt(n);
    for (int j = 0; j < 2; j++) {
        for (int i = 0; i < n; i++) {
            cin >> a[j][i];
            ++cnt[--a[j][i]];
        }
    }
    for (int i = 0; i < n; i++) {
        if (cnt[i] != 2) {
            cout << -1 << '\n';
            return;
        }
    }
    vector<vector<int>> b(2, vector<int>(n, -1));
    for (int j = 0; j < 2; j++) {
        for (int i = 0; i < n; i++) {
            if (b[0][a[j][i]] == -1) {
                b[0][a[j][i]] = 2 * i + j;
            } else {
                b[1][a[j][i]] = 2 * i + j;
            }
        }
    }
    vector<vector<pii>> G(n);
    auto adde = [&] (int u, int v, int w) {
        G[u].emplace_back(v, w);
        G[v].emplace_back(u, w);
    };
    for (int i = 0; i < n; i++) {
        adde(b[0][i] >> 1, b[1][i] >> 1, (b[0][i] & 1) == (b[1][i] & 1));
        adde(b[1][i] >> 1, b[0][i] >> 1, (b[0][i] & 1) == (b[1][i] & 1));
    }
    cnt.resize(2);
    vector<int> col(n, -1);
    bool f = false;
    vector<pair<vector<pii>, int>> alls;
    vector<pii> nodes;
    function<void(int, int)> go = [&] (int u, int c) {
        if (f) return;
        col[u] = c;
        ++cnt[c];
        nodes.emplace_back(u, c);
        for (auto it : G[u]) {
            int v = it.fi, w = it.se;
            if (w) {
                if (col[v] == -1) go(v, c ^ 1);
                else if (col[v] == col[u]) {
                    f = true;
                    return;
                }
            } else {
                if (col[v] == -1) go(v, c);
                else if (col[v] != col[u]) {
                    f = true;
                    return;
                }
            }
        }
    };
    int res = 0;
    for (int i = 0; i < n && !f; i++) {
        if (col[i] == -1) {
            cnt[0] = cnt[1] = 0;
            nodes.clear();
            go(i, 0);
            int op = 0;
            if (cnt[1] < cnt[0]) op = 1;
            res += min(cnt[0], cnt[1]);
            alls.emplace_back(nodes, op);
        }
    }
    if (f) {
        cout << -1 << '\n';
        return;
    }
    cout << res << '\n';
    for (auto& it : alls) {
        auto nodes = it.fi;
        int op = it.se;
        for (auto& it2 : nodes) {
            int u = it2.fi, c = it2.se;
            if (c == op) {
                cout << u + 1 << ' ';
            }
        }
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
    int T; cin >> T; while(T--)
    run();
    return 0;
}