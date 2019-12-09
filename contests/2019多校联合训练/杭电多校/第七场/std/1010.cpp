#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define FOR(i, x, y) for (decay<decltype(y)>::type i = (x), _##i = (y); i < _##i; ++i)
#define FORD(i, x, y) for (decay<decltype(x)>::type i = (x), _##i = (y); i > _##i; --i)
#ifdef zerol
#define dbg(x...) do { cerr << "\033[32;1m" << #x << " -> "; err(x); } while (0)
#else
#define dbg(...)
#endif // zerol
void err() { cerr << "\033[39;0m" << endl; }
template<typename T, typename... A>
void err(T a, A... x) { cerr << a << ' '; err(x...); }
// ----------------------------------------------------------------------------------------

const int N = 2e5+10;

using P = pair<int, int>;

P a[N], b[N], c[N];

unsigned long long k1, k2;
unsigned long long rng() {
    unsigned long long k3 = k1, k4 = k2;
    k1 = k4;
    k3 ^= k3 << 23;
    k2 = k3 ^ k4 ^ (k3 >> 17) ^ (k4 >> 26);
    return k2 + k4;
}

void reading(P a[], int& n, bool gen) {
    static int b[N];
    if(gen) {
        int mod; scanf("%llu%llu%d", &k1, &k2, &mod);
        FOR(i, 0, n) b[i] = rng() % mod;
    } else FOR(i, 0, n) scanf("%d", b+i);
    
    sort(b, b+n);
    int m = 0;
    for(int i = 0, j = 0; i<n; i = j) {
        for(; (j<n) && (b[j] == b[i]); ++j);
        a[m++] = P(b[i], j-i);
    }
    n = m;
}

bool cmp(const P& p, const P& q) {
    return p.first + p.second > q.first + q.second;
}

int main() {
    int T; scanf("%d", &T);
    while(T--) {
        int n, m, t; scanf("%d%d%d", &n, &m, &t);
        reading(a, n, t == 2);
        reading(b, m, t == 2);
        int SA = 0, SB = 0, k = 0;
        for(int i = 0, j = 0; i<n || j<m; ) {
            dbg(a[i].first, a[i].second, b[j].first, b[j].second, i, j);
            if((i<n) && (j<m) && (a[i].first == b[j].first)) {
                c[k++] = P(a[i++].second, b[j++].second);
            } else if((i == n) || (j<m && b[j].first < a[i].first)){
                SB += b[j++].second;
            } else {
                SA += a[i++].second;
            }
        }
        sort(c, c+k, cmp);
        FOR(i, 0, k) {
            if(i&1) {
                SB += c[i].second;
            } else {
                SA += c[i].first;
            }
        }
        if(SA > SB) puts("Cuber QQ");
        else puts("Quber CC");
    }
    return 0;
}