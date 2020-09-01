// Author : heyuhhh
// Created Time : 2020/08/21 15:42:39
#pragma comment(linker, "/STACK:25600000,25600000")
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
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
const int N = 1e5 + 5;

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

struct Edge {
    int v, next;
} e[N << 1];
int head[N], cnt = 1;
void adde(int u, int v) {
    e[cnt].v = v, e[cnt].next = head[u], head[u] = cnt++;
}

int n, m;
int tsz, rt;
int sz[N], Max[N], father[N];
bool vis[N];
void getrt(int u, int fa) {
    sz[u] = 1; Max[u] = 0;
    for (int i = head[u]; i; i = e[i].next) {
        int v = e[i].v;
        if(v == fa || vis[v]) continue;
        getrt(v, u);
        sz[u] += sz[v];
        if(sz[v] > Max[u]) Max[u] = sz[v];
    }
    Max[u] = max(Max[u], tsz - sz[u]);
    if(Max[u] < Max[rt]) rt = u;
}
void findrt(int u, int fa) {
    tsz = (sz[u] == 0 ? n : sz[u]);
    Max[rt = 0] = INF;
    getrt(u, fa);
}
void dfs(int u, int fa) {
    vis[u] = true;
    for (int i = head[u]; i; i = e[i].next) {
        int v = e[i].v;
        if(v != fa && !vis[v]) {
            findrt(v, u);
            father[rt] = u;
            dfs(rt, 0);
        }
    }   
}

int Min[N << 1][20], deep[N];
int lg[N << 1];
int dfn[N], T;
void dfs2(int u, int fa) {
    deep[u] = deep[fa] + 1;
    Min[dfn[u] = ++T][0] = deep[u];
    for (int i = head[u]; i; i = e[i].next) {
        int v = e[i].v;
        if(v != fa) {
            dfs2(v, u);
            Min[++T][0] = deep[u];
        }
    }
}
inline int query(int x, int y) {
    int a = dfn[x], b = dfn[y];
    if (a > b) swap(a, b);
    int k = lg[b - a + 1];
    return min(Min[a][k], Min[b - (1 << k) + 1][k]);
}
 
inline int dis(int x, int y) {
    return deep[x] + deep[y] - 2 * query(x, y);   
} 

// A：全局答案 B：到点分树中各个子树的最大值和次大值 C：点分树子树中各点到当前点的距离
struct ds {
    priority_queue<int> s, del;
    inline void ins(int x) {
        if (x != -1) s.push(x);
    }
    inline void erase(int x) {
        if (x != -1) del.push(x);
    }
    inline int siz() {
        return sz(s) - sz(del);
    }
    inline int Max() {
        if (s.empty()) return -1;
        while (!del.empty() && s.top() == del.top()) s.pop(), del.pop();
        if (s.empty()) return -1;
        return s.top();
    }
    inline int query() {
        int res = Max();
        if (res == -1) return -1;
        s.pop();
        int tmp = Max();
        s.push(res);
        if (tmp == -1) return -1;
        res += tmp;
        return res;
    }
} A, B[N], C[N];

bool sta[N];

inline void off(int u, int v) {
    if (u == v) {
        B[u].ins(0);
        if (B[u].siz() == 2) {
            A.ins(B[u].Max());
        }
    }
    while (father[u]) {
        int fa = father[u], d = dis(fa, v), pre = C[u].Max();
        C[u].ins(d);
        if (!fa) return;
        if (d > pre) {
            int maxv = B[fa].query();
            B[fa].erase(pre);
            B[fa].ins(d);
            A.erase(maxv);
            A.ins(B[fa].query());
        }
        u = fa;
    }
}

inline void on(int u, int v) {
    if (u == v) {
        B[u].erase(0);
        if (B[u].siz() == 1) {
            A.erase(B[u].Max());
        }
    }
    if (!father[u]) return;
    while (father[u]) {
        int fa = father[u], d = dis(fa, v), pre = C[u].Max();
        C[u].erase(d);
        if (d == pre) {
            int maxv = B[fa].query();
            B[fa].erase(d);
            B[fa].ins(C[u].Max());
            A.erase(maxv);
            A.ins(B[fa].query());
        }
        u = fa;
    }
}

void run() {
    FI(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        FI(u), FI(v);
        adde(u, v), adde(v, u);
    }
    dfs2(1, 0);
    lg[2] = 1;
    for (int i = 3; i <= T; i++) {
        lg[i] = lg[i >> 1] + 1;
    }
    for (int j = 1; j < 20; j++) {
        for (int i = 1; i <= T; i++) {
            if (i + (1 << (j - 1)) <= T) {
                Min[i][j] = min(Min[i][j - 1], Min[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    findrt(1, 0);
    dfs(1, 0);
    int tot = 0;
    for (int i = 1; i <= n; i++) {
        off(i, i);
        ++tot;
    }
    int q;
    FI(q);
    int lastans = -1;
    char last = 'D';
    while (q--) {
        static char s[2];
        FI(s);
        if (s[0] == 'C') {
            int x; FI(x);
            if (sta[x] == 0) {
                on(x, x);
                --tot;
            } else {
                off(x, x);
                ++tot;
            }
            sta[x] ^= 1;
        } else {
            if (last != 'G') {
                if (tot <= 1) lastans = tot - 1;
                else lastans = A.Max();
            }
            FO(lastans);
            FO('\n');
        }
        last = s[0];
    }

}
int main() {
#ifdef Local
    freopen("input.in", "r", stdin);
#endif
    run();
    Flush;
    return 0;
}