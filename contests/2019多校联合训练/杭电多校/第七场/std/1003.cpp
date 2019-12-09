#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define FOR(i, x, y) for (decay<decltype(y)>::type i = (x), _##i = (y); i < _##i; ++i)
#define FORD(i, x, y) for (decay<decltype(x)>::type i = (x), _##i = (y); i > _##i; --i)
#ifdef zerol
#define dbg(args...) do { cout << "\033[32;1m" << #args << " -> "; err(args); } while (0)
#else
#define dbg(...)
#endif
void err() { cout << "\033[39;0m" << endl; }
template<template<typename...> class T, typename t, typename... Args>
void err(T<t> a, Args... args) { for (auto x: a) cout << x << ' '; err(args...); }
template<typename T, typename... Args>
void err(T a, Args... args) { cout << a << ' '; err(args...); }
// -----------------------------------------------------------------------------
const int N = 1E5 + 100;
 
namespace tree {
#define mid ((l + r) >> 1)
#define lson l, mid
#define rson mid + 1, r
    const int MAGIC = N * 20 * 18;
    struct P {
        int w, ls, rs;
    } tr[MAGIC];
    int sz = 1;
    int _new(int w, int ls, int rs) {
        tr[sz] = {w, ls, rs};
        assert(sz != MAGIC);
        return sz++;
    }
    int ins(int tt, int x, int v, int l = -1, int r = N) {
        if (x < l || r < x) return tt;
        const P& t = tr[tt];
        if (l == r) return _new(t.w + v, 0, 0);
        return _new(t.w + v, ins(t.ls, x, v, lson), ins(t.rs, x, v, rson));
    }
    int query(int tt, int k, int l = -1, int r = N) {
        if (l == r) return l;
        const P& t = tr[tt];
        int w = tr[t.rs].w;
        if (k <= w) return query(t.rs, k, rson);
        else return query(t.ls, k - w, lson);
    }
};
 
char s[N];
namespace sam {
    const int M = 2 * N;
    vector<int> G[M];
    int t[M][26], len[M] = {-1}, fa[M], sz = 2, last = 1, one[M], pos[M], ed[M];
    void ins(int ch, int pp) {
        int p = last, np = last = sz++; ed[np] = pp + 1;
        len[np] = len[p] + 1; one[np] = pos[np] = pp;
        for (; p && !t[p][ch]; p = fa[p]) t[p][ch] = np;
        if (!p) { fa[np] = 1; return; }
        int q = t[p][ch];
        if (len[q] == len[p] + 1) fa[np] = q;
        else {
            int nq = sz++; len[nq] = len[p] + 1; one[nq] = one[q];
            memcpy(t[nq], t[q], sizeof t[0]);
            fa[nq] = fa[q];
            fa[q] = fa[np] = nq;
            for (; p && t[p][ch] == q; p = fa[p]) t[p][ch] = nq;
        }
    }
 
    int up[M], c[256] = {2}, a[M];
    void rsort2() {
        FOR (i, 1, 256) c[i] = 0;
        FOR (i, 2, sz) up[i] = s[one[i] + len[fa[i]]];
        FOR (i, 2, sz) c[up[i]]++;
        FOR (i, 1, 256) c[i] += c[i - 1];
        FOR (i, 2, sz) a[--c[up[i]]] = i;
        FOR (i, 2, sz) G[fa[a[i]]].push_back(a[i]);
    }
}
using namespace sam;
set<int> e[M];
int d[M];
 
void s_ins(set<int>& e, int& d, int x) {
    auto it = e.insert(x).first, l = it, r = it;
    if (e.size() == 1) return;
    if (l != e.begin() && r != --e.end()) {
        int ll = *--l, rr = *++r;
        d = tree::ins(d, rr - ll, -1);
        d = tree::ins(d, x - ll, 1); d = tree::ins(d, rr - x, 1);
    } else {
        if (it != e.begin()) d = tree::ins(d, x - *--l, 1);
        else d = tree::ins(d, *++r - x, 1);
    }
}
 
int K, ok[M];
void dfs(int u, int f) {
    for (int& v: G[u]) dfs(v, u);
    if (f == -1) return;
    if (ed[u]) s_ins(e[u], d[u], ed[u]);
    int l = tree::query(d[u], K + 1), r = tree::query(d[u], K);
    l = max(l, len[fa[u]] + 1); r = min(r - 1, len[u]);
    if (l <= r) ok[u] = l;
    if (e[f].size() < e[u].size()) {
        swap(e[f], e[u]); swap(d[f], d[u]);
    }
    for (auto& x: e[u]) s_ins(e[f], d[f], x);
}
 
bool go(int u) {
    if (ok[u]) {
        FOR (i, one[u], one[u] + ok[u]) putchar(s[i]);
        return true;
    }
    for (int &v: G[u]) if (go(v)) return true;
    return false;
}
 
void init();
int main() {
//  visit https://github.com/zerolfx/template for more templates
#ifdef zerol
    freopen("in", "r", stdin);
#endif
    int T; cin >> T;
    while (T--) {
        init();
        scanf("%s", s);
        cin >> K; --K;
        FORD (i, (int)strlen(s) - 1, -1) ins(s[i] - 'a', i);
        rsort2();
        dfs(1, -1);
        puts(go(1) ? "" : "-1");
    }
}
 
void init() {
    memset(t, 0, (sz + 10) * sizeof t[0]);
    fill(ed, ed + (sz + 10), 0);
    fill(ok, ok + (sz + 10), 0);
    FOR (i, 0, sz + 10) { e[i].clear(); d[i] = 0; G[i].clear(); }
    sz = 2;
    last = 1;
    tree::sz = 1;
}