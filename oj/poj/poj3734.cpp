#include <cstdio>
#include <iostream>
using namespace std;
const int MOD = 10007;
typedef long long ll;
int qpow(ll a, ll b) {
    ll res = 1;
    while(b) {
        if(b & 1) res = res * a % MOD;   
        a = a * a % MOD;
        b >>= 1;
    }
    return res;   
}

void run() {
    int n; scanf("%d", &n);
    int ans = (qpow(4, n) + qpow(2, n + 1)) % MOD;
    ans = 1ll * ans * qpow(4, MOD - 2) % MOD;
    cout << ans << '\n';
}

int main() {
    int T; cin >> T;
    while(T--) run();
}
