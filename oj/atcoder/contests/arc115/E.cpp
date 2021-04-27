// Author : heyuhhh
// Created Time : 2021/03/31 21:38:18
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
const int N = 5e5 + 5, MOD = 998244353;

inline int add(int x, int y) {
    return x + y >= MOD ? x + y - MOD : x + y;
}
inline int dec(int x, int y) {
    return x - y < 0 ? x - y + MOD : x - y;
}
inline int mul(int x, int y) {
    return 1ll * x * y % MOD;
}

int n;
int a[N], L[N];
int sta[N], top;

int dp[N];
int sum[N][2];

void run() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = n; i >= 0; i--) {
        while (top && a[sta[top]] > a[i]) {
            L[sta[top--]] = i;
        }
        sta[++top] = i;
    }
    dp[0] = 1;
    sum[0][0] = 1;
    sum[0][1] = MOD - 1;
    for (int i = 1; i <= n; i++) {
        sum[i][0] = sum[i - 1][0];
        sum[i][1] = sum[i - 1][1];
        if (i & 1) {
            dp[i] = mul(a[i], dec(sum[i - 1][0], (L[i] == 0 ? 0 : sum[L[i] - 1][0])));
        } else {
            dp[i] = mul(a[i], dec(sum[i - 1][1], (L[i] == 0 ? 0 : sum[L[i] - 1][1])));
        }
        if (L[i] > 0) {
            if ((L[i] & 1) == (i & 1)) {
                dp[i] = add(dp[i], dp[L[i]]);
            } else {
                dp[i] = dec(dp[i], dp[L[i]]);
            }
        }        
        if (i & 1) {
            sum[i][0] = dec(sum[i][0], dp[i]);
            sum[i][1] = add(sum[i][1], dp[i]);
        } else {
            sum[i][0] = add(sum[i][0], dp[i]);
            sum[i][1] = dec(sum[i][1], dp[i]);
        }
    }
    int ans = dp[n];
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