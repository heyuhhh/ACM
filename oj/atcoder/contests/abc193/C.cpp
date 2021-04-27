// Author : heyuhhh
// Created Time : 2021/02/27 20:05:37
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
void run() {
    ll n;
    cin >> n;
    ll ans = n;
    map<ll, int> mp;
    for (int i = 2; 1ll * i * i <= n; i++) {
        for (ll j = 1ll * i * i; j <= n; j *= i) {
            if (mp.find(j) == mp.end()) {
                mp[j] = 1;
                --ans;
            }
        }
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