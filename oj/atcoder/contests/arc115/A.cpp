// Author : heyuhhh
// Created Time : 2021/03/26 09:30:22
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
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    int even = 0, odd = 0;
    ll ans = 1ll * n * (n - 1) / 2;
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = 0; j < m; j++) {
            cnt += (s[i][j] - '0');
        }
        if (cnt & 1) {
            ans -= odd;
            ++odd;
        } else {
            ans -= even;
            ++even;
        }
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
    run();
    return 0;
}