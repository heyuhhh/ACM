// Author : heyuhhh
// Created Time : 2020/07/16 16:11:28
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
    ll a, b, n, m;
    cin >> a >> b >> n >> m;
    if (a + b < n + m) {
        cout << "No" << '\n';
        return;
    }
    if (a < b) {
        ll d = b - a;
        if (n >= d) {
            n -= d;
            b = a;
        } else {
            if (a >= m) {
                cout << "Yes" << '\n';
            } else {
                cout << "No" << '\n';
            }
            return;
        }
    }
    if (a >= b) {
        ll d = a - b;
        if (d > n) {
            if (b >= m) {
                cout << "Yes" << '\n';
            } else {
                cout << "No" << '\n';
            }
        } else {
            a -= d, n -= d;
            assert(a == b);
            if (n < m) {
                if (m <= a) {
                    cout << "Yes" << '\n';
                } else {
                    cout << "No" << '\n';
                }
            } else {
                if (b >= m) {
                    cout << "Yes" << '\n';
                } else {
                    cout << "No" << '\n';
                }
            }
        }
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