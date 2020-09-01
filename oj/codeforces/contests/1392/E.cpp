// Author : heyuhhh
// Created Time : 2020/08/22 16:42:16
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
    vector<vector<ll>> a(n, vector<ll>(n));
    a[0][0] = 0;
    ll now = 1;
    for (int i = 1, cur = 0; i < 2 * n - 1; i++) {
        for (int j = 0; j <= i; j++) {
            int k = i - j;
            if (j < n && k < n) {
                if (cur) a[j][k] = now;
                else a[j][k] = 0;
                cur ^= 1;
            }
        }
        now <<= 1;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j];
            if (j == n - 1) cout << endl;
            else cout << ' ';
        }
    }
    cout << endl;
    int q;
    cin >> q;
    while (q--) {
        ll k;
        cin >> k;
        vector<pii> path;
        int x = 0, y = 0;
        for (int i = 0; i < 2 * n - 1; i++) {
            path.push_back(MP(x, y));
            int op = ((k >> i) & 1);
            if (x + 1 < n && ((a[x + 1][y] > 0) == (op > 0))) ++x;
            else ++y;
        }
        path.push_back(MP(n - 1, n - 1));
        for (auto& it : path) {
            cout << it.fi + 1 << ' ' << it.se + 1 << endl;
        }
        cout << endl;
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