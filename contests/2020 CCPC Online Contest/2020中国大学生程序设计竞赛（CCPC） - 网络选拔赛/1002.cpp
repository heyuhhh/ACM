// Author : heyuhhh
// Created Time : 2020/09/20 13:01:45
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
const int N = 2e5 + 5;

ll sum1[N], sum2[N], prime[N];
ll w[N], ind1[N], ind2[N];
ll g1[N], g2[N];
bool chk[N];
int tot, cnt;
void pre(int n) { //  \sqrt
    chk[1] = 1;
    for(int i = 1; i <= n; i++) {
        if(!chk[i]) {
            prime[++tot] = i;
            sum1[tot] = sum1[tot - 1] + i;
        }
        for(int j = 1; j <= tot && prime[j] * i <= n; j++) {
            chk[i * prime[j]] = 1;
            if(i % prime[j] == 0) break;
        }
    }
}
 
void calc_g(ll n) {
    int z = sqrt(n + 0.5);
    for(ll i = 1, j; i <= n; i = j + 1) {
        j = n / (n / i);
        w[++cnt] = n / i;
        
        g1[cnt] = 1ll * w[cnt] * ((w[cnt] + 1)) / 2 - 1;

        if(n / i <= z) ind1[n / i] = cnt;
        else ind2[n / (n / i)] = cnt;
    }
    for(int i = 1; i <= tot; i++) {
        for(int j = 1; j <= cnt && prime[i] * prime[i] <= w[j]; j++) {
            ll tmp = w[j] / prime[i], k;
            if(tmp <= z) k = ind1[tmp]; else k = ind2[n / tmp];
            g1[j] -= prime[i] * (g1[k] - sum1[i - 1]);
        }
    }
}

void run() {
    ll n, k;
    cin >> n >> k;
    int inv2 = (k + 1) / 2;
    cnt = 0;
    calc_g(n + 1);
    ll ans = (n + 1) % k * ((n + 2) % k) % k * inv2 % k;
    ll tmp = g1[ind2[1]] % k;
    ans = (ans + tmp) % k;
    ans -= 2 + 3;
    if (ans < 0) ans += k;
    cout << ans << '\n';
}
int main() {
#ifdef Local
    freopen("input.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    pre(100000);
    int T; cin >> T; while(T--)
    run();
    return 0;
}