// Author : heyuhhh
// Created Time : 2020/07/17 09:55:43
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
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> ans;
    for (int k = 0; k < n << 1; k++) {
        int nxt = -1;
        vector<bool> vis(n + 1);
        for (int i = 0; i < n; i++) {
            vis[a[i]] = true;
        }
        for (int i = 0; i <= n; i++) {
            if (!vis[i]) {
                nxt = i;
                break;
            }
        }
        if (nxt == n) {
            int p = n - 1;
            while (p >= 0 && a[p] == p) --p;
            if (p < 0) break;
            a[p] = n;
            ans.push_back(p + 1);
            continue;
        }
        if (a[nxt] != nxt) {
            a[nxt] = nxt;
            ans.push_back(nxt + 1);
        }
    }
    cout << sz(ans) << '\n';
    for (auto it : ans) {
        cout << it << ' ';
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
    int T; cin >> T; while(T--)
    run();
    return 0;
}