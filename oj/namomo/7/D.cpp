// Author : heyuhhh
// Created Time : 2020/08/29 20:43:58
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
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    auto sum = [&] (int x) {
        return 1ll * x * (x + 1) / 2;
    };
    int x;
    for (x = 1; x <= m; x++)
        if (sum(x) >= m) 
            break;

    int ans = 0;
    int p = 0;
    int now = 1;
    while(p < n) {
        // cout << now + x << endl;
        while (p < n && a[p] < now + x - 1) ++p;
        if (p >= n) break;
        ++ans;
        int d = a[p] - now + 1;
        int tot = d;
        while (tot < m) {
            ++now;
            --d;
            tot += d;
        }
        ++now;
        ++p;
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