// Author : heyuhhh
// Created Time : 2020/09/19 20:48:35
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
    ll n;
    int x, m;
    cin >> n >> x >> m;
    
    vector<int> f(m + 2);
    vector<ll> sum(m + 2);
    f[1] = sum[1] = x;

    if (n <= m) {
        for (int i = 2; i <= n; i++) {
            f[i] = 1ll * f[i - 1] * f[i - 1] % m;
            sum[i] = sum[i - 1] + f[i];
        }
        ll res = sum[n];
        cout << res << '\n';
        return;
    }

    ll ans = x, S;
    vector<int> last(m + 2, -1);
    last[x] = 1;
    int len, k;
    for (int i = 2; i <= m + 1; i++) {
        f[i] = 1ll * f[i - 1] * f[i - 1] % m;
        sum[i] = sum[i - 1] + f[i];
        if (last[f[i]] != -1) {
            k = last[f[i]];
            len = i - k;
            S = sum[i] - sum[last[f[i]]];
            n -= i - 1;
            break;
        }
        ans += f[i];
        last[f[i]] = i;
    }
    ans += (n / len) * S + sum[k + n % len - 1] - sum[k - 1];
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