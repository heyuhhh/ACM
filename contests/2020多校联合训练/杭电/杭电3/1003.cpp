// Author : heyuhhh
// Created Time : 2020/07/29 15:30:54
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

#define FI(x) FastIO::read(x)
#define FO(x) FastIO::write(x)
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

struct BIT {
    int c[N];
    int lowbit(int x) {
        return x & (-x);
    }
    void add(int x, int v) {
        for (; x < N; x += lowbit(x)) {
            c[x] += v;
        }
    }
    int query(int x) {
        int res = 0;
        for (;x > 0; x -= lowbit(x)) {
            res += c[x];
        }
        return res;
    }
    int query(int l, int r) {
        return query(r) - query(l - 1);
    }
}A[2], B[2];

struct node {
    int id, u, val, t;
};

int n;
vector<int> G[N];
vector<node> v[N];
int col[N], val[N];
int in[N], out[N], T;
ll ans[N];

void init() {
    for (int i = 1; i <= n; i++) {
        G[i].clear();
        v[i].clear();
    }
    T = 0;
}

void dfs(int u, int fa) {
    in[u] = ++T;
    for (auto v : G[u]) {
        if (v != fa) {
            dfs(v, u);
        }
    }
    out[u] = T;
}

void work(int color) {
    for (int bit = 0; bit < 20; bit++) {
        for (auto it : v[color]) {
            int u = it.u, id = it.id;
            int b = (it.val >> bit & 1);
            vector<int> num(2);
            num[0] = A[0].query(1, n) - (A[0].query(in[u], out[u]) + B[0].query(in[u]));
            num[1] = A[1].query(1, n) - (A[1].query(in[u], out[u]) + B[1].query(in[u]));
            // dbg(color, bit, num[0], num[1]);
            ans[id] += 1ll * num[b ^ 1] * (1 << bit) * it.t;
            A[b].add(in[u], it.t);
            B[b].add(in[u] + 1, it.t);
            B[b].add(out[u] + 1, -it.t);
        }
    }
}

void run() {
    FI(n);
    init();
    for (int i = 1; i <= n; i++) {
        FI(col[i]);
    }
    for (int i = 1; i <= n; i++) {
        FI(val[i]);
    }
    for (int i = 1; i <= n; i++) {
        v[col[i]].emplace_back(node{0, i, val[i], 1});
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        FI(u), FI(v);
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    dfs(1, 0);
    int q; FI(q);
    for (int i = 1; i <= q; i++) {
        int op, x, y; 
        FI(op), FI(x), FI(y);
        v[col[x]].emplace_back(node{i, x, val[x], -1});
        if (op == 1) {
            val[x] = y;
        } else {
            col[x] = y;
        }
        v[col[x]].emplace_back(node{i, x, val[x], 1});
    }
    for (int i = 1; i <= n; i++) {
        v[col[i]].emplace_back(node{q + 1, i, val[i], -1});
    }
    for (int i = 1; i <= n; i++) {
        work(i);
    }
    for (int i = 1; i <= q; i++) {
        ans[i] += ans[i - 1];
    }
    for (int i = 0; i <= q; i++) {
        FO(ans[i]), FO('\n');
        ans[i] = 0;
    }
}
int main() {
#ifdef Local
    freopen("input.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    int T; FI(T); while(T--)
    run();
    Flush;
    return 0;
}