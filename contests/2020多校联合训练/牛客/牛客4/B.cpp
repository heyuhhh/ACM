// Author : heyuhhh
// Created Time : 2020/07/20 12:10:55
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
const int N = 1e6 + 5, MOD = 1e9 + 7;
int qpow(ll a, ll b) {
    ll res = 1;
    while(b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

int v[N], prime[N];
int num;
void Euler() {
    for(int i = 2; i < N; i++) {
        if(v[i] == 0) {
            v[i] = i;
            prime[++num] = i;
        }
        for(int j = 1; j <= num && prime[j] * i < N; j++) {
            v[prime[j] * i] = prime[j] ;
        }
    }
} 

void run() {
    int n, c;
    cin >> n >> c;
    int x = 0;
    for (int i = 1; 1ll * prime[i] * prime[i] <= n && i <= num; i++) {
        while (n % prime[i] == 0) {
            n /= prime[i];
            ++x;
        }
    }
    if (n > 1) {
        ++x;
    }
    int ans = qpow(c, x);
    cout << ans << '\n';
}

int main() {
#ifdef Local
    freopen("input.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    Euler();
    int T; cin >> T; while(T--)
    run();
    return 0;
}