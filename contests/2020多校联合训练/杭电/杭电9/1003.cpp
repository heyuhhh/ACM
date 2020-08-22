// Author : heyuhhh
// Created Time : 2020/08/18 15:13:02
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
    int x, y, k;
    cin >> x >> y >> k;
    if (x > y) swap(x, y);
    int d = y - x;
    if (d % (k + 1)) {
        cout << 1 << '\n';
        return;
    }
    int n = d / (k + 1);
    double p = 1.0 * (1 - k + sqrt(1.0 * k * k + 2 * k + 5)) / 2;
    if (int(p * n) == x) {
        cout << 0 << '\n';
    } else {
        cout << 1 << '\n';
    }
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