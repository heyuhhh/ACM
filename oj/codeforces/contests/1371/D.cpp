// Author : heyuhhh
// Created Time : 2020/07/16 16:37:37
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
    int n, k; cin >> n >> k;
    int r = n * n - k;
    vector<vector<int>> a(n, vector<int>(n, 1));
    int i = 0, j = 0, cnt = 0;
    while (r--) {
        a[i][j] = 0;
        ++i, ++j;
        i %= n, j %= n;
        ++cnt;
        if (cnt % n == 0) {
            i = cnt / n;
            j = 0;
        }
    }

    int Max = 0, Min = INF;
    for (int i = 0; i < n; i++) {
        int t = 0;
        for (int j = 0; j < n; j++) {
            t += a[i][j];
        }
        Max = max(t, Max);
        Min = min(t, Min);
    }
    int ans = (Max - Min) * (Max - Min);

    Max = 0, Min = INF;
    for (int i = 0; i < n; i++) {
        int t = 0;
        for (int j = 0; j < n; j++) {
            t += a[j][i];
        }
        Max = max(t, Max);
        Min = min(t, Min);
    }    
    ans += (Max - Min) * (Max - Min);

    cout << ans << '\n';

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j];
        } 
        cout << '\n';
    }
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