struct Splay {
    // key: 结点的权值  cnt: 结点的个数  size: 子树大小  sz: 结点总数
    int f[N], ch[N][2], key[N], cnt[N], size[N], sz = 0, root = 0;
    Splay() {sz = root = 0;}
    // 清空结点信息
    inline void clear(int x) {
        ch[x][0] = ch[x][1] = f[x] = key[x] = cnt[x] = size[x] = 0;
    }
    // 判断当前结点是否为左右儿子
    inline int get(int x) {
        return ch[f[x]][1] == x;
    }
    // 更新结点信息
    inline void update(int x) {
        if (!x) return;
        size[x] = cnt[x];
        if (ch[x][0]) size[x] += size[ch[x][0]];
        if (ch[x][1]) size[x] += size[ch[x][1]];
    }
    // 上旋操作
    inline void rot(int x) {
        int old = f[x], oldf = f[old], tp = get(x);
        ch[old][tp] = ch[x][tp ^ 1]; f[ch[old][tp]] = old;
        f[old] = x; ch[x][tp ^ 1] = old;
        f[x] = oldf;
        if (oldf) ch[oldf][ch[oldf][1] == old] = x;
        update(old); update(x);
    }
    // 将结点x伸展到根结点以维持整棵树平衡
    inline void splay(int x) {
        for (int fa; fa = f[x], fa; rot(x))
            if (f[fa]) rot(get(x) == get(fa) ? fa : x);
        root = x;
    }
    // 插入结点并且上旋为根结点
    inline int insert(int v) {
        if (root == 0) {
            ++sz; ch[sz][0] = ch[sz][1] = f[sz] = 0;
            key[sz] = v; cnt[sz] = 1; size[sz] = 1;
            root = sz;
            update(root);
            return 1;
        }
        int tot = root, fa = 0;
        while (1) {
            if (key[tot] == v) {
                cnt[tot]++; update(tot), update(fa);
                splay(tot);
                return cnt[tot];
            }
            fa = tot;
            tot = ch[tot][v > key[tot]];
            if (tot == 0) {
                ++sz; ch[sz][0] = ch[sz][1] = 0;
                key[sz] = v; cnt[sz] = size[sz] = 1;
                f[sz] = fa; ch[fa][v > key[fa]] = sz;
                update(sz); update(fa); splay(sz);
                break;
            }
        }
        return 1;
    }
    // 查找v的排名，即比v小的数的个数+1，并将其伸展为根结点
    inline int rk(int v) {
        int ans = 0, tot = root;
        while (1) {
            if (v < key[tot]) tot = ch[tot][0];
            else {
                ans += (ch[tot][0] ? size[ch[tot][0]] : 0);
                if (v == key[tot]) {
                    splay(tot); return ans + 1;
                }
                ans += cnt[tot];
                tot = ch[tot][1];
            }
        }
        return 0;
    }
    // 查找第k大的值
    inline int kth(int x) {
        int tot = root;
        while (1) {
            if (ch[tot][0] && x <= size[ch[tot][0]]) tot = ch[tot][0];
            else {
                int t = (ch[tot][0] ? size[ch[tot][0]] : 0) + cnt[tot];
                if (x <= t) return key[tot];
                x -= t; tot = ch[tot][1];
            }
        }
        return -1;
    }
    // 返回根节点前驱所在位置
    inline int prev() {
        int tot = ch[root][0];
        while (ch[tot][1]) tot = ch[tot][1];
        return tot;
    }
    // 返回根节点后驱所在位置
    inline int succ() {
        int tot = ch[root][1];
        while (ch[tot][0]) tot = ch[tot][0];
        return tot;
    }
    // 删除一个结点，若有两个儿子则取一个前驱/后继作为根，另一个直接拼上
    inline void del(int v) {
        rk(v);
        if (cnt[root] > 1) {
            --cnt[root]; update(root); return;
        }
        if (!ch[root][0] && !ch[root][1]) {
            clear(root); root = 0; return;
        }
        if (!ch[root][0]) {
            int old = root; root = ch[root][1]; f[root] = 0;
            clear(old); return;
        } else if (!ch[root][1]) {
            int old = root; root = ch[root][0]; f[root] = 0;
            clear(old); return;
        }
        int x = prev(), old = root;
        splay(x); f[ch[old][1]] = x; ch[x][1] = ch[old][1];
        clear(old); update(root);
    }
}tr;

//区间翻转代码：
// 先找到l-1,r+1的位置，然后找到[l,r]对应子树打上标记即可
// 注意标记的下传以及哨兵结点的建立 
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