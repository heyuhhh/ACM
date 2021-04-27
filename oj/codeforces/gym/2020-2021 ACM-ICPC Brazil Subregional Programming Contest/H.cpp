#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 52;

ll C[N][N];

void init() {
    C[0][0] = 1;
    for (int i = 1; i < N; i++) {
        C[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
        }
    }
}

ll n, k;
ll a[60], p[60];
ll l, r;
ll ansl, ansr;
void run() {
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        p[i] = i == 1 ? 1 : 2 * p[i - 1];
    }
    cin >> l >> r;
    sort(a + 1, a + n + 1);
    ll tmp = 0;
    for(int i = n; i; i--) {
        if(tmp + a[i] <= r) tmp += a[i], ansr += p[i];
    }
    tmp = 0;
    for(int i = 1; i <= n; i++) {
        tmp += a[i];
        ansl += p[i];
        if(tmp > l) {
            for(int j = i; j; j--) {
                if(tmp - a[j] >= l) tmp -= a[j], ansl -= p[j];
            }
            break;
        }
    }

    vector<vector<vector<ll>>> dp(52, vector<vector<ll>>(52, vector<ll>(2, -1)));

    function<ll(ll, int, int, int)> calc = [&] (ll x, int cur, int has, int lim) {
        if (cur == -1) {
            return ll(has == k);
        }
        if (dp[cur][has][lim] != -1) return dp[cur][has][lim];
        ll& res = dp[cur][has][lim];
        res = 0;

        if (!lim) {
            int nd = k - has;
            int all = cur + 1;
            res = C[all][nd];
            return res;
        }

        int bit = (x >> cur & 1);
        int up = (lim ? bit : 1);

        for (int b = 0; b <= up; b++) {
            res += calc(x, cur - 1, has + b, (lim && (b == up)));
        }

        return res;
    };

    ll ans = calc(ansr, 51, 0, 1);
    for (int i = 0; i < 52; i++) {
        for (int j = 0; j < 52; j++) {
            dp[i][j][0] = dp[i][j][1] = -1;
        }
    }
    ans -= calc(ansl - 1, 51, 0, 1);
    cout << ans << '\n';
}

int main() {
#ifdef Local
    freopen("input.in", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0);
    cout << fixed << setprecision(10);
    // int T; cin >> T; while (T--) 
    init();
    run();
    return 0;
}