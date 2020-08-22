// Author : heyuhhh
// Created Time : 2020/07/27 13:24:29
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
const int N = 5e5 + 5;
const int P[] = {998244353};

#define ull unsigned long long
#define rep(ii,a,b) for(int ii=a;ii<=b;++ii)
#define forn(i, n) for(int i = 0; i < n; ++i)
#define for1(i, n) for(int i = 1; i <= n; ++i)
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

const int maxsz = 3e5 + 7;//@maxsz素数表@
//1e7+19,2e7+3,3e7+23,4e5+9 @maxsz最好为素数@
//1e6+3,2e6+3,3e6+7,4e6+9,1e5+3,2e5+3,3e5+7
//@要保证取值的操作值集合小于maxsz,@
//@count操作不增加新节点@
template<typename key,typename val>
class hash_map{public:
  struct node{key u;val v;int next;};
  vector<node> e;
  int head[maxsz],nume,numk,id[maxsz];
  bool count(key u){
    int hs=(u%maxsz + maxsz) % maxsz;
    for(int i=head[hs];i;i=e[i].next)
      if(e[i].u==u) return 1;
    return 0;
  }
  val& operator[](key u){
    int hs=(u%maxsz + maxsz) % maxsz;
    for(int i=head[hs];i;i=e[i].next)
      if(e[i].u==u) return e[i].v;
    if(!head[hs])id[++numk]=hs;
    if(++nume>=e.size())e.resize(nume<<1);
    return e[nume]=(node){u,0,head[hs]},head[hs]=nume,e[nume].v;
  }
  void clear(){
    rep(i,0,numk)head[id[i]]=0;
    numk=nume=0;
  }
};
hash_map<int, int> mp;

int qpow(ll a, ll b, int op) {
    int MOD = P[op];
    ll res = 1;
    while(b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

void add(int& a, int b, int op) {
    a += b;
    if (a >= P[op]) a -= P[op];
}

int n, k;
int a[N];
int val[N][1], chkv[1], sum[N][1], vpow[N][1];

void init() {
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < 1; j++) {
            vpow[i][j] = qpow(i, P[j], j);
        }
    }
}

void run() {
    FI(n), FI(k);
    for (int i = 1; i <= n; i++) {
        FI(a[i]);
    }
    int lb = -1, rb = -1;
    mp.clear();
    for (int i = 1; i <= n; i++) {
        if (mp.count(a[i]) == 0) {
            ++mp[a[i]];
        } else {
            lb = i;
            break;
        }
    }
    mp.clear();
    for (int i = n; i >= 1; i--) {
        if (mp.count(a[i]) == 0) {
            ++mp[a[i]];
        } else {
            rb = i;
            break;
        }
    }
    if (k > n) {
        if (lb == -1) {
            puts("YES");
        } else {
            if (rb >= lb) {
                puts("NO");
            } else {
                puts("YES");
            }
        }
        return;
    }

    for (int j = 0; j < 1; j++) {
        int tmp = 0;
        for (int i = 1; i <= k; i++) {
            add(tmp, vpow[i][j], j);
        }
        chkv[j] = tmp;
        for (int i = 1; i <= n; i++) {
            val[i][j] = vpow[a[i]][j];
            sum[i][j] = (sum[i - 1][j] + val[i][j]) % P[j];
        }
    }

    auto query = [&](int l, int r, int op) {
        return (sum[r][op] - sum[l - 1][op] + P[op]) % P[op];
    };
    for (int l = 1; l <= k; l++) {
        int i;
        bool flag = true;
        for (i = l; i + k - 1 <= n; i += k) {
            bool ok = true;
            for (int j = 0; j < 1; j++) {
                if (query(i, i + k - 1, j) != chkv[j]) {
                    ok = false;
                    break;
                }
            }
            if (!ok) {
                flag = false;
                break;
            }
        }
        if (flag) {
            if (lb == -1 || (lb >= l && rb <= i)) {
                puts("YES");
                return;
            }
        }
    }
    puts("NO");
}
int main() {
#ifdef Local
    freopen("input.in", "r", stdin);
#endif
    init();
    int T; FI(T); while(T--)
    run();
    Flush;
    return 0;
}