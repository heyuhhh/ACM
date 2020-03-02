/*
 * Author:  heyuhhh
 * Created Time:  2020/2/8 16:35:25
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
#define MP make_pair
#define fi first
#define se second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define INF 0x3f3f3f3f
#define Local
#ifdef Local
  #define dbg(args...) do { cout << #args << " -> "; err(args); } while (0)
  void err() { std::cout << '\n'; }
  template<typename T, typename...Args>
  void err(T a, Args...args) { std::cout << a << ' '; err(args...); }
#else
  #define dbg(...)
#endif
void pt() {std::cout << '\n'; }
template<typename T, typename...Args>
void pt(T a, Args...args) {std::cout << a << ' '; pt(args...); }
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
}dian[N << 1];
int last, tot, cnt;
bool chk[N];
void init() {
    last = tot = 1;
    cnt = dian[1].len = 0;
    for(int i = 1; i <= 2 * n; i++) memset(dian[i].ch, 0, sizeof(dian[i].ch));
}
void add(int c) {
    int p = last;
    int np = last = ++tot;
    dian[np].len = dian[p].len + 1;
    for(; p && !dian[p].ch[c]; p = dian[p].fa) dian[p].ch[c] = np;
    if(!p) {
        dian[np].fa = 1;
        ++cnt;
        if(cnt == 2) chk[0] = true;
    }
    else {
        int q = dian[p].ch[c];
        if(dian[q].len == dian[p].len + 1) dian[np].fa = q, chk[dian[q].len] = true;
        else {
            int nq = ++tot; dian[nq] = dian[q];
            dian[nq].len = dian[p].len + 1;
            dian[q].fa = dian[np].fa = nq;
            chk[dian[nq].len] = true;
            for(; p && dian[p].ch[c] == q; p = dian[p].fa) dian[p].ch[c] = nq;
        }
    }
}

void run(){
    cin >> (s + 1);
    n = strlen(s + 1);
    for(int i = 0; i <= n + 1; i++) chk[i] = false;
    init();
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        add(s[i] - 'a');   
        while(chk[ans]) ++ans;
        cout << ans << " \n"[i == n];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    int T; cin >> T;
    while(T--) run();
    return 0;
}
