#include <bits/stdc++.h>
 
using namespace std;
typedef long long LL;
const LL Mod = 1e9 + 7;
const int Maxn = 105;
LL quick_pow(LL x, LL n){
    LL a = x, ans = 1;
    while(n){
        if (n & 1) ans = ans * a % Mod;
        a = a * a % Mod;
        n >>= 1;
    }
    return ans;
}
LL cal(int n, int p, int k){
    LL a[Maxn][20], b[Maxn][20];
    for (int i = 1; i <= k; i++) {
        a[1][i] = quick_pow(p, i / 2);
        if (p % 4 == 1) a[2][i] = ((p - 1) * i + p) % Mod * quick_pow(p, i - 1) % Mod;
        else a[2][i] = quick_pow(p, i - (i & 1));
    }
    for (int i = 3; i <= n; i++)
        for (int K = 1; K <= k; K++){
            b[i][K] = quick_pow(p, K) * a[i - 2][K] % Mod;
            LL tmp = quick_pow(p, K - 1) * (p - 1) % Mod;
            b[i][K] += quick_pow(p, K * (i - 2)) * tmp % Mod;
            for (int j = 1; j < K; j++)
                b[i][K] += tmp * a[i - 2][j] % Mod * quick_pow(p, (i - 2) * (K - j)) % Mod;
            b[i][K] %= Mod;
            if (p % 4 == 1) a[i][K] = b[i][K];
            else{
                LL sum = quick_pow(p, K * (i - 1));
                for (int j = 1; j <= K / 2; j++){
                    sum += a[i - 1][2 * j] * quick_pow(p, (K - 2 * j) * (i - 1) + j) % Mod;
                    sum -= a[i - 1][2 * j - 1] * quick_pow(p, (K - 2 * j + 1) * (i - 1) + j - 1) % Mod;
                }
                sum = (sum * 2) % Mod;
                a[i][K] = (sum - b[i][K] + Mod + Mod) % Mod;
            }
        //cout << i << " " << K << " " << a[i][k] << " " << b[i][k] << endl;
    }
    return b[n][k];
}
int main()
{
    //freopen("data.in", "r", stdin);
    //freopen("data.out", "w", stdout);
    int T;
    cin >> T;
    while(T--){
        int n, m;
        cin >> n >> m;
        LL ans = 1;
        for (int i = 3; i * i <= m; i++){
            if (m % i == 0){
                int cnt = 0;
                while (m % i == 0){
                    m /= i;
                    cnt++;
                }
                ans *= cal(n, i, cnt);
                ans %= Mod;
            }
        }
        if (m > 1) ans *= cal(n, m, 1), ans %= Mod;
        cout << ans << endl;
    }
    return 0;
}