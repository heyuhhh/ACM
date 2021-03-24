//广义后缀自动机，分在线和离线两种算法
//离线需要先构造出trie树，之后直接在trie树上bfs添加结点即可，一般比较麻烦，必须建出显式trie树
//在线算法直接插入即可，注意1：需要调整last，从last开始插入；注意2：要加上SAM中被注释的部分，这就是普通sam和广义sam的区别
//N:结点个数，M:字符集大小，sam需要乘以一个2
//其它操作和普通sam类似
struct SAM {
    const static int MAXNODE = N * 2;
    const static int M = 26;  //
    int go[MAXNODE][M], link[MAXNODE], len[MAXNODE];
    int lc[MAXNODE], lenSorted[MAXNODE], siz[MAXNODE];
    int last, sz, root;

    int newnode() {
        ++sz;
        memset(go[sz], 0, sizeof(go[sz]));
        return sz;
    }

    void init() {
        sz = 0;
        root = last = newnode();
        len[root] = link[root] = 0;
    }

    int split(int p, int q, int ch) {
        int clone = newnode();
        memcpy(go[clone], go[q], sizeof(go[q]));
        link[clone] = link[q];
        link[q] = clone;
        len[clone] = len[p] + 1;
        for (int i = p; i && go[i][ch] == q; i = link[i]) {
            go[i][ch] = clone;
        }
        return clone;
    }

    void insert(int ch) {
        // if (go[last][ch]) {
        //     int q = go[last][ch];
        //     last = len[last] + 1 == len[q] ? q : split(last, q, ch);
        //     siz[last] = 1;
        //     return;
        // }
        // ----
        int cur = newnode();
        len[cur] = len[last] + 1;
        siz[cur] = 1;
        int p = last;
        for (; p && !go[p][ch]; p = link[p]) {
            go[p][ch] = cur;
        }
        if (!p) {
            link[cur] = root;
        } else {
            int q = go[p][ch];
            link[cur] = len[p] + 1 == len[q] ? q : split(p, q, ch);
        }
        last = cur;
    }

    ll solve() {
        ll ans = 0;
        for (int i = root + 1; i <= sz; ++i) {
           ans += len[i] - len[link[i]];
        }
        return ans;
    }
    void sortLen() {
        for (int i = 1; i <= sz; i++) lc[i] = 0;
        for (int i = 1; i <= sz; i++) lc[len[i]]++;
        for (int i = 2; i <= sz; i++) lc[i] += lc[i - 1];
        for (int i = 1; i <= sz; i++) lenSorted[lc[len[i]]--] = i;
    }
    void getSize() {
        sortLen();
        for (int i = sz; i > 0; i--) {
            siz[link[lenSorted[i]]] += siz[lenSorted[i]];
        }
    }    
}sam;
int sam_id[N];
struct Trie {
    int ch[N][M];
    int root, cnt, last;

    int newnode() {
        memset(ch[++cnt], 0, sizeof(ch[cnt]));
        return cnt;
    }

    void init() {
        cnt = 0;
        root = newnode();
    }

    int insert(int last, int x) {
        if (!ch[last][x]) {
            ch[last][x] = newnode();
        }
        return ch[last][x];
    }

    void bfs() {
        int p = root;
        sam.init();
        sam_id[root] = sam.root;
        queue <int> q;
        q.push(p);
        while (!q.empty()) {
            int u = q.front(); 
            q.pop();
            for (int i = 0; i < M; i++) {
                if (ch[u][i]) {
                    sam.last = sam_id[u];
                    sam.insert(i);
                    sam_id[ch[u][i]] = sam.last;
                    q.push(ch[u][i]);
                }
            }
        }
    }
}trie;