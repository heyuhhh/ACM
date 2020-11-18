// Author : heyuhhh
// Created Time : 2020/10/21 20:13:43
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

int n, m;
int f[N], a[N], b[N];
vector<int> G[N];

struct node {
    int val, d;
    int ch[2];
} t[N];

ll sum[N];
int rt[N], siz[N];

int merge(int x, int y) {
    if (!x || !y) return x | y;
    if (t[x].val < t[y].val) swap(x, y);
    t[x].ch[1] = merge(t[x].ch[1], y);
    t[x].d = t[t[x].ch[1]].d + 1;
    if (t[t[x].ch[1]].d > t[t[x].ch[0]].d) {
        swap(t[x].ch[1], t[x].ch[0]);
    }
    return x;
}

void del(int& x) {
    x = merge(t[x].ch[0], t[x].ch[1]);
}

ll ans;

void run() {
    FI(n), FI(m);
    for (int i = 1; i <= n; i++) {
        FI(f[i]), FI(a[i]), FI(b[i]);
        t[i].val = a[i];
        siz[i] = 1;
        sum[i] = a[i];
    }
    for (int i = 1; i <= n; i++) {
        rt[i] = i;
    }
    for (int i = n; i >= 1; i--) {
        ans = max(ans, 1ll * b[i] * siz[i]);
        if (f[i]) {
            rt[f[i]] = merge(rt[f[i]], rt[i]);
            sum[f[i]] += sum[i];
            siz[f[i]] += siz[i];
            while (sum[f[i]] > m) {
                sum[f[i]] -= t[rt[f[i]]].val;
                siz[f[i]]--;
                del(rt[f[i]]);
            }
        }
    }
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