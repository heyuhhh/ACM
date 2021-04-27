// Author : heyuhhh
// Created Time : 2021/03/19 14:16:40
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

bitset<N> pre, now;

void run() {
    int n;
    ll k;
    cin >> n >> k;
    --k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        if (((k + i) & k) == k) {
            pre[i] = 1;
        }
    }
    vector<int> b(n);
    for (int bit = 0; bit < 17; ++bit) {
        now.reset();
        for (int i = 0; i < n; ++i) {
            now ^= (pre << i);
            if (now[i]) b[i] ^= (1 << bit);
        }
    }
    for (int i = 0; i < n; ++i) {
        if (i) cout << ' ';
        cout << b[i];
    }
    cout << '\n';
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