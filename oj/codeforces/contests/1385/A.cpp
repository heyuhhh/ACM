// Author : heyuhhh
// Created Time : 2020/07/18 09:15:55
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
    int a[3];
    for (int i = 0; i < 3; i++) {
        cin >> a[i];
    }
    sort(a, a + 3);
    if (a[2] == a[1]) {
        cout << "YES" << '\n';
        cout << a[2] << ' ' << a[0] << ' ' << a[0] << '\n';
    } else {
        cout << "NO" << '\n';
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