// Author : heyuhhh
// Created Time : 2020/11/15 20:02:17
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
#define x1 sx
#define x2 ex
#define y1 sy
#define y2 ey
//head
const int N = 1e5 + 5;
void run() {
    double sx, sy, ex, ey;
    cin >> sx >> sy >> ex >> ey;
    ey = -ey;
    double x = -y1 * (x1 - x2) / (y1 - y2) + x1;
    cout << x << '\n';
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