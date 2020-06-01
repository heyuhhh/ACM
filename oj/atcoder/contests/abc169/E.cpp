/*
 * Author:  heyuhhh
 * Created Time:  2020/5/31 20:46:05
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
const int N = 2e5 + 5;

struct seg {
    int l, r;   
}a[N];

int n;

int findL(int k) {
    return a[k + 1].r;
}

int findR(int k) {
    return a[k + 1].l;
}

seg find(int k) {
    sort(a + 1, a + n + 1, [&](seg A, seg B) {
        return A.r < B.r;
    });
    int r = findL(k - 1);
    sort(a + 1, a + n + 1, [&](seg A, seg B) {
        return A.l > B.l;
    });   
    int l = findR(n - k);
    return seg{l, r};
}

void run() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int l, r; cin >> l >> r;
        a[i] = seg{l, r};
    }
    if (n & 1) {
        seg res = find(n / 2 + 1);
        int ans = max(0, res.r - res.l + 1); 
        cout << ans << '\n';
    } else {
        seg res1 = find(n / 2), res2 = find(n / 2 + 1);
        int Min = res1.l + res2.l, Max = res1.r + res2.r;
        int ans = max(0, Max - Min + 1);
        cout << ans << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
