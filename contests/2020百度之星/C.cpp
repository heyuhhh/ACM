#include <bits/stdc++.h>
using namespace std;
int t;
int n, l, k, a[100010];
inline long long calc() {
    sort(a, a + n);
    reverse(a, a + n);
    int pos = 0;
    for (int i = 0; i < n; i++) {
        if (i % l < k - 1) pos++;
    }
    int lst = n;
    long long ans = 0;
    for (int i = n; i --> 0;) {
        if (i % l >= k - 1) {
            cout << i << ' ' << a[pos] << '\n';
            ans += 1ll * a[pos++] * (lst - max(i, l - 1));
            lst = max(i, l - 1);
        }
    }
    return ans;
}
int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d%d", &n, &l, &k);
        for (int i = 0; i < n; i++) {
            scanf("%d", a + i);
        }
        long long min = calc();
    }
}