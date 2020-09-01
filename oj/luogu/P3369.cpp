// Author : heyuhhh
// Created Time : 2020/08/15 09:44:46
// #pragma GCC optimize(2)
// #pragma GCC optimize(3, "Ofast", "inline")
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
const int N = 1e6 + 1e5 + 5;
#define FI(n) FastIO::read(n)
#define FO(n) FastIO::write(n)
#define Flush FastIO::Fflush()
namespace FastIO {
	const int SIZE = 1 << 16;
	char buf[SIZE], obuf[SIZE], str[60];
	int bi = SIZE, bn = SIZE, opt;
	double D[] = {0.1, 0.01, 0.001, 0.0001, 0.00001, 0.000001, 0.0000001, 0.00000001, 0.000000001, 0.0000000001};
	int read(char *s) {
		while (bn) {
			for (; bi < bn && buf[bi] <= ' '; bi++);
			if (bi < bn) break;
			bn = fread(buf, 1, SIZE, stdin);
			bi = 0;
		}
		int sn = 0;
		while (bn) {
			for (; bi < bn && buf[bi] > ' '; bi++) s[sn++] = buf[bi];
			if (bi < bn) break;
			bn = fread(buf, 1, SIZE, stdin);
			bi = 0;
		}
		s[sn] = 0;
		return sn;
	}
	bool read(int& x) {
		int n = read(str), bf = 0;
		if (!n) return 0;
		int i = 0; if (str[i] == '-') bf = 1, i++; else if (str[i] == '+') i++;
		for (x = 0; i < n; i++) x = x * 10 + str[i] - '0';
		if (bf) x = -x;
		return 1;
	}
	bool read(long long& x) {
		int n = read(str), bf;
		if (!n) return 0;
		int i = 0; if (str[i] == '-') bf = -1, i++; else bf = 1;
		for (x = 0; i < n; i++) x = x * 10 + str[i] - '0';
		if (bf < 0) x = -x;
		return 1;
	}
	void write(int x) {
		if (x == 0) obuf[opt++] = '0';
		else {
			if (x < 0) obuf[opt++] = '-', x = -x;
			int sn = 0;
			while (x) str[sn++] = x % 10 + '0', x /= 10;
			for (int i = sn - 1; i >= 0; i--) obuf[opt++] = str[i];
		}
		if (opt >= (SIZE >> 1)) {
			fwrite(obuf, 1, opt, stdout);
			opt = 0;
		}
	}
	void write(long long x) {
		if (x == 0) obuf[opt++] = '0';
		else {
			if (x < 0) obuf[opt++] = '-', x = -x;
			int sn = 0;
			while (x) str[sn++] = x % 10 + '0', x /= 10;
			for (int i = sn - 1; i >= 0; i--) obuf[opt++] = str[i];
		}
		if (opt >= (SIZE >> 1)) {
			fwrite(obuf, 1, opt, stdout);
			opt = 0;
		}
	}
	void write(unsigned long long x) {
		if (x == 0) obuf[opt++] = '0';
		else {
			int sn = 0;
			while (x) str[sn++] = x % 10 + '0', x /= 10;
			for (int i = sn - 1; i >= 0; i--) obuf[opt++] = str[i];
		}
		if (opt >= (SIZE >> 1)) {
			fwrite(obuf, 1, opt, stdout);
			opt = 0;
		}
	}
	void write(char x) {
		obuf[opt++] = x;
		if (opt >= (SIZE >> 1)) {
			fwrite(obuf, 1, opt, stdout);
			opt = 0;
		}
	}
	void Fflush() { if (opt) fwrite(obuf, 1, opt, stdout); opt = 0;}
};
struct Splay {
    int f[N], ch[N][2], key[N], cnt[N], size[N], sz = 0, root = 0;
    Splay() {sz = root = 0;}
    // 删除结点
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

void run() {
    int n, m;
    FI(n), FI(m);
    for (int i = 0; i < n; i++) {
        int x;
        FI(x);
        tr.insert(x);
    }
    int res = 0, last = 0;
    for (int _ = 0; _ < m; _++) {
        int op, x;
        FI(op), FI(x);
        x ^= last;
        if (op == 1) {
            tr.insert(x);
        }
        if (op == 2) {
            tr.del(x);
        }
        if (op == 3) {
            tr.insert(x);
            int ans = tr.rk(x);
            tr.del(x);
            last = ans;
            res ^= ans;
        }
        if (op == 4) {
            int ans = tr.kth(x);
            last = ans;
            res ^= ans;
        }
        if (op == 5) {
            tr.insert(x);
            int ans = tr.key[tr.prev()];
            last = ans;
            res ^= ans;
            tr.del(x);
        }
        if (op == 6) {
            tr.insert(x);
            int ans = tr.key[tr.succ()];
            last = ans;
            res ^= ans;
            tr.del(x);
        }
    }
    FO(res);
}

int main() {
#ifdef Local
    freopen("input.in", "r", stdin);
#endif
    run();
    Flush;
    return 0;
}