/*
 * Author:  heyuhhh
 * Created Time:  2020/4/28 9:44:14
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
const int N = 50000 + 5, MOD = 1e9 + 7;

bool vis[N];
void init() {
    vis[0] = vis[1] = true;
    for (int i = 2; i < N; i++) {
        if (!vis[i]) {
            for (ll j = 1ll * i * i; j < N; j += i) {
                vis[j] = true;   
            }
        }   
    }
}

int n, m;
int f[N << 2];

void FWT_xor(int *a, int n, int op) {
    static int inv2 = (MOD + 1) / 2;
    for(int i = 1; i < n; i <<= 1)
        for(int p = i << 1, j = 0; j < n; j += p)
            for(int k = 0; k < i; k++) {
                int X = a[j + k], Y = a[i + j + k];
                a[j + k] = (X + Y) % MOD; a[i + j + k] = (X + MOD - Y) % MOD;
                if(op == -1) a[j + k] = 1ll * a[j + k] * inv2 % MOD, a[i + j + k] = 1ll * a[i + j + k] * inv2 % MOD;
            }                
}

int qpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }   
    return res;
}

void run() {
    memset(f, 0, sizeof(f));
    for (int i = 0; i <= m; i++) {
        if (!vis[i]) ++f[i];
    }
    int l = 1;
    while (l < m + 1) l <<= 1;
    FWT_xor(f, l, 1);
    for (int i = 0; i < l; i++) {
        f[i] = qpow(f[i], n);
    }
    FWT_xor(f, l, -1);
    cout << f[0] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    init();
    while (cin >> n >> m) run();
    return 0;
}
