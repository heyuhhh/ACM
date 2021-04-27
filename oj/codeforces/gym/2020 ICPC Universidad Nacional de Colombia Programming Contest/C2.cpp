// Author : heyuhhh
// Created Time : 2021/03/01 17:30:21
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
const int N = 1e5 + 5, MOD = 1e9 + 7;
inline int add(int x, int y) {
    return x + y >= MOD ? x + y - MOD : x + y;
}
inline int dec(int x, int y) {
    return x - y < 0 ? x - y + MOD : x - y;
}
void run() {
    int a, k;
    cin >> a >> k;
    vector<int> f(k + 1);
    f[1] = a;
    int sum = a;
    int t = a;
    for (int i = 2; i <= k; i++) {
        t = 1ll * t * a % MOD;
        f[i] = dec(t, sum);
        sum = add(sum, f[i]);
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