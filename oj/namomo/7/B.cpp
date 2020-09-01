// Author : heyuhhh
// Created Time : 2020/08/29 19:15:46
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

int fac[N];
void init() {
    fac[0] = 1;
    for (int i = 1; i < N; i++) {
        fac[i] = 1ll * fac[i - 1] * i % MOD;
    }
}

void run() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << 1 << '\n';
        return;
    }
    int tot = n * n;
    int ans;
    ans = (1ll * tot / 2 * (tot / 2 - 1) + 1ll * (tot + 1) / 2 * ((tot + 1) / 2 - 1)) % MOD;
    ans = 1ll * ans * fac[tot - 2] % MOD;
    cout << ans << '\n';
}
int main() {
#ifdef Local
    freopen("input.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    init();
    int T; cin >> T; while(T--)
    run();
    return 0;
}