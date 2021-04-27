// Author : heyuhhh
// Created Time : 2021/03/24 12:55:12
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
const int N = 3e5 + 5;

struct Fenwick_tree {
    ll c[N];
    int lowbit(int x) {
        return x & (-x);
    }
    void add(int x, int v) {
        for (; x < N; x += lowbit(x)) {
            c[x] += v;
        }
    }
    ll query(int x) {
        ll res = 0;
        for (; x; x -= lowbit(x)) {
            res += c[x];
        }
        return res;
    }
    int kth(int k) {
        int l = 1, r = N, mid;
        while (l < r) {
            mid = (l + r) >> 1;
            if (query(mid) > k) r = mid;
            else l = mid + 1;
        }
        return l - 1;
    }
} A, B;

int n, k;
struct Edge {
    int u, v, w;
    bool operator < (const Edge& A) const {
        return w < A.w;
    }
} e[N];

int f[N];
int find(int x) {
    return f[x] == x ? f[x] : f[x] = find(f[x]);
}

void run() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        f[i] = i;
    }
    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        e[i] = Edge{u, v, w};
    }
    sort(e + 1, e + n);
    for (int i = 1; i <= n; i++) {
        A.add(i, 1);
    }
    for (int i = 1; i < n; i++) {
        int u = e[i].u, v = e[i].v, w = e[i].w;
        u = find(u), v = find(v);
        if (u < v) swap(u, v);
        f[u] = v;
        A.add(u, -1);
        int l = u, r = A.kth(k);
        if (l <= r) {
            B.add(l, w);
            B.add(r + 1, -w);
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << B.query(i) << '\n';
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