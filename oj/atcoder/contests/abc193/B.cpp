// Author : heyuhhh
// Created Time : 2021/02/27 20:03:30
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
    int ans = INF;
    for (int i = 0; i < n; i++) {
        int a, p, x;
        cin >> a >> p >> x;
        if (a < x) {
            ans = min(ans, p);
        }
    }
    if (ans == INF) ans = -1;
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