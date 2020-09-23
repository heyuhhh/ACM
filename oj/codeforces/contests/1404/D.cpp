// Author : heyuhhh
// Created Time : 2020/09/16 18:33:32
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
    if (n % 2 == 0) {
        cout << "First" << '\n';
        for (int i = 0; i < 2 * n; i++) {
            if (i) cout << ' ';
            cout << i % n + 1;
        }
        cout << endl << endl;
        int x;
        cin >> x;
    } else {
        cout << "Second" << endl << endl;
        vector<vector<int>> has(n);
        for (int i = 0; i < 2 * n; i++) {
            int bel;
            cin >> bel;
            --bel;
            has[bel].emplace_back(i);
        }
        vector<vector<int>> G(2 * n);
        for (int i = 0; i < n; i++) {
            G[i].emplace_back(i + n);
            G[i + n].emplace_back(i);
        }
        for (int i = 0; i < n; i++) {
            G[has[i][0]].emplace_back(has[i][1]);
            G[has[i][1]].emplace_back(has[i][0]);
        }
        vector<int> col(2 * n, -1);
        vector<int> zeros, ones;
        int res = 0;
        function<void(int, int)> go = [&] (int u, int c) {
            col[u] = c;
            if (c == 0) {
                res = (res + u + 1) % (2 * n);
                zeros.emplace_back(u);
            } else {
                ones.emplace_back(u);
            }
            for (auto& v : G[u]) {
                assert(col[v] != col[u]);
                if (col[v] == -1) {
                    go(v, c ^ 1);
                }
            }
        };
        for (int i = 0; i < 2 * n; i++) {
            if (col[i] == -1) {
                go(i, 0);
            }
        }
        if (res == 0) {
            for (int i = 0; i < sz(zeros); i++) {
                if (i) cout << ' ';
                cout << zeros[i] + 1;
            }
        } else {
            for (int i = 0; i < sz(ones); i++) {
                if (i) cout << ' ';
                cout << ones[i] + 1;
            }
        }
        cout << endl << endl;
        int x;
        cin >> x;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}