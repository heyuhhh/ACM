// Author : heyuhhh
// Created Time : 2021/02/06 20:01:56
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
    int v, s, t, d;
    cin >> v >> s >> t >> d;
    s *= v;
    t *= v;
    if (s <= d && d <= t) {
        cout << "No" << '\n';
    } else {
        cout << "Yes" << '\n';
    }
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