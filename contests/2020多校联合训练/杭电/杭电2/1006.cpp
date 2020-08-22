// Author : heyuhhh
// Created Time : 2020/07/23 16:24:33
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
const int N = 2e6 + 5;
const int p[3] = {998244353, 100000259, 10001093};

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

int fib[N][3];

void init() {
    fib[1][0] = fib[1][1] = fib[1][2] = 1;
    fib[2][0] = fib[2][1] = fib[2][2] = 2;
    for (int k = 0; k < 3; k++) {
        for (int i = 3; i < N; i++) {
            fib[i][k] = (fib[i - 1][k] + fib[i - 2][k]) % p[k];
        }
    }
}

int a[N], b[N], c[N];
int sa[3], sb[3], sc[3];

void run() {
    for (int k = 0; k < 3; k++) {
        sa[k] = sb[k] = sc[k] = 0;
    }
    int na, nb, nc;
    FI(na);
    for (int i = 1; i <= na; i++) {
        FI(a[i]);
        for (int k = 0; k < 3; k++) {
            if (a[i]) {
                sa[k] = (sa[k] + fib[i][k]) % p[k];
            }
        }
    }
    FI(nb);
    for (int i = 1; i <= nb; i++) {
        FI(b[i]);
        for (int k = 0; k < 3; k++) {
            if (b[i]) {
                sb[k] = (sb[k] + fib[i][k]) % p[k];
            }
        }
    }
    FI(nc);
    for (int i = 1; i <= nc; i++) {
        FI(c[i]);
        for (int k = 0; k < 3; k++) {
            if (c[i]) {
                sc[k] = (sc[k] + fib[i][k]) % p[k];
            }
        }
    }
    map<int, int> mp;
    for (int k = 0; k < 3; k++) {
        int t = (1ll * sa[k] * sb[k] % p[k] - sc[k] + p[k]) % p[k];
        for (int i = 1; i < nc; i++) {
            if (fib[i][k] == t) {
                ++mp[i];
                if (mp[i] == 3) {
                    FO(i), FO('\n');
                    return;
                }
            }
        }
    }
}
int main() {
#ifdef Local
    freopen("input.in", "r", stdin);
#endif
    init();
    int T; cin >> T; while(T--)
    run();
    Flush;
    return 0;
}