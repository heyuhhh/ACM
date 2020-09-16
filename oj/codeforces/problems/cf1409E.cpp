// Author : heyuhhh
// Created Time : 2020/09/10 09:54:55
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
    int n, k;
    cin >> n >> k;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; i++)
        cin >> x[i];
    for (int i = 0; i < n; i++)
        cin >> y[i];
    sort(all(x));
    int ans = 0;
    vector<int> res(n);
    for (int i = 0; i < n; i++) {
        int l = x[i], r = x[i] + k;
        int p1 = upper_bound(all(x), r) - x.begin();
        res[i] = p1 - i;
    }
    vector<int> pre(n), suf(n);
    pre[0] = res[0];
    for (int i = 1; i < n; i++)
        pre[i] = max(pre[i - 1], res[i]);
    suf[n - 1] = res[n - 1];
    for (int i = n - 2; i >= 0; i--)
        suf[i] = max(suf[i + 1], res[i]);
    
    for (int i = 0; i < n; i++) {
        int t = res[i];
        int p = upper_bound(all(x), x[i] + k) - x.begin();
        int tmp = 0;
        if (p < n) 
            tmp = suf[p];
        ans = max(ans, t + tmp);
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