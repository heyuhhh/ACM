// Author : heyuhhh
// Created Time : 2020/09/17 11:09:18
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
const int N = 2e5 + 5;

struct segm {
    int l, r, t;
    bool operator < (const segm& A) const {
        if (r != A.r) return r < A.r;
        return l < A.l;
    }
};

void run() {
    int n;
    cin >> n;
    vector<segm> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].l >> a[i].r >> a[i].t;
        --a[i].t;
    }
    sort(all(a));
    vector<multiset<pii>> s(2);
    int mm = 0;
    for (int i = 0; i < n; i++) {
        int l = a[i].l, r = a[i].r, t = a[i].t;
        auto p = s[t ^ 1].lower_bound(MP(l, 0));
        if (p != s[t ^ 1].end()) {
            ++mm;
            s[t ^ 1].erase(p);
        } else {
            s[t].emplace(r, l);
        }
    }
    int ans = n - mm;
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