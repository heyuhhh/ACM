/*
 * Author:  heyuhhh
 * Created Time:  2020/4/27 16:10:31
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
int m[N], c[N], cnt[N], suf[N];

void run() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> m[i];
        ++cnt[m[i]];
    }
    sort(m + 1, m + n + 1);
    for (int i = k; i >= 1; i--) {
        suf[i] = suf[i + 1] + cnt[i];   
    }
    for (int i = 1; i <= k; i++) {
        cin >> c[i];   
    }
    int res = 0;
    for (int i = 1; i <= k; i++) {
        res = max(res, (suf[i] - 1) / c[i] + 1);   
    }
    cout << res << '\n';
    vector <vector <int>> ans(res);
    for (int i = 1; i <= n; i++) {
        ans[(i - 1) % res].push_back(m[i]);
    }
    for (int i = 0; i < res; i++) {
        cout << sz(ans[i]);
        for (auto it : ans[i]) cout << ' ' << it;
        cout << '\n';   
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
