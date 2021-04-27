// Author : heyuhhh
// Created Time : 2021/03/26 09:47:57
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
    vector<int> cnt(n, 1);
    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        ans.emplace_back(cnt[i - 1]);
        for (int j = i + i; j <= n; j += i) {
            if (cnt[j - 1] == cnt[i - 1]) {
                ++cnt[j - 1];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (i) cout << ' ';
        cout << ans[i];
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