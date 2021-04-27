#include <bits/stdc++.h>
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
using namespace std;
const int N = 1e5 + 5, M = 2e6 + 5;
typedef long long ll;

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

int n;
int a[N];

int head[N], tot, val[N << 1], nxt[N << 1];

inline void adde(int u, int v) {
    val[tot] = v, nxt[tot] = head[u], head[u] = tot++;
}

ll ans;

int cnt[M][2];

int siz[N], bson[N];

void dfs(int u, int fa) {
    siz[u] = 1;
    int Max = 0;
    for (register int i = head[u]; i != -1; i = nxt[i]) {
        int v = val[i];
        if (v == fa) continue;
        dfs(v, u);
        siz[u] += siz[v];
        if (siz[v] > Max) {
            Max = siz[v];
            bson[u] = v;
        }
    }
}

int son, now;

void calc(int u, int fa, int bit, int op) {
    int b = (u >> bit & 1);
    if (op == 0) {
        ans += 1ll * cnt[now ^ a[u]][b ^ 1] * (1 << bit);
    } 
    cnt[a[u]][b] += op;
    for (register int i = head[u]; i != -1; i = nxt[i]) {
        int v = val[i];
        if (v == fa) continue;
        if (v != son) {
            calc(v, u, bit, op);
        }
    }
}

template<int bit>
void solve(int u, int fa, int op) {
    for (register int i = head[u]; i != -1; i = nxt[i]) {
        int v = val[i];
        if (v == fa) continue;
        if (v != bson[u]) {
            solve<bit>(v, u, 1);
        }
    }
    if (bson[u]) solve<bit>(bson[u], u, 0);
    son = bson[u];
    now = a[u];
    ++cnt[a[u]][u >> bit & 1];
    for (register int i = head[u]; i != -1; i = nxt[i]) {
        int v = val[i];
        if (v == fa) continue;
        if (v != son) {
            calc(v, u, bit, 0);
            calc(v, u, bit, 1);
        }
    }
    
    son = 0;
    if (op) {
        --cnt[a[u]][u >> bit & 1];
        for (register int i = head[u]; i != -1; i = nxt[i]) {
            int v = val[i];
            if (v == fa) continue;
            if (v != son) {
                calc(v, u, bit, -1);
            }
        }
    }
}

inline void run() {
    FI(n);
    for (register int i = 1; i <= n; ++i) {
        FI(a[i]);
        head[i] = -1;
    }
    for (register int i = 1; i < n; ++i) {
        int u, v;
        FI(u), FI(v);
        adde(u, v);
        adde(v, u);
    }
    dfs(1, 0);
    solve<0>(1, 0, 1);
    solve<1>(1, 0, 1);
    solve<2>(1, 0, 1);
    solve<3>(1, 0, 1);
    solve<4>(1, 0, 1);
    solve<5>(1, 0, 1);
    solve<6>(1, 0, 1);
    solve<7>(1, 0, 1);
    solve<8>(1, 0, 1);
    solve<9>(1, 0, 1);
    solve<10>(1, 0, 1);
    solve<11>(1, 0, 1);
    solve<12>(1, 0, 1);
    solve<13>(1, 0, 1);
    solve<14>(1, 0, 1);
    solve<15>(1, 0, 1);
    solve<16>(1, 0, 0);
    FO(ans), FO('\n');
}

int main() {
#ifdef Local
    freopen("input.in", "r", stdin);
#endif
    run();
    Flush;
    return 0;
}