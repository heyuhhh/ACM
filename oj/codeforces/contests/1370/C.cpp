/*
 * Author:  heyuhhh
 * Created Time:  2020/6/21 8:00:35
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
const int N = 1e5 + 5;

void first() {
    cout << "Ashishgup" << '\n';
}
void second() {
    cout << "FastestFinger" << '\n';
}

void run() {
    int n; cin >> n;
    if (n == 1) {
        second();
        return;
    }
    if (n & 1) {
        first();
        return;
    }
    int cnt = 0, cnt2 = 0;
    while (n % 2 == 0) {
        n /= 2;
        ++cnt;
    }
    for (int i = 3; 1ll * i * i <= n; i++) {
        while (n % i == 0) {
            n /= i;
            ++cnt2;
        }
    }
    if (n > 1) ++cnt2;
    if (cnt == 1) {
        if (cnt2 != 1) {
            first();
        } else {
            second();
        }
    } else {
        if (cnt2) {
            first();
        } else {
            second();
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    int T; cin >> T; while(T--)
    run();
    return 0;
}
