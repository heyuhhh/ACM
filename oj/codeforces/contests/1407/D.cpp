// Author : heyuhhh
// Created Time : 2020/09/09 00:21:00
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
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> sta(n);
    int top = -1;
    vector<int> big(n);
    for (int i = 0; i < n; i++) {
        while (top >= 0 && a[sta[top]] <= a[i])
            big[sta[top--]] = i;
        sta[++top] = i;
    }
    while (top >= 0) 
        big[sta[top--]] = -1;
    vector<int> small(n);
    for (int i = 0; i < n; i++) {
        while (top >= 0 && a[sta[top]] >= a[i])
            small[sta[top--]] = i;
        sta[++top] = i;
    }
    while (top >= 0)
        small[sta[top--]] = -1;
    
    vector<int> lbig(n);
    for (int i = n - 1; i >= 0; i--) {
        while (top >= 0 && a[sta[top]] <= a[i])
            lbig[sta[top--]] = i;
        sta[++top] = i;
    }
    while (top >= 0) 
        lbig[sta[top--]] = -1;
    vector<int> lsmall(n);
    for (int i = n - 1; i >= 0; i--) {
        while (top >= 0 && a[sta[top]] >= a[i])
            lsmall[sta[top--]] = i;
        sta[++top] = i;
    }
    while (top >= 0)
        lsmall[sta[top--]] = -1;
    
    vector<vector<int>> G(n);
    for (int i = 0; i < n; i++) {
        if (lsmall[i] != -1)
            G[i].push_back(lsmall[i]);
        if (lbig[i] != -1)
            G[i].push_back(lbig[i]);
        if (small[i] != -1)
            G[small[i]].push_back(i);
        if (big[i] != -1)
            G[big[i]].push_back(i);
    }
    vector<int> dp(n, INF);
    dp[0] = 0;
    for (int i = 1; i < n; i++) {
        for (auto j : G[i]) {
            dp[i] = min(dp[i], dp[j] + 1);
        }
    }
    int res = dp[n - 1];
    cout << res << '\n';
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