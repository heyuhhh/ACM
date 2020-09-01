// Author : heyuhhh
// Created Time : 2020/07/18 09:47:55
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
    string s; 
    cin >> s;
    vector<vector<int>> sum(n, vector<int>(26));
    sum[0][s[0] - 'a'] = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 26; j++) {
            sum[i][j] = sum[i - 1][j];
        }
        ++sum[i][s[i] - 'a'];
    }

    auto calc = [&] (int l, int r, int d) {
        return r - l + 1 - sum[r][d] + (l > 0 ? sum[l - 1][d] : 0);
    };

    function<int(int, int, int)> dfs;
    dfs = [&] (int l, int r, int d) {
        if (l == r) {
            if (s[l] - 'a' != d) {
                return 1;
            }
            return 0;
        }
        int mid = (l + r) >> 1;
        int ans1 = dfs(l, mid, d + 1) + calc(mid + 1, r, d);
        int ans2 = dfs(mid + 1, r, d + 1) + calc(l, mid, d);
        return min(ans1, ans2);
    };
    int ans = dfs(0, n - 1, 0);
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