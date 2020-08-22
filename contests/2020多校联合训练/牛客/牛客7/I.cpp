// Author : heyuhhh
// Created Time : 2020/08/05 20:10:05
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
const int N = 5000 + 5;
int MOD;

int qpow(ll a, ll b) {
    ll res = 1;
    while(b) {
        if(b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;   
    }
    return res;   
}
int c[N][N];

void init() {
    c[0][0] = 1;
    for (int i = 1; i < N; i++) {
        c[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % MOD;
        }
    }
}

int C(int n, int m) {
    return c[n][m];
}

int ans[N];
int f[N], A[N], a[N];

void run() {
    int T;
    cin >> T >> MOD;
    assert(MOD > 1);
    init();
    a[1] = 1;
    for (int i = 2; i < N; i++) {
        a[i] = qpow(i, i - 2);
    }
    
    f[0] = 1;
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < i; j++) {
            f[i] = (f[i] + 1ll * C(i - 1, j) * f[i - j - 1] % MOD * a[j + 1] % MOD) % MOD;
        }
    }
    
    A[1] = 0;
    for (int i = 2; i < N; i++) {
        for (int d = 1; d < i; d++) {
            A[i] = (A[i] + 1ll * i * C(i - 2, d - 1) % MOD * d % MOD * d % MOD * qpow(i - 1, i - 2 - d + 1) % MOD) % MOD;
        }
    }
    

    ans[1] = 0;
    for (int i = 2; i < N; i++) {
        for (int j = 0; j < i; j++) {
            ans[i] = (ans[i] + 1ll * C(i - 1, j) * ((1ll * f[i - j - 1] * A[j + 1] % MOD 
                    + 1ll * ans[i - j - 1] * a[j + 1] % MOD) % MOD) % MOD) % MOD;
        }
    }
    while (T--) {
        int n;
        cin >> n;
        cout << ans[n] << '\n';
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