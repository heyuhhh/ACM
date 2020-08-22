// Author : heyuhhh
// Created Time : 2020/07/22 10:47:45
#pragma GCC optimize(2)
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

int n, m;
int a[N];
vector<int> G[N], bG[N];
int bsz;
struct Block {
    int Bnum, E, V;
    vector<int> Bcnt;
    vector<int> Bbel;
    vector<int> Bres;
    vector<pii> Bdiv;

    void init(int x) {
        V = sz(G[x]) + 1;
        E = sqrt(V + 0.5);
        Bnum = 0;
        Bcnt.assign(V + 1, 0);
        Bbel.assign(V + 1, -1);
        Bdiv.clear();
        Bres.clear();
        for (int i = 0; i <= V; i += E, ++Bnum) {
            for (int j = i; j <= min(V, i + E - 1); j++) {
                Bbel[j] = Bnum;
            }
            Bdiv.emplace_back(i, min(i + E - 1, V));
            Bres.push_back(0);
        }
    }

    void add(int x) {
        if (x > V) return;
        ++Bcnt[x];
        if (Bcnt[x] == 1) {
            ++Bres[Bbel[x]];
        }
    }

    void del(int x) {
        if (x > V) return;
        --Bcnt[x];
        if (Bcnt[x] == 0) {
            --Bres[Bbel[x]];
        }
    }

    int query() {
        for (int i = 0; i < Bnum; i++) {
            if (Bdiv[i].se - Bdiv[i].fi + 1 != Bres[i]) {
                for (int j = Bdiv[i].fi; j <= Bdiv[i].se; j++) {
                    if (!Bcnt[j]) {
                        return j;
                    }
                }
            }
        }
    }
}blk[N];

void run() {
    FI(n), FI(m);
    bsz = sqrt(m + 0.5);
    for (int i = 1; i <= n; i++) {
        FI(a[i]);
        G[i].clear();
        bG[i].clear();
    }
    for (int i = 1; i <= m; i++) {
        int u, v;
        FI(u), FI(v);
        G[u].push_back(v);
        G[v].push_back(u);
    }

    for (int i = 1; i <= n; i++) {
        blk[i].init(i);
    }

    for (int i = 1; i <= n; i++) {
        for (auto j : G[i]) {
            if (sz(G[j]) > bsz) {
                bG[i].push_back(j);
            }
            if (sz(G[i]) <= bsz) {
                blk[j].add(a[i]);
            }
        }
    }
    
    int q;
    FI(q);
    while (q--) {
        int op;
        FI(op);
        if (op == 1) {
            int u, x;
            FI(u), FI(x);
            if (sz(G[u]) <= bsz) {
                for (auto v : G[u]) {
                    blk[v].del(a[u]);
                    blk[v].add(x);
                }
            }
            a[u] = x;
        } else {
            int u;
            FI(u);
            for (auto v : bG[u]) {
                blk[u].add(a[v]);
            }
            int ans = blk[u].query();
            FO(ans), FO('\n');
            for (auto v : bG[u]) {
                blk[u].del(a[v]);
            }
        }
    }
}
int main() {
#ifdef Local
    freopen("input.in", "r", stdin);
#endif
    int T; FI(T); while(T--)
    run();
    Flush;
    return 0;
}