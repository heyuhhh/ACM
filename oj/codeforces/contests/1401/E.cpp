// Author : heyuhhh
// Created Time : 2020/08/22 22:51:00
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
const int N = 1e6 + 5;

int c[N];
int lowbit(int x) {
    return x & -x;
}
void add(int x, int v) {
    for (; x < N; x += lowbit(x)) c[x] += v;
}
int query(int x) {
    int res = 0;
    for (; x; x -= lowbit(x)) res += c[x];
    return res;
}
int query(int l, int r) {
    return query(r) - query(l - 1);
}

void run() {
    int n, m;
    cin >> n >> m;
    int ans = 1;

    vector<tuple<int, int, int>> a, b;
    for (int i = 0; i < n; i++) {
        int y, l, r;
        cin >> y >> l >> r;
        if (l == 0 && r == 1000000) ++ans;
        a.emplace_back(l, y, 1);
        a.emplace_back(r + 1, y, -1);
    }
    for (int i = 0; i < m; i++) {
        int x, l, r;
        cin >> x >> l >> r;
        if (l == 0 && r == 1000000) ++ans;
        b.emplace_back(x, l, r);
    }
    sort(all(a));
    sort(all(b));
    int i = 0, x;
    for (auto [x, l, r] : b) {
        while (i < 2 * n && get<0>(a[i]) < x) {
            auto [tt, y, v] = a[i++];
            add(y, v);
        }
        ans += query(l, r);
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