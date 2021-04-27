// Author : heyuhhh
// Created Time : 2020/11/15 20:06:08
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
    int n, k;
    cin >> n >> k;
    vector<vector<int>> w(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> w[i][j];
        }
    }
    int ans = 0;
    function<void(int, int, int)> dfs = [&] (int s, int at, int tot) {
        if (s == (1 << n) - 1) {
            if (tot + w[at][0] == k) ++ans;
            return;
        }
        for (int i = 0; i < n; i++) if (!(s >> i & 1)) {
            dfs(s | (1 << i), i, tot + w[i][at]);
        }
    };
    dfs(1, 0, 0);
    cout << ans << '\n';
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