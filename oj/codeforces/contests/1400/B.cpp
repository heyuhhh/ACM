// Author : heyuhhh
// Created Time : 2020/08/25 22:40:47
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
    int p, f;
    cin >> p >> f;
    int cs, cw;
    cin >> cs >> cw;
    int s, w;
    cin >> s >> w;
    if (s > w) {
        swap(s, w);
        swap(cs, cw);
    }
    int A = p / s, B = f / s;
    if (A + B <= cs) {
        cout << A + B << '\n';
    } else {
        int ans = 0;
        for (int i = 0; i <= min(A, cs); i++) {
            int nowp = p - i * s;
            int r = cs - i;
            if (r * s > f) continue;
            int nowf = f - r * s;
            int res = cs;

            // cout << i << ' ' << nowp << ' ' << nowf<<endl;

            int p1 = nowp / w, p2 = nowf / w;
            res += min(cw, p1 + p2);

            ans = max(ans, res);
        }
        cout << ans << '\n';
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