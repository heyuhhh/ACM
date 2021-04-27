// Author : heyuhhh
// Created Time : 2021/03/13 12:54:57
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
void run() {
    int n;
    cin >> n;
    vector<int> cnt(N);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ++cnt[x];
    }
    vector<int> f(N);
    int ans = 0;
    for (int i = 1; i <= 100000; i++) {
        f[i] = 1ll * (f[i - 1] + 1) * cnt[i] % MOD;
        ans = (ans + f[i]) % MOD;
    }
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