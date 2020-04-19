/*
 * Author:  heyuhhh
 * Created Time:  2020/4/18 19:51:22
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
const int N = 1e5 + 5;

char s[N];
int cnt[10], ans[10];

bool dfs(int x, int k, int m) {
    if(x == -1) {
        return k == 0 && m == 0;
    }
    int r = min(k, cnt[x]);
    if(x == 0) {
        int f = 1;
        for(int i = 1; i < 10; i++) {
            if(ans[i] > 0) f = 0;
        }   
        if(f) r = min(cnt[x], 1);
    }
    int l = max(0, r - 2);
    for(int i = r; i >= l; i--) {
        ans[x] = i;
        if(dfs(x - 1, k - i, (m + i * x) % 3)) return true;
    }
    return false;
}

void run() {
    int n, k;
    cin >> (s + 1) >> k;
    n = strlen(s + 1);
    for(int i = 0; i < 10; i++) cnt[i] = ans[i] = 0;
    for(int i = 1; i <= n; i++) {
        ++cnt[s[i] - '0'];
    }
    if(!dfs(9, k, 0)) cout << -1 << '\n';
    else {
        for(int i = 9; i >= 0; i--) {
            for(int j = 1; j <= ans[i]; j++) cout << i;
        }   
        cout << '\n';
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
