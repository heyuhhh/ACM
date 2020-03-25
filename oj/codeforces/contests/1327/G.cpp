/*
 * Author:  heyuhhh
 * Created Time:  2020/3/25 8:58:08
 */
#include <iostream>
#include <algorithm>
#include <cstring>
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
#define Local
#ifdef Local
  #define dbg(args...) do { cout << #args << " -> "; err(args); } while (0)
  void err() { std::cout << '\n'; }
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
const int N = 4e5 + 5, M = 1005, MAX = 14;
queue <int> q;
namespace ACAM{
    int sz;
    int ch[M][MAX];
    int cnt[M], fail[M], sum[M];
    int newnode() {
        memset(ch[++sz], 0, sizeof(ch[sz]));
        cnt[sz] = fail[sz] = 0;
        return sz;
    }
    void init() {
        sz = -1;
        newnode();
    }
    void insert(char *s, int val) {
        int u = 0;
        for(int i = 1; s[i]; i++) {
            int idx = s[i] - 'a';
            if(!ch[u][idx]) ch[u][idx] = newnode();
            u = ch[u][idx];
        }
        sum[u] += val;
    }
    void build() {
        while(!q.empty()) q.pop();
        for(int i = 0; i < MAX; i++) {
            if(ch[0][i]) q.push(ch[0][i]);
        }
        while(!q.empty()) {
            int cur = q.front(); q.pop();
            for(int i = 0; i < MAX; i++) {
                if(ch[cur][i]) {
                    fail[ch[cur][i]] = ch[fail[cur]][i];
                    sum[ch[cur][i]] += sum[ch[fail[cur]][i]];
                    q.push(ch[cur][i]);
                } else {
                    ch[cur][i] = ch[fail[cur]][i];
                }
            }
        }
    }
};
using namespace ACAM;
int k;
char s[N], t[M];
int go[M];
ll dp[M][1 << MAX], c[M];

void chkmax(ll &x, ll y) {
    x = max(x, y);
}

void run() {
    cin >> k;
    init();
    for(int i = 1; i <= k; i++) {
        int c;
        cin >> (t + 1) >> c;   
        insert(t, c);
    }
    build();
    for(int i = 0; i <= sz; i++) {
        for(int j = 0; j < 1 << MAX; j++) {
            dp[i][j] = -1e18;
        }   
    }
    dp[0][0] = 0;
    for(int i = 0; i <= sz; i++) go[i] = i, c[i] = 0;
    cin >> (s + 1);
    int cnt = 0;
    for(int i = 1; s[i]; i++) {
        if(s[i] == '?') {
            for(int st = 0; st < 1 << MAX; st++) {
                if(__builtin_popcount(st) != cnt) continue;
                for(int j = 0; j <= sz; j++) if(dp[j][st] > -1e18) {
                    for(int t = 0; t < MAX; t++) if(!(st >> t & 1)) {
                        chkmax(dp[ch[go[j]][t]][st | (1 << t)], dp[j][st] + c[j] + sum[ch[go[j]][t]]);
                    }
                }
            }
            for(int j = 0; j <= sz; j++) go[j] = j, c[j] = 0;
            ++cnt;
        } else {
            for(int j = 0; j <= sz; j++) go[j] = ch[go[j]][s[i] - 'a'], c[j] += sum[go[j]];
        }
    }
    ll ans = -1e18;
    for(int st = 0; st < 1 << MAX; st++) {
        if(__builtin_popcount(st) == cnt) {
            for(int i = 0; i <= sz; i++) {
                chkmax(ans, dp[i][st] + c[i]);   
            }
        }   
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
