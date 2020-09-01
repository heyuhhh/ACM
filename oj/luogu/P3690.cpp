// Author : heyuhhh
// Created Time : 2020/08/16 15:19:52
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
const int N = 1e5 + 5, M = 3e5 + 5;
struct LCT {
    #define ls ch[x][0]
    #define rs ch[x][1]
    int ch[N][2], fa[N], sum[N], val[N];
    int tag[N], siz[N];
    inline void init(int n) {
        for (int i = 1; i <= n; i++) {
            ch[i][0] = ch[i][1] = 0;
            fa[i] = sum[i] = val[i] = 0;
            tag[i] = siz[i] = 0;
        }
    }
    inline void pushup(int x) {
        siz[x] = siz[ls] + siz[rs] + 1;
        sum[x] = sum[ls] ^ sum[rs] ^ val[x];
    }
    inline void pushdown(int x) {
        if (tag[x]) {
            if (ls) swap(ch[ls][0], ch[ls][1]), tag[ls] ^= tag[x];
            if (rs) swap(ch[rs][0], ch[rs][1]), tag[rs] ^= tag[x];
            tag[x] = 0;
        }
    }
    void update(int x) {
        if (!isroot(x)) update(fa[x]);
        pushdown(x);
    }
    inline int get(int x) {
        return x == ch[fa[x]][1];
    }
    inline bool isroot(int x) {
        return ch[fa[x]][0] != x && ch[fa[x]][1] != x;
    }
    inline void rotate(int x) {
        int y = fa[x], z = fa[y], k = get(x);
        if (!isroot(y)) ch[z][ch[z][1] == y] = x;
        ch[y][k] = ch[x][k ^ 1]; fa[ch[y][k]] = y;
        ch[x][k ^ 1] = y; fa[y] = x; fa[x] = z;
        pushup(y), pushup(x);
    }
    inline void splay(int x) {
        update(x);
        for (int f = fa[x]; !isroot(x); f = fa[x]) {
            if (!isroot(f)) rotate(get(f) == get(x) ? f : x);
            rotate(x);
        }
    }
    inline int access(int x) {
        int p;
        for (p = 0; x; p = x, x = fa[x]) {
            splay(x); ch[x][1] = p; pushup(x);
        }
        return p;
    }
    inline void makeroot(int x) {
        x = access(x); swap(ls, rs);
        tag[x] ^= 1;
    }
    inline void link(int x, int y) {
        makeroot(x), splay(x);
        makeroot(y), splay(y);
        if (fa[x] || fa[y]) return;
        fa[y] = x;
    }
    inline void split(int x, int y) {
        makeroot(x); access(y); splay(y);
    }
    inline void cut(int x, int y) {
        makeroot(y); access(x); splay(x);
        if (siz[x] != 2 || ls != y) return;
        ls = fa[y] = 0;
    }
    inline int find(int x) {
        access(x), splay(x);
        while (ls) pushdown(x), x = ls;
        splay(x); return x;
    }
    inline void modify(int x, int v) {
        splay(x); val[x] = v; pushup(x);
    }
    inline int query(int x, int y) {
        makeroot(x); access(y); splay(y);
        return sum[y];
    }
}lct;

int n, m;
int a[N];

void run() {
    cin >> n >> m;
    lct.init(n);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        lct.modify(i, a[i]);
    }
    while (m--) {
        int op, x, y;
        cin >> op >> x >> y;
        if (op == 0) {
            lct.split(x, y);
            cout << lct.sum[y] << '\n';
        } else if (op == 1) {
            lct.link(x, y);
        } else if (op == 2) { 
            lct.cut(x, y);
        } else {
            lct.modify(x, y);
        }
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