// Author : heyuhhh
// Created Time : 2020/09/22 12:39:30
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
const int N = 31;

int A[N], B[N], K[N], W[N];
ll dp[N][2][2][2][2][2];

int trans(int* a, int x) {
    for (int i = N - 1; i >= 0; i--) {
        a[i] = (x >> i & 1);
    }
}

ll dfs(int cur, int ua, int ub, int uk, int uw, int bit) {
    if (cur == -1) {
        return bit == 0;
    }
    ll& res = dp[cur][ua][ub][uk][uw][bit];
    if (res != -1) return res;
    res = 0;
    int a = ua ? A[cur] : 1;
    int b = ub ? B[cur] : 1;
    int k = uk ? K[cur] : 1;
    int w = uw ? W[cur] : 1;
    for (int i = 0; i <= a; i++) {
        for (int j = 0; j <= b; j++) {
            int nb = 2 * bit + i - j;
            int nw = (i ^ j);
            if (nw > w) continue;
            if (nb >= 1 && nb <= 2) {
                if (nb - 1 <= k) res += dfs(cur - 1, ua && (a == i), ub && (b == j), uk && (k == (nb - 1)), uw && (w == nw), 1);
            }
            if (nb >= 0 && nb <= 1) {
                if (nb <= k) res += dfs(cur - 1, ua && (a == i), ub && (b == j), uk && (k == nb), uw && (w == nw), 0);
            }
        }
    }
    return res;
}

void run() {
    memset(dp, -1, sizeof(dp));
    int a, b, k, w;
    cin >> a >> b >> k >> w;
    trans(K, k), trans(W, w);

    memset(dp, -1, sizeof(dp));
    trans(A, a), trans(B, b);
    ll ans = 0;
    ans += dfs(N - 1, 1, 1, 1, 1, 0);

    memset(dp, -1, sizeof(dp));
    trans(A, b), trans(B, a);
    ans += dfs(N - 1, 1, 1, 1, 1, 0);
    ans -= min(a, b) + 1;
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