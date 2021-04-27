// Author : heyuhhh
// Created Time : 2020/11/15 21:02:05
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
    int n, q;
    cin >> n >> q;
    vector<int> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
        --c[i];
    }
    vector<vector<int>> V(n);
    vector<map<int, int>> mp(n);
    for (int i = 0; i < n; i++) {
        V[i].emplace_back(i);
        mp[i][c[i]] = 1;
    }
    vector<int> f(n);
    iota(all(f), 0);
    auto find = [&] (int x) {
        int t = x;
        while (t != f[t]) t = f[t];
        while (x != f[x]) {
            int tmp = f[f[x]];
            f[x] = t;
            x = tmp;
        }
        return t;
    };
    while (q--) {
        int op;
        cin >> op;
        if (op == 1) {
            int a, b;
            cin >> a >> b;
            --a, --b;
            if (find(a) != find(b)) {
                a = find(a), b = find(b);
                if (sz(V[a]) < sz(V[b])) swap(a, b);
                for (auto it : V[b]) {
                    V[a].emplace_back(it);
                    ++mp[a][c[it]];
                }
                f[b] = a;
            }
        } else {
            int x, y;
            cin >> x >> y;
            --x, --y;
            x = find(x);
            if (mp[x].find(y) == mp[x].end()) cout << 0 << '\n';
            else cout << mp[x][y] << '\n';
        }
    }
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