// Author : heyuhhh
// Created Time : 2020/08/18 20:18:00
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
void err(int x) {cerr << x;}
void err(long long x) {cerr << x;}
void err(double x) {cerr << x;}
void err(char x) {cerr << '"' << x << '"';}
void err(const string &x) {cerr << '"' << x << '"';}
void _print() {cerr << "]\n";}
template<typename T, typename V>
  void err(const pair<T, V> &x) {cerr << '{'; err(x.first); cerr << ','; err(x.second); cerr << '}';}
template<typename T>
  void err(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), err(i); cerr << "}";}
template <typename T, typename... V>
  void _print(T t, V... v) {err(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifdef Local
#define dbg(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define dbg(x...)
#endif
//head
const int N = 4e5 + 5;

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

int a[N];
ll all;
int n, q;

struct Splay{
    int f[N], ch[N][2], size[N], rev[N] = {0}, val[N], minv[N], root, sz;
    ll sum[N];
    inline void init() {
        root = sz = size[0] = rev[0] = f[0] = 0; val[0] = minv[0] = INF;
    }
    inline void clear(int x) {
        ch[x][0] = ch[x][1] = f[x] = sum[x] = size[x] = 0; val[x] = minv[x] = INF;
    }    
    inline int newnode(int fa, int d, int v) {
        ++sz;
        ch[sz][0] = ch[sz][1] = 0;
        f[sz] = fa;
        ch[fa][d] = sz;
        val[sz] = v;
        return sz;
    }
    inline int get(int x){return ch[f[x]][1] == x;}
    inline void update(int x){
        size[x] = size[ch[x][0]] + size[ch[x][1]] + 1;
        minv[x] = min(val[x], min(minv[ch[x][0]], minv[ch[x][1]]));
        sum[x] = val[x] + sum[ch[x][0]] + sum[ch[x][1]];
    }
    // 建二叉搜索树
    int build(int l, int r, int rt){
        if (l > r) return 0;
        int m = (l + r) >> 1, tot = ++sz;
        val[tot] = a[m]; f[tot] = rt;
        ch[tot][0] = build(l, m - 1, tot);
        ch[tot][1] = build(m + 1, r, tot);
        update(tot);
        return tot;
    }
    inline void rot(int x){
        int old = f[x], oldf = f[old], tp = get(x);
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
            if (k <= size[ch[tot][0]]) tot = ch[tot][0];
            else {
                k -= size[ch[tot][0]] + 1;
                if (!k) return tot;
                tot = ch[tot][1];
            }
        }
    }
    inline int find(int r, int v) {
        int x = rk(r);
        if (val[x] < v) return r;
        splay(x, 0);
        int y = ch[x][0];
        int res = 0;
        while (y) {
            if (ch[y][1] && minv[ch[y][1]] < v) res += size[ch[y][0]] + 1, y = ch[y][1];
            else if (val[y] < v) return res + size[ch[y][0]] + 1;
            else if (ch[y][0] && minv[ch[y][0]] < v) y = ch[y][0];
            else return 0;
        }
        return 0;
    }
    inline int query(int x) {
        x = rk(x);
        return val[x];
    }
    inline ll queryS(int l, int r) {
        int x = rk(l - 1);
        splay(x, 0);
        if (r == n) return sum[ch[x][1]];
        int y = rk(r + 1);
        splay(y, x);
        return sum[ch[y][0]];
    }
    inline void modify(int p, int v) {
        int x = rk(p);
        val[x] = v;
        update(x);
        splay(x, 0);
    }
    inline void move(int l, int r, int v) {
        // 单独提出l这个位置，直接删除
        int x = rk(l - 1);
        splay(x, 0);
        int y = rk(l + 1);
        splay(y, x);
        clear(ch[y][0]);
        ch[y][0] = 0;
        update(y);
        // 找到应该插的位置，直接插入
        int now = rk(r - 1);
        splay(now, 0);
        if (r == n) {
            ch[now][1] = newnode(now, 1, v);
            update(ch[now][1]);
            splay(sz, 0);
        } else {
            int tmp = rk(r);
            splay(tmp, now);
            ch[tmp][0] = newnode(tmp, 0, v);
            update(ch[tmp][0]);
            splay(sz, 0);
        }
    }
}tr;

void run() {
    all = 0;
    FI(n), FI(q);
    for (int i = 1; i <= n; i++) {
        FI(a[i]);
        all += a[i];
    }
    tr.init();
    tr.root = tr.build(1, n, 0);
    while (q--) {
        int op;
        FI(op);
        if (op == 1) {
            int x, y;
            FI(x), FI(y);
            int L = tr.find(x, y);
            if (L == 0 || L == x) {
                FO(0), FO('\n');
                continue;
            }
            ++L;
            int R = x;
            ll res = tr.queryS(L, R) - 1ll * (R - L + 1) * (y - 1);
            FO(res), FO('\n');

            int h = tr.query(L);
            tr.modify(L - 1, tr.query(L - 1) + h - (y - 1));
            if (L + 1 >= R) tr.modify(L, tr.query(R)), tr.modify(R, y - 1);
            else tr.move(L, R, y - 1);
        } else {
            int x;
            FI(x);
            int ans = tr.query(x);
            FO(ans), FO('\n');
        }
    }
    for (int i = 1; i <= n; i++) {
        FO(tr.query(i));
        if (i != n) FO(' ');
        else FO('\n');
    }
}
int main() {
#ifdef Local
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
#endif
    int T; FI(T); while(T--)
    run();
    Flush;
    return 0;
}