/*
 * Author:  heyuhhh
 * Created Time:  2020/5/22 21:15:00
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

struct Manacher{
    char ch[N << 1];
    int p[N << 1];
    void work(char *s) {
        int l = 0;
        ch[l++] = '&'; ch[l++] = '#';
        for(int i = 0; s[i]; i++) {
            ch[l++] = s[i];
            ch[l++] = '#';
        }
        ch[l] = '\0';
        int mx = 0, id = 0;
        for(int i = 0; i < l; i++) {
            p[i] = i < mx ? min(p[2 * id - i], mx - i) : 1;
            while(ch[i + p[i]] == ch[i - p[i]]) p[i]++;
            if(i + p[i] > mx) mx = i + p[i], id = i;
        }
    }
    void debug() {
        cout << ch << '\n';
        int len = strlen(ch);   
        for (int i = 0; i < len; i++) {
            cout << p[i] << ' ';
        }
        cout << '\n';
    }
    vector <pii> gao() {
        int l = strlen(ch);
        vector <pii> res;
        for (int i = 1; i < l; i++) if (ch[i] != '#') {
            int l = (i - p[i]) / 2;
            int pos = i / 2 - 1;
            int r = 2 * pos - l;
            ++l, ++r;
            while (l <= r) {
                res.push_back(MP(l, r));
                ++l, --r;
            }
        }
        return res;
    }
}Man;

char s[N];
int n, m;
struct node {
    int l, r, id;
    bool operator < (const node &A) const {
        return r < A.r;   
    }
}a[N];
struct BIT {
    int c[N];
    int lowbit(int x) {return x & (-x);}
    void add(int x, int v = 1) {
        for(; x < N; x += lowbit(x)) c[x] += v;
    }
    int query(int x) {
        int res = 0;
        for(; x; x -= lowbit(x)) res += c[x];
        return res;   
    }
    int query(int l, int r) {
        return query(r) - query(l - 1);   
    }
}bit; 
int ans[N];

void run() {
    cin >> n >> m;
    cin >> s;
    Man.work(s);
    //Man.debug();
    for (int i = 1; i <= m; i++) {
        int l, r; cin >> l >> r;
        a[i] = node{l, r, i};
    }
    sort(a + 1, a + m + 1);
    vector <vector <int>> query(n + 1);
    for (int i = 1; i <= m; i++) {
        query[a[i].r].push_back(i);
    }
    vector <pii> b = Man.gao();
    vector <vector <int>> v(n + 1);
    for (auto it : b) {
        v[it.se].push_back(it.fi);
    }
    for (int i = 1; i <= n; i++) {
        for (auto it : v[i]) bit.add(it, 1);
        for (auto it : query[i]) {
            int l = a[it].l, id = a[it].id;
            ans[id] = bit.query(l, i);
        }
    }
    for (int i = 1; i <= m; i++) {
        cout << ans[i] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
