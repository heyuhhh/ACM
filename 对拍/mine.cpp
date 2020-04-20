/*
 * Author:  heyuhhh
 * Created Time:  2020/4/17 19:45:42
 */
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <iomanip>
#include <assert.h>
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
const int N = 1000 + 5, MOD = 1e9 + 7;

int qpow(ll a, ll b) {
    ll res = 1;
    while(b) {
        if(b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }   
    return res;
}

int n, m;
int f[N], C[N][N];

void run() {
    cin >> n >> m;
    f[0] = 1ll * m * (1 - qpow(m, n) + MOD) % MOD * qpow(1 - m + MOD, MOD - 2) % MOD;
    for(int i = 0; i < N; i++) {
        C[i][0] = 1;
        for(int j = 1; j <= i; j++) {
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;   
        }
    }
    for(int i = 1; i <= m; i++) {
        f[i] = (MOD - 1ll * qpow(n, i) * qpow(m, n + 1) % MOD) % MOD;  
        for(int k = 0; k < i; k++) {
            int res = 1ll * C[i][k] * m % MOD * ((f[k] + (k == 0) - 1ll * qpow(m, n) * qpow(n, k) % MOD + MOD) % MOD) % MOD;
            f[i] = (f[i] + res) % MOD;
        }
        f[i] = 1ll * f[i] * qpow(MOD + 1 - m, MOD - 2) % MOD;
    }
    cout << f[m] << '\n';
}

int main() { 
    run();
    return 0;
}
