#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
const int N = 1e5 + 5;

int a[N];
struct Splay{
    int f[N], ch[N][2], size[N], rev[N] = {0}, key[N], root, sz;
    Splay(){
        root = sz = size[0] = rev[0] = f[0] = 0; key[0] = INF;
    }
    inline int get(int x){return ch[f[x]][1] == x;}
    inline void update(int x){
        size[x] = size[ch[x][0]] + size[ch[x][1]] + 1;
    }
    inline void pushdown(int x){
        if (!rev[x]) return;
        swap(ch[x][0], ch[x][1]);
        rev[ch[x][0]] ^= 1; rev[ch[x][1]] ^= 1; rev[x] = 0;
    }
    // 建二叉搜索树
    inline int build(int l, int r, int rt){
        if (l > r) return 0;
        int m = (l + r) >> 1, tot = ++sz;
        key[tot] = a[m]; f[tot] = rt; rev[tot] = 0;
        ch[tot][0] = build(l, m - 1, tot);
        ch[tot][1] = build(m + 1, r, tot);
        update(tot);
        return tot;
    }
    inline void rot(int x){
        int old = f[x], oldf = f[old], tp = get(x);
        pushdown(old); pushdown(x); // 注意这里的区别
        ch[old][tp] = ch[x][tp ^ 1]; f[ch[old][tp]] = old;
        ch[x][tp ^ 1] = old; f[old] = x; 
        f[x] = oldf;
        if (oldf) ch[oldf][ch[oldf][1] == old] = x;
        update(old); update(x);
    }
    inline void splay(int x, int tar){ // 旋转到对应位置
        for (int fa; (fa = f[x]) != tar; rot(x))
            if (f[fa] != tar)
                rot(get(fa) == get(x) ? fa : x);
        if (!tar) root = x;
    }
    inline int rk(int k){
        int tot = root;
        while (1){
            pushdown(tot); // !!
            if (k <= size[ch[tot][0]]) tot = ch[tot][0];
            else {
                k -= size[ch[tot][0]] + 1;
                if (!k) return tot;
                tot = ch[tot][1];
            }
        }
    }
    inline void reverse(int l, int r){
        int a = rk(l), b = rk(r + 2); // 找到对应位置
        splay(a, 0); splay(b, a); // 分别旋转至对应位置
        rev[ch[b][0]] ^= 1; // 打上翻转标记
    }
    void print(int p){
        pushdown(p);
        if (ch[p][0]) print(ch[p][0]);
        if (key[p] != INF && key[p] > 0) printf("%d ", key[p]);
        if (ch[p][1]) print(ch[p][1]);
    }
}tr;

int n, m;
void run() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        a[i + 1] = i;
    }
    a[1] = 0, a[n + 2] = INF;
    tr.root = tr.build(1, n + 2, 0);
    while (m--) {
        int l, r;
        cin >> l >> r;
        tr.reverse(l, r);
    }
    tr.print(tr.root);
}
int main() {
    run();
    return 0;
}