// Author : heyuhhh
// Created Time : 2021/02/25 13:17:12
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
    if (n == 0) {
        cout << 0 << '\n';
        return;
    }
    vector<vector<int>> at(N);
    vector<vector<int>> has(n);
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int x;
            cin >> x;
            --x;
            at[x].emplace_back(i);
            has[i].emplace_back(x);
        }
    }
    vector<int> c(n);
    for (int i = n - 1; i >= 0; i--) {
        c[i] = 1;
        for (auto it : has[i]) {
            while (at[it].back() > i) {
                if (c[at[it].back()] >= c[i]) {
                    c[i] = c[at[it].back()] + 1;
                }
                at[it].pop_back();
            }
        }
    }
    int ans = *max_element(all(c));
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