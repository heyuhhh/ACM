// Author : heyuhhh
// Created Time : 2020/09/15 19:23:18
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
const int N = 5e5 + 5;

int n;
int a[N];
int minv[N << 2], cntv[N << 2], lz[N << 2];
void tag(int o, int l, int r, int v) {
    minv[o] += v;
    lz[o] += v;
}

void push_up(int o) {
    minv[o] = min(minv[o << 1], minv[o << 1|1]);
    cntv[o] = 0;
    if (minv[o << 1] == minv[o]) cntv[o] = cntv[o << 1];
    if (minv[o << 1|1] == minv[o]) cntv[o] += cntv[o << 1|1];
}

void push_down(int o, int l, int r) {
    if(lz[o] != 0) {
        int mid = (l + r) >> 1;
        tag(o << 1, l, mid, lz[o]);
        tag(o << 1|1, mid + 1, r, lz[o]);
        lz[o] = 0;   
    }
}

void build(int o, int l, int r) {
    lz[o] = 0;
    if(l == r) {
        minv[o] = 0;
        cntv[o] = 1;
        return;
    }
    int mid = (l + r) >> 1;
    build(o << 1, l, mid), build(o << 1|1, mid + 1, r);
    push_up(o);
}

void update(int o, int l, int r, int L, int R, ll v) {
    if(L <= l && r <= R) {
        tag(o, l, r, v);
        return;
    }   
    push_down(o, l, r);
    int mid = (l + r) >> 1;
    if(L <= mid) update(o << 1, l, mid, L, R, v);
    if(R > mid) update(o << 1|1, mid + 1, r, L, R, v);
    push_up(o);
}

int query(int o, int l, int r, int L, int R) {
    if(L <= l && r <= R) {
        if (minv[o] == 0) return cntv[o];
        return 0;
    }
    push_down(o, l, r);
    int mid = (l + r) >> 1;
    int res = 0;
    if(L <= mid) res = query(o << 1, l, mid, L, R);
    if(R > mid) res += query(o << 1|1, mid + 1, r, L, R);
    return res;
}

void run() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<vector<int>> pos(n + 1);
    build(1, 1, n);

    for (int i = 1; i <= n; i++) {
        pos[i].emplace_back(n + 1);
    }
    auto Add = [&] (int x, int v) {
        int third = pos[a[x]][sz(pos[a[x]]) - 3];
        int fourth = pos[a[x]][sz(pos[a[x]]) - 4];
        update(1, 1, n, third, fourth - 1, v);
    };
    ll ans = 0;
    for (int l = n; l >= 1; l--) {
        if (sz(pos[a[l]]) >= 4) {
            Add(l, 1);
        }
        pos[a[l]].emplace_back(l);
        if (sz(pos[a[l]]) >= 4) {
            Add(l, -1);
        }
        int second = pos[a[l]][sz(pos[a[l]]) - 2];
        update(1, 1, n, l, second - 1, 1);
        ans += query(1, 1, n, l, n);
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