// Author : heyuhhh
// Created Time : 2020/08/17 09:33:30
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
typedef unsigned int ui;
//head
const int N = 1e5 + 5, MOD = 51061;
struct LCT {
    #define ls ch[x][0]
    #define rs ch[x][1]
    int ch[N][2], fa[N], sum[N], val[N];
    int add[N], mul[N], tag[N], siz[N];
    inline void tagadd(int x, int v) {
        sum[x] = (sum[x] + 1ll * v * siz[x] % MOD) % MOD;
        val[x] = (val[x] + v) % MOD;
        add[x] = (add[x] + v) % MOD;
    }
    inline void tagmul(int x, int v) {
        sum[x] = 1ll * sum[x] * v % MOD;
        val[x] = 1ll * val[x] * v % MOD;
        add[x] = 1ll * add[x] * v % MOD;
        mul[x] = 1ll * mul[x] * v % MOD;
    }
    inline void init(int n) {
        for (int i = 1; i <= n; i++) {
            ch[i][0] = ch[i][1] = 0;
            fa[i] = sum[i] = 0;
            siz[i] = 0;
            add[i] = 0, mul[i] = val[i] = 1;
        }
    }
    // 注意pushup在哪里用，一般是进行上旋操作时用到
    inline void pushup(int x) {
        siz[x] = siz[ls] + siz[rs] + 1;
        sum[x] = (sum[ls] + sum[rs] + val[x]) % MOD;
    }
    inline void pushdown(int x) {
        if (tag[x]) {
            if (ls) swap(ch[ls][0], ch[ls][1]), tag[ls] ^= tag[x];
            if (rs) swap(ch[rs][0], ch[rs][1]), tag[rs] ^= tag[x];
            tag[x] = 0;
        }
        if (mul[x] != 1) {
            if (ls) {
                tagmul(ls, mul[x]);
            }
            if (rs) {
                tagmul(rs, mul[x]);
            }
            mul[x] = 1;
        }
        if (add[x] > 0) {
            if (ls) {
                tagadd(ls, add[x]);
            }
            if (rs) {
                tagadd(rs, add[x]);
            }
            add[x] = 0;
        }
    }
    // 标记要先下传，避免奇奇怪怪的错误
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
    // 与splay类似，多了一个isroot的判断，rotate时会变换父亲
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
    // 核心操作，将x到当前树中的根这条路径上的边全转化为实边，这样x和根节点在一颗splay里面
    // 返回最后得到splay的根节点，如果连用两次，那么就是两个点的lca
    inline int access(int x) {
        int p;
        for (p = 0; x; p = x, x = fa[x]) {
            splay(x); ch[x][1] = p; pushup(x);
        }
        return p;
    }
    // 重要操作，将整棵树的根变为x，实际上就是一段路径的边方向发生翻转，这样才能使得任意一条链都满足深度递增
    inline void makeroot(int x) {
        x = access(x); swap(ls, rs);
        tag[x] ^= 1;
    }
    // 链接两个点，如果已联通则不链接
    inline void link(int x, int y) {
        makeroot(x), splay(x);
        makeroot(y), splay(y);
        if (fa[x] || fa[y]) return; // 如果在一连通块中，那么有个必然不能为根，所以存在父亲
        fa[y] = x;
    }
    // 提取x~y这条链，并且使得y为splay树根
    inline void split(int x, int y) {
        makeroot(x); access(y); splay(y);
    }
    // 切断一条边，注意不存在边的判断
    inline void cut(int x, int y) {
        makeroot(y); access(x); splay(x);
        if (siz[x] != 2 || ls != y) return;
        ls = fa[y] = 0;
    }
    // 寻找x所在连通块的根节点，深度最小那么一直往左子树走即可，最后会使得根节点为splay的树根
    inline int find(int x) {
        access(x), splay(x);
        while (ls) pushdown(x), x = ls;
        splay(x); return x;
    }
    inline int query(int x, int y) {
        makeroot(x); access(y); splay(y);
        return sum[y];
    }
    void update(int x, int y, int op, int v) {
        split(y, x);
        if (op) tagmul(x, v);
        else tagadd(x, v);
    }
}lct;
int n, q;
void run() {
    cin >> n >> q;
    lct.init(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        lct.link(u, v);
    }
    while (q--) {
        string s; cin >> s;
        if (s == "*") {
            int u, v, c;
            cin >> u >> v >> c;
            lct.update(u, v, 1, c);
        } else if (s == "+") {
            int u, v, c;
            cin >> u >> v >> c;
            lct.update(u, v, 0, c);
        } else if (s == "-") {
            int u1, v1, u2, v2;
            cin >> u1 >> v1 >> u2 >> v2;
            lct.cut(u1, v1);
            lct.link(u2, v2);
        } else {
            int u, v;
            cin >> u >> v;
            int res = lct.query(u, v);
            cout << res << '\n';
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