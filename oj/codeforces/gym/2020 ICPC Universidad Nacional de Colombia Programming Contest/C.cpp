// Author : heyuhhh
// Created Time : 2021/03/01 15:38:19
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
const int N = 5e6 + 5, MOD = 1e9 + 7;

inline void add(int& x, int y) {
    x += y;
    if (x >= MOD) x -= MOD;
}
inline void dec(int& x, int y) {
    x -= y;
    if (x < 0) x += MOD;
}

int f[N];

void run() {
    int a, k;
    cin >> a >> k;
    
    int sum = 0;
    int t = 1;
    for (int i = 1; i <= k; i++) {
        t = 1ll * t * a % MOD;
        add(f[i], t);
        for (int j = i + i; j <= k; j += i) {
            dec(f[j], f[i]);
        }
        add(sum, f[i]);
    }
    cout << sum << '\n';
}
int main() {
#ifdef Local
    freopen("input.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}