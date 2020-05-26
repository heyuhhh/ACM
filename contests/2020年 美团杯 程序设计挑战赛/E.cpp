/*
 * Author:  heyuhhh
 * Created Time:  2020/5/19 10:59:50
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
const int N = 1e6 + 5;

int n;
char s[N];

struct node{
    int ch[26];
    int len, fa;
    node(){memset(ch, 0, sizeof(ch)), len = 0;}
}dian[N << 2];
int last = 1, tot = 1;
void add(int c) {
    int p = last;
    int np = last = ++tot;
    dian[np].len = dian[p].len + 1;
    for(; p && !dian[p].ch[c]; p = dian[p].fa) dian[p].ch[c] = np;
    if(!p) dian[np].fa = 1;
    else {
        int q = dian[p].ch[c];
        if(dian[q].len == dian[p].len + 1) dian[np].fa = q;
        else {
            int nq = ++tot; dian[nq] = dian[q];
            dian[nq].len = dian[p].len + 1;
            dian[q].fa = dian[np].fa = nq;
            for(; p && dian[p].ch[c] == q; p = dian[p].fa) dian[p].ch[c] = nq;
        }
    }
}

ll cnt[26];

void run() {
    cin >> (s + 1);
    n = strlen(s + 1);
    ll ans = 0, all = 1;
    auto calc = [&]() {
        return dian[last].len - dian[dian[last].fa].len;
    };
    for (int i = n; i >= 0; i--) {
        ans += all;
        ans -= (i < n ? cnt[s[i + 1] - 'a'] : 0);
        if (i) {
            add(s[i] - 'a');
            cnt[s[i] - 'a'] += calc();
            all += calc();              
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
