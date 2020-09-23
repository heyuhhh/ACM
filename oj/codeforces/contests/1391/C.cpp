// Author : heyuhhh
// Created Time : 2020/09/06 19:34:33
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
    int ans = 1;
    for (int i = 1; i <= n; i++) 
        ans = 1ll * ans * i % MOD;
    int res = 1;
    for (int i = 1; i < n; i++)
        res = 1ll * res * 2 % MOD;
    ans = (ans - res + MOD) % MOD;
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