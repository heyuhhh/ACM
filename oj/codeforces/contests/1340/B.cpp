/*
 * Author:  heyuhhh
 * Created Time:  2020/4/23 23:15:45
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
const int N = 2000 + 5;

const int dig[] = {119, 18, 93, 91, 58, 107, 111, 82, 127, 123};

int n, k;
char s[7];
int a[N];
bool dp[N][N], chk[N][N];

void dfs(int p, int r) {
    if(p == 0) return;
    if(r > k) return;
    if(chk[p][r]) return;
    chk[p][r] = true;
    for(int i = 0; i < 10; i++) {
        if((a[p] & dig[i]) == a[p]) {
            int t = __builtin_popcount(a[p] ^ dig[i]);
            dp[p][r + t] = true;
            dfs(p - 1, r + t);
        }
    }
}

void run() {
    cin >> n >> k;
    memset(dp, false, sizeof(dp));
    dp[n + 1][0] = true;
    for(int i = 1; i <= n; i++) {
        cin >> s;
        int x = 0;
        for(int j = 0; j < 7; j++) {
            if(s[j] == '1') x += (1 << (7 - j - 1));
        }   
        a[i] = x;
    }
    dfs(n, 0);
    vector <int> ans;
    for(int i = 1; i <= n; i++) {
        bool ok = false;
        for(int j = 9; j >= 0; j--) if((a[i] & dig[j]) == a[i]) {
            int t = __builtin_popcount(a[i] ^ dig[j]);
            if(k - t >= 0 && dp[i + 1][k - t]) {
                ans.push_back(j);   
                ok = true;
                k -= t;
                break;
            }
        }
        if(ok == false) {
            cout << -1 << '\n';
            return;   
        }
    }
    for(auto it : ans) cout << it;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
