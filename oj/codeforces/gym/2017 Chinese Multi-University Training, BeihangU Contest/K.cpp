/*
 * Author:  heyuhhh
 * Created Time:  2020/5/29 13:43:59
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

ll n, k;
int _;

void run() {
    ++_;
    cout << "Case #" << _ << ": ";
    if (k <= n) {
        cout << k << '\n';
        return;   
    }
    k -= n;
    ll t = (k + n - 2) / (n - 1);
    if (t & 1) {
        cout << (k - 1) % (n - 1) + 1 << '\n';
    } else {
        if (k % (n - 1) == 0) {
            cout << n << '\n';
        } else {
            cout << (k - 1) % (n - 1) + 1 << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    while (cin >> n >> k) run();
    return 0;
}
