// Author : heyuhhh
// Created Time : 2021/02/19 16:29:08
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
    int n, m, k;
    cin >> n >> m >> k;
    int tr = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        tr += x;
    }
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        tr += x;
    }
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
    }
    int ans = abs(tr - n);
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