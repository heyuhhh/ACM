/*
 * Author:  heyuhhh
 * Created Time:  2020/4/10 20:27:31
 */
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <iomanip>
#include <assert.h>
#define MP make_pair
#define fi first
#define se second
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define INF 0x3f3f3f3f
#define Local
#ifdef Local
  #define dbg(args...) do { cout << #args << " -> "; err(args); } while (0)
  void err() { std::cout << std::endl; }
  template<typename T, typename...Args>
  void err(T a, Args...args) { std::cout << a << ' '; err(args...); }
  template <template<typename...> class T, typename t, typename... A> 
  void err(const T <t> &arg, const A&... args) {
  for (auto &v : arg) std::cout << v << ' '; err(args...); }
#else
  #define dbg(...)
#endif
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
//head
const int N = 2e5 + 5;

int n, k;
char s[N];
struct SA{                                       //sa:1...n  Rank:0...n-1
    int x[N], y[N], sa[N], c[N], height[N], Rank[N];
    int f[N][20], lg[N];
    int n;                                          //length
    void da(char *s, int m){
        n++;
        for(int i = 0; i < m; i++) c[i] = 0;
        for(int i = 0; i < n; i++) c[x[i] = s[i]]++;
        for(int i = 1; i < m; i++) c[i] += c[i - 1] ;
        for(int i = n - 1; i >= 0; i--) sa[--c[x[i]]] = i;
        for(int k = 1; k <= n; k <<= 1) {
            int p = 0 ;
            for(int i = n - k; i < n; i++) y[p++] = i ;
            for(int i = 0; i < n; i++) if(sa[i] >= k) y[p++] =sa[i] - k;
            for(int i = 0; i < m; i++) c[i] = 0;
            for(int i = 0; i < n; i++) c[x[y[i]]]++;
            for(int i = 1; i < m; i++) c[i] += c[i - 1];
            for(int i = n - 1; i >= 0; i--) sa[--c[x[y[i]]]] = y[i] ;
            swap(x , y); p = 1; x[sa[0]] = 0;
            for(int i = 1; i < n; i++)
                x[sa[i]] = y[sa[i - 1]] == y[sa[i]] && y[sa[i-1] + k] == y[sa[i] + k] ? p - 1 : p++;
            if(p >= n) break ;
            m = p;
        }
        n--;
        int k = 0;
        for(int i = 0; i <= n; i++) Rank[sa[i]] = i;
        for(int i = 0; i < n; i++) {
            if(k) k--;
            int j = sa[Rank[i] - 1];
            while(s[i + k] == s[j + k]) k++;
            height[Rank[i]] = k;
        }
    }
    ll count() {
        ll ans = 0;
        for(int i = 1; i <= n; i++) ans += n - sa[i] - height[i];
        return ans;
    }
    void init() {
        for(int i = 2; i < N; i++) lg[i] = lg[i >> 1] + 1;
        for(int i = 2; i <= n; i++) f[i][0] = height[i];
        for(int j = 1; j < 20; j++)
            for(int i = 2; i + (1 << j) - 1 <= n; i++)
                f[i][j] = min(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]) ;
    }
    int get_lcp(int l, int r) {
        ++l; if(l > r) return n + 1;
        int k = lg[r - l + 1];
        return min(f[l][k], f[r - (1 << k) + 1][k]);
    }
}suf;

bool chk(int x) {
    for(int l = 1, r; l <= n; l = r + 1) {
        r = l;
        while(suf.get_lcp(l, r + 1) >= x) ++r;
        set <int> S;
        for(int i = l; i <= r; i++) S.insert(suf.sa[i]);
        auto now = *S.begin();
        int cnt = 1;
        while(1) {
            auto nxt = S.lower_bound(now + x);   
            if(nxt == S.end()) break;
            now = *nxt;
            ++cnt;
        }
        if(cnt >= k) return true;
    }
    return false;
}

void run() {
    cin >> n >> k;
    cin >> s;
    suf.n = n;
    suf.da(s, 520);
    suf.init();
    int l = 1, r = n / k + 3, mid;
    while(l < r) {
        mid = (l + r) >> 1;
        if(chk(mid)) l = mid + 1;
        else r = mid;   
    }
    cout << l - 1 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
