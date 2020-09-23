// Author : heyuhhh
// Created Time : 2020/09/06 09:26:08
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
    if (n <= 30) {
        cout << "NO" << '\n';
    } else {
        cout << "YES" << '\n';
        if (n == 36) {
            cout << "5 6 10 15" << '\n';
        } else if (n == 40) {
            cout << "6 9 10 15" << '\n';
        } else if (n == 44) {
            cout << "6 10 13 15" << '\n';
        } else {
            cout << "6 10 14" << ' ' << n - 30 << '\n';
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