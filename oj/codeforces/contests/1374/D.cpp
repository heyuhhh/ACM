// Author : heyuhhh
// Created Time : 2020/07/17 13:33:15
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
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    map<int, int> cnt;
    int t = 0, t2 = 0;
    for (int i = 0; i < n; i++) {
        int r = (k - a[i] % k) % k;
        if (r == 0) continue;
        ++cnt[r];
        if (cnt[r] > t) {
            t = cnt[r];
            t2 = r;
        } else if (cnt[r] == t) {
            t2 = max(t2, r);
        }
    }
    --t;
    ll x = 1ll * t * k + t2;
    if (t == -1) x = -1;
    cout << x + 1 << '\n';
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