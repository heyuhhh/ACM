/*
 * Author:  heyuhhh
 * Created Time:  2019/12/17 15:36:21
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
const int N = 105;

int s, n;
char ch[N];
int G[N][N][N];
int a[N];
ll p[64], fac[N];
ll ans;

void dfs(int x, int up) {
    if(x == n) {
        memset(p, 0, sizeof(p));
        int c = 0;
        for(int k = 1; k <= s; k++) {
            ll res = 0;
            int tot = 0;
            for(int i = 1; i <= n; i++) {
                for(int j = i + 1; j <= n; j++) {
                    if(a[i] != a[j]) res |= ((ll)G[k][i][j] << tot);
                    ++tot;
                }
            }   
            for(int i = tot; i >= 0; i--) if(res >> i & 1) {   
                if(!p[i]) {
                    ++c; p[i] = res; 
                    break;   
                }
                res ^= p[i];
            }
        }
        if(up & 1) ans += fac[up - 1] * (1ll << (s - c));
        else ans -= fac[up - 1] * (1ll << (s - c));
        return;
    }
    for(int i = 1; i <= up + 1; i++) {
        a[x + 1] = i; dfs(x + 1, max(i, up));   
    }
}

void run(){
    fac[0] = 1;
    for(int i = 1; i < 12; i++) fac[i] = fac[i - 1] * i;
    for(int k = 1; k <= s; k++) {
        cin >> (ch + 1);
        int len = strlen(ch + 1), cnt = 0;
        for(int j = 1; !n; j++) if(j * (j - 1) == 2 * len) n = j;
        for(int i = 1; i <= n; i++) {
            for(int j = i + 1; j <= n; j++) {
                G[k][i][j] = ch[++cnt] - '0';
            }
        }
    }
    a[1] = 1;
    dfs(1, 1);
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    while(cin >> s) run();
    return 0;
}
