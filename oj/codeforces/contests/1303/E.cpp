/*
 * Author:  heyuhhh
 * Created Time:  2020/2/13 9:56:57
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
const int N = 400 + 5;

int n, m;
char s[N], t[N];
int nxt[N][26];
int dp[N][N];

int solve(char *s, int n, char *t, int m) {
    memset(dp, INF, sizeof(dp));
    dp[0][0] = 0;
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            if(i) dp[i][j] = min(dp[i][j], nxt[dp[i - 1][j]][s[i] - 'a']);
            if(j) dp[i][j] = min(dp[i][j], nxt[dp[i][j - 1]][t[j] - 'a']);
        }
    }
    return dp[n][m];
}

void run(){
    cin >> (s + 1) >> (t + 1);
    n = strlen(s + 1);
    m = strlen(t + 1);
    memset(nxt, 0, sizeof(nxt));
    for(int i = 0; i < 26; i++) nxt[n + 1][i] = n + 1;
    for(int i = n; i >= 0; i--) {
        for(int j = 0; j < 26; j++) {
            if(s[i + 1] == 'a' + j) nxt[i][j] = i + 1;
            else nxt[i][j] = nxt[i + 1][j];
        }
    }
    int ans = INF;
    for(int i = 1; i <= m; i++) {
        ans = min(ans, solve(t, i, t + i, m - i));
    }
    if(ans <= n) cout << "YES" << '\n';
    else cout << "NO" << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    int T; cin >> T;
    while(T--) run();
    return 0;
}
