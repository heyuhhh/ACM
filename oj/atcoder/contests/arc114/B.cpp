// Author : heyuhhh
// Created Time : 2021/03/14 20:14:12
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
const int N = 1e5 + 5, MOD = 998244353;
void run() {
    int n;
    cin >> n;
    vector<int> f(n, -1);
    iota(all(f), 0);
    auto find = [&] (int x) {
        while (x != f[x]) {
            int t = f[x];
            f[x] = f[f[x]];
            x = t;
        }
        return x;
    };
    auto Union = [&] (int x, int y) {
        x = find(x), y = find(y);
        if (x != y) {
            f[x] = y;
            return false;
        }
        return true;
    };
    int ans = 1;
    for (int i = 0; i < n; i++) {
        int to;
        cin >> to;
        --to;
        if (i == to || Union(i, to)) {
            ans = 1ll * ans * 2 % MOD;
        }
    }
    --ans;
    if (ans < 0) ans += MOD;
    cout << ans << '\n';
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