// Author : heyuhhh
// Created Time : 2020/08/22 09:33:39
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
    vector<int> a(3), b(3);
    for (int i = 0; i < 3; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < 3; i++) {
        cin >> b[i];
    }
    int ans = 0;
    if (a[0] < b[2]) {
        b[2] -= a[0];
        a[0] = 0;
    } else {
        a[0] -= b[2];
        b[2] = 0;
    }
    if (b[0] < a[1]) {
        a[1] -= b[0];
        b[0] = 0;
    } else {
        b[0] -= a[1];
        a[1] = 0;
    }
    if (a[1]) {
        a[2] -= b[2];
        ans = 2 * a[2];
    } else {
        a[2] -= b[2];
        ans = 2 * min(a[2], b[1]);
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