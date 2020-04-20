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
int pown[N];

void run() {
    cin >> n >> m;
    if(m == 1) {
        cout << 1ll * n * (n + 1) / 2 % MOD << '\n';
        return;
    }
    pown[0] = 1;
    for(int i = 1; i <= m; i++) pown[i] = 1ll * pown[i - 1] * n % MOD;
    int powm = qpow(m, n), powm1 = qpow(m, n + 1);
    int inv = qpow(1 - m + MOD, MOD - 2);
    f[0] = 1ll * m * (1 - powm + MOD) % MOD * inv % MOD;
    for(int i = 0; i < N; i++) {
        C[i][0] = 1;
        for(int j = 1; j <= i; j++) {
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;   
        }
    }
    for(int i = 1; i <= m; i++) {
        f[i] = (MOD - 1ll * pown[i] * powm1 % MOD) % MOD;  
        for(int k = 0; k < i; k++) {
            int res = 1ll * C[i][k] * m % MOD * ((f[k] + (k == 0) - 1ll * powm * pown[k] % MOD + MOD) % MOD) % MOD;
            f[i] = (f[i] + res) % MOD;
        }
        f[i] = 1ll * f[i] * inv % MOD;
    }
    cout << f[m] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
