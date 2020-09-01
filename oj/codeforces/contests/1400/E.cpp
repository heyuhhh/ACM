// Author : heyuhhh
// Created Time : 2020/08/26 00:44:37
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
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    function<int(int, int, int)> solve = [&] (int l, int r, int x) {
        if (r - l == 1) return a[l] > 0 ? 1 : 0;
        
        int Min = INF;
        for (int i = l; i < r; i++) {
            Min = min(Min, a[i]);
        }

        int ans = Min - x;
        for (int i = l, j; i < r; i = j + 1) {
            j = i;
            if (a[i] == Min) continue;
            while (j < r && a[j] != Min) ++j;
            ans += solve(i, j, Min);
        }

        ans = min(ans, r - l);
        return ans;
    };
    int ans = solve(0, n, 0);
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