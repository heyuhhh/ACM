#include <bits/stdc++.h>
using namespace std;

int n;
long long a[1 << 20], b[1 << 20];

int main() {
    int T; scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) scanf("%lld%lld", a + i, b + i);
        long long totu = accumulate(a, a + n, 0ll);
        long long totv = accumulate(b, b + n, 0ll);
        long long ans = min(totu, totv);
        for (int i = 0; i < n; i++) ans = min(ans, totu + totv - a[i] - b[i]);
        printf("%lld\n", ans);
    }
    return 0;
}
