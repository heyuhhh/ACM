/*
 * Author:  heyuhhh
 * Created Time:  2020/6/22 10:01:22
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
#include <functional>
#include <numeric>
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

void run() {
    int n; cin >> n;
    vector <int> a(n);
    vector <bool> check(N), vis(N);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (vis[a[i]]) {
            check[a[i]] = true;
        }
        vis[a[i]] = true;
    }
    for (int i = 1; i < N; i++) if (vis[i]) {
        for (int j = i + i; j < N; j += i) {
            check[j] = true;
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (!check[a[i]]) ++ans;
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
