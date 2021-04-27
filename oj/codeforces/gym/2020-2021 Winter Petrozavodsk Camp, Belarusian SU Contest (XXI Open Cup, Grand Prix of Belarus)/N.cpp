// Author : heyuhhh
// Created Time : 2021/02/21 13:13:02
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
const int N = 1e6 + 5;
int lg[N];
void run() {
    lg[2] = 1;
    for (int i = 3; i < N; i++) {
        lg[i] = lg[i >> 1] + 1;
    }
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<vector<int>> f(n, vector<int>(20));
    vector<vector<int>> g(n, vector<int>(20));
    for (int i = 0; i < n; i++) {
        f[i][0] = a[i];
        g[i][0] = i;
    }
    for (int j = 1; j < 20; j++) {
        for (int i = 0; i + (1 << j - 1) < n; i++) {
            int l = f[i][j - 1], r = f[i + (1 << j - 1)][j - 1];
            if (l > r) {
                f[i][j] = l;
                g[i][j] = g[i][j - 1];
            } else {
                f[i][j] = r;
                g[i][j] = g[i + (1 << j - 1)][j - 1];
            }
        }
    }
    
    function<int(int, int)> getmx = [&] (int l, int r) {
        int k = lg[r - l + 1];
        return max(f[l][k], f[r - (1 << k) + 1][k]);
    };
    function<int(int, int)> getpos = [&] (int l, int r) {
        int k = lg[r - l + 1];
        if (f[l][k] > f[r - (1 << k) + 1][k]) {
            return g[l][k];
        }
        return g[r - (1 << k) + 1][k];
    };
    vector<int> ans;
    function<void(int, int, int)> solve = [&] (int l, int r, int C) {
        int mx = getmx(l, r);
        int pos = getpos(l, r);
        // cout << mx << ' ' << pos << '\n';
        if (mx >= C) {
            ans.emplace_back(pos);
            if (pos != l) {
                solve(l, pos - 1, max(C, mx - (pos - l - 1)));
            }
            if (pos != r) {
                solve(pos + 1, r, max(C, mx - (r - pos - 1)));
            }
        }
    };
    solve(0, n - 1, 0);
    sort(all(ans));
    cout << sz(ans) << '\n';
    for (int i = 0; i < sz(ans); i++) {
        if (i) cout << ' ';
        cout << ans[i] + 1;
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