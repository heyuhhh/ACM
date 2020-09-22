// Author : heyuhhh
// Created Time : 2020/09/16 10:40:15
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
    vector<int> l(n), r(n);
    vector<int> b;
    for (int i = 0; i < n; i++) {
        cin >> l[i] >> r[i];
        b.emplace_back(l[i]);
        b.emplace_back(r[i]);
    }
    
    sort(all(b));
    b.erase(unique(all(b)), b.end());
    int L = 0, R = sz(b);

    vector<vector<int>> v(R);
    for (int i = 0; i < n; i++) {
        l[i] = lower_bound(all(b), l[i]) - b.begin();
        r[i] = lower_bound(all(b), r[i]) - b.begin();   
        v[l[i]].emplace_back(r[i]);
    }

    for (int i = 0; i < R; i++) {
        sort(all(v[i]));
    }

    vector<vector<int>> dp(R, vector<int>(R, -1));
    function<int(int, int)> solve = [&] (int l, int r) {
        if (l > r) return 0;
        if (dp[l][r] != -1) return dp[l][r];
        dp[l][r] = 0;
        int res = 0;
        for (int i = 0; i < sz(v[l]); i++) {
            if (v[l][i] > r) break;
            if (v[l][i] == r) ++dp[l][r];
            else {
                res = max(res, solve(l, v[l][i]) + solve(v[l][i] + 1, r));
            }
        }
        dp[l][r] += max({solve(l, r - 1), solve(l + 1, r), res});
        return dp[l][r];
    };

    int ans = solve(0, R - 1);
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