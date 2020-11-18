<<<<<<< HEAD
// 每个结点由二元组(k,w)组成，k满足二叉搜索树的性质，w满足堆的性质
// 构建的过程中用栈来维护，有点像单调栈？
=======
>>>>>>> 69e9080b9001e454b6fc968183fcfd8a9df062de
pii b[N];
struct Cartesian_Tree{
    struct node{
        int id, val, fa;
        int son[2];
        node(){}
        node(int id, int val, int fa) : id(id), val(val), fa(fa) {
            son[0] = son[1] = 0;
        }
    }tr[N];
    int rt;
    void init() {
        tr[0] = node(0, 1e9, 0);
    }
    void build(int n, int *a) {
        for(int i = 1; i <= n; i++) tr[i] = (i, a[i], 0);
        for(int i = 1; i <= n; i++) {
            int k = i - 1;
            while(tr[k].val < tr[i].val) k = tr[k].fa;
            tr[i].son[0] = tr[k].son[1];
            tr[k].son[1] = i;
            tr[i].fa = k;
            tr[tr[i].son[0]].fa = i;
        }
        rt = tr[0].son[1];
    }
    int dfs(int u) {
        if(!u) return 0;
        int lsz = dfs(tr[u].son[0]);
        int rsz = dfs(tr[u].son[1]);
        b[tr[u].id].fi = lsz;
        b[tr[u].id].se = rsz;
        return lsz + rsz + 1;
    }
}CT; 
