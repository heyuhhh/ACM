// Author : heyuhhh
// Created Time : 2020/11/07 12:43:22
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
const int N = 1e5 + 5;

int v[N], primes[N], tot;

void init() {
    for (int i = 2; i < N; i++) {
        if (!v[i]) {
            v[i] = i;
            primes[++tot] = i;
        }
        for (int j = 1; j <= tot && 1ll * primes[j] * i < N; j++) {
            v[primes[j] * i] = primes[j];
            if (i % primes[j] == 0) break;
        }
    }
}

void run() {
    int n;
    cin >> n;
    vector<int> d;
    for (int i = 1; i <= tot && 1ll * primes[i] * primes[i] <= n; i++) {
        while (n % primes[i] == 0) {
            n /= primes[i];
            d.emplace_back(primes[i]);
        }
    }
    if (n > 1) d.emplace_back(n);
    if (sz(d) <= 1) {
        cout << 0 << '\n';
        return;
    }
    if (sz(d) == 2) {
        cout << -1 << '\n';
        return;
    }
    sort(d.rbegin(), d.rend());
    int ans = d[0] * d[1];
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