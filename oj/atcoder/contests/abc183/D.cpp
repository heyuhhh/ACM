// Author : heyuhhh
// Created Time : 2020/11/15 20:16:23
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
const int N = 2e5 + 5;
void run() {
    int n, m;
    cin >> n >> m;
    vector<ll> nd(N);
    for (int i = 0; i < n; i++) {
        int s, t, w;
        cin >> s >> t >> w;
        nd[s] += w;
        nd[t] -= w;
    }
    for (int i = 0; i < N; i++) {
        if (i) nd[i] += nd[i - 1];
        if (nd[i] > m) {
            cout << "No" << '\n';
            return;
        }
    }
    cout << "Yes" << '\n';
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