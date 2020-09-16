// Author : heyuhhh
// Created Time : 2020/09/13 20:12:41
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
const int N = 1e5 + 5, MOD = 1e9 + 7;
void add(int& x, int y) {
    x += y;
    if (x >= MOD) x -= MOD;
}
void run() {
    int S;
    cin >> S;
    vector<int> dp(S + 1);
    dp[0] = 1;
    for (int i = 0; i < S; i++) {
        for (int j = 3; j <= S; j++) {
            if (i + j <= S) {
                add(dp[i + j], dp[i]);
            }
        }
    }
    cout << dp[S] << '\n';
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