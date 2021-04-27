// Author : heyuhhh
// Created Time : 2021/02/21 20:02:20
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
    int K;
    cin >> K;
    vector<int> d(K + 1);
    for (int i = 1; i <= K; i++) {
        for (int j = 1; i * j <= K; j++) {
            ++d[i * j];
        }
    }
    for (int i = 1; i <= K; i++) {
        d[i] += d[i - 1];
    }
    ll ans = 0;
    for (int i = 1; i <= K; i++) {
        int p = K / i;
        ans += d[p];
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