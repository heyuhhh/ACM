// Author : heyuhhh
// Created Time : 2020/09/19 20:25:41
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
    vector<int> d(n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j * j <= i; j++) if (i % j == 0) {
            ++d[i];
            if (j != i / j) {
                ++d[i];
            }
        }
    }
    ll ans = 0;
    for (int i = 1; i < n; i++) {
        ans += d[i];
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