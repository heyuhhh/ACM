// Author : heyuhhh
// Created Time : 2020/08/01 12:54:54
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
    vector<int> ans;
    while (n) {
        if (n < m) swap(n, m);
        for (int i = 1; i <= m; i++) {
            ans.push_back(m);
        }
        n -= m;
    }
    sort(all(ans));
    reverse(all(ans));
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