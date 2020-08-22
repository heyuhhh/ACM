// Author : heyuhhh
// Created Time : 2020/07/28 12:10:14
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
    int n, p;
    cin >> n >> p;
    vector<int> a(n + 1);
    vector<int> sum(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] %= p;
    }
    for (int i = 1; i <= n; i++) {
        sum[i] = (sum[i - 1] + a[i]) % p;
    }
    vector<int> f(n + 1);
    vector<int> last(p, -1);
    last[0] = 0;
    for (int i = 1; i <= n; i++) {
        f[i] = f[i - 1];
        if (last[sum[i]] != -1) {
            f[i] = max(f[i], f[last[sum[i]]] + 1);
        }
        last[sum[i]] = i;
    }
    cout << f[n] << '\n';
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