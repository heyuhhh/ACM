/*
 * Author:  heyuhhh
 * Created Time:  2020/5/26 14:12:02
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

int a[N];

void run() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] < a[i - 1]) {
            l = i - 1;
            while (l && a[l] == a[l - 1]) --l;
            break;
        }
    }
    for (int i = n - 1; i; i--) {
        if (a[i] < a[i - 1]) {
            r = i;
            while (r + 1 < n && a[r] == a[r + 1]) ++r;
            break;
        }
    }
    if (l <= r) reverse(a + l, a + r + 1);
    for (int i = 1; i < n; i++) {
        if (a[i] < a[i - 1]) {
            cout << "impossible" << '\n';
            return;
        }
    }
    ++l, ++r;
    cout << l << ' ' << r << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
