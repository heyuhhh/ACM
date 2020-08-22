// Author : heyuhhh
// Created Time : 2020/08/20 20:10:09
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
const int N = 5e6 + 5;

int n, m;
unsigned long long k1, k2;
const int threshold = 10000000;
int a[N], b[N];

unsigned long long f() {
    unsigned long long k3 = k1, k4 = k2;
    k1 = k4;
    k3 ^= (k3 << 23);
    k2 = k3 ^ k4 ^ (k3 >> 17) ^ (k4 >> 26);
    return k2 + k4;
}

void gen(int n, unsigned long long _k1, unsigned long long _k2) {
    k1 = _k1;
    k2 = _k2;
    for (int i = 1; i <= n; i++) {
        a[i] = f() % threshold + 1;
        b[i] = f() % threshold + 1;
    }
}

void run() {
    gen(n, k1, k2);
    for (int i = 1; i <= n; i++) {
        b[i] += a[i];
    }
    sort(a + 1, a + n + 1, greater<int>());
    sort(b + 1, b + n + 1, greater<int>());
    int p = 1, q = 0;
    ll res = a[1];
    ll cur = a[1];
    for (int i = 2; i <= m; i++) {
        ll cur1 = -1e18;
        ll cur2 = -1e18;
        if (p + 1 <= n) cur1 = a[p + 1];
        if (p && q + 1 <= n) cur2 = b[q + 1] - a[p];

        if (cur1 > cur2) {
            ++p;
            cur += cur1;
        } else {
            ++q;
            --p;
            cur += cur2;
        }

        res ^= cur;
    }
    cout << res << '\n';
}
int main() {
#ifdef Local
    freopen("input.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    while (cin >> n >> m >> k1 >> k2)
    run();
    return 0;
}