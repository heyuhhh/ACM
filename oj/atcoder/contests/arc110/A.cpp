// Author : heyuhhh
// Created Time : 2020/12/05 20:01:26
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
const int N = 100 + 5;

int primes[N], tot;
bool vis[N];

void init(int n) {
    for (int i = 2; i <= n; i++) {
        if (!vis[i]) {
            primes[++tot] = i;
            for (int j = i * i; j <= n; j += i) {
                vis[j] = true;
            }
        }
    }
}

int Max[N];

void run() {
    int n;
    cin >> n;
    ll ans = 1;
    for (int i = 2; i <= n; i++) {
        int x = i;
        for (int j = 1; j <= tot; j++) if (x % primes[j] == 0) {
            int now = 1;
            while (x % primes[j] == 0) {
                now *= primes[j];
                x /= primes[j];
            }
            Max[j] = max(Max[j], now);
        }
    }
    for (int i = 1; i <= tot; i++) if (Max[i]) {
        ans *= Max[i];
    }
    cout << ans + 1 << '\n';
}
int main() {
#ifdef Local
    freopen("input.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    init(30);
    run();
    return 0;
}