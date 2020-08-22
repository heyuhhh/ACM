// Author : heyuhhh
// Created Time : 2020/08/18 13:03:39
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
    int n;
    cin >> n;
    vector<int> f(n, -1);
    vector<int> d(n, 1);
    ll ans = 1;
    for (int i = 1; i < n; i++) {
        int fa; cin >> fa;
        --fa;
        f[i] = fa;
        d[i] = d[fa] + 1;
        ans += d[i];
    }
    int x;
    int Max = *max_element(all(d));
    for (int i = 0; i < n; i++) {
        if (d[i] == Max) {
            x = i;
            break;
        }
    }
    while (x >= 0) {
        ans += -d[x] + n;
        x = f[x];
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
    int T; cin >> T; while(T--)
    run();
    return 0;
}