#include <iostream>
 
using namespace std;
typedef long long LL;
const int modd = 1e9 + 7;
const int MAXN = 1e6 +7;
int sum[MAXN];
 
int quieck_pow(LL a, int n)
{
   LL ans = 1;
   while (n) {
       if (n & 1) ans = ans * a % modd;
       a = a * a % modd;
       n >>= 1;
   }
    return  ans;
}
 
int main()
{
    int cas, n, Q, L, R, p, q, a, x;
    scanf("%d", &cas);
    while (cas--) {
        scanf("%d%d", &n, &Q);
        for (int i = 1; i <= n; i++) {
            scanf("%d%d%d%d", &p, &q, &x, &a);
            LL tmp = (sum[i - 1] - sum[x - 1] + modd) % modd;
            sum[i] = (tmp + a) % modd * q % modd * quieck_pow(p, modd - 2) % modd;
            sum[i] = (sum[i] - tmp + modd) % modd;
            sum[i] = (sum[i - 1] + sum[i]) % modd;
        }
        while (Q--) {
            scanf("%d%d", &L, &R);
            printf("%d\n", (sum[R - 1] - sum[L - 1] + modd) % modd);
        }
    }
}