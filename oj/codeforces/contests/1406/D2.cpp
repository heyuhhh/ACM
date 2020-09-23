// Author : heyuhhh
// Created Time : 2020/09/13 09:42:29
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
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<ll> d(n);
    ll sum = 0;
    for (int i = 1; i < n; i++) {
        d[i] = a[i] - a[i - 1];
        if (d[i] >= 0) 
            sum += d[i];
    }
    auto get = [&] () {
        ll res = sum + a[0];
        if (res > 0)
            return (res + 1) / 2;
        return res / 2;
    };
    auto add = [&] (int p, int v) {
        if (d[p] > 0) sum -= d[p];
        d[p] += v;
        if (d[p] > 0) sum += d[p];
    };
    cout << get() << '\n';
    int q;
    cin >> q;
    while (q--) {
        int l, r, x;
        cin >> l >> r >> x;
        --l, --r;
        if (l)
            add(l, x);
        else 
            a[0] += x;
        if (r + 1 < n) 
            add(r + 1, -x);
        cout << get() << '\n';
    }
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