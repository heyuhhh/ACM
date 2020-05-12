/*
 * Author:  heyuhhh
 * Created Time:  2020/5/5 18:52:18
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

ll pow5(ll c) {
    return c * c * c * c * c;
}

void run() {
    int x; cin >> x;
    int k = 2000;
    auto calc = [&](ll t) {
        for (int i = 0; i <= k; i++) {
            if (pow5(i) == t) return i;   
            if (pow5(-i) == t) return -i;
        }
        return k + 1;
    };
    for (int i = 0; i <= k; i++) {
        int t = calc(x + pow5(i));
        if (t <= k) {
            cout << t << ' ' << i << '\n';
            return;
        }   
        t = calc(x - pow5(i));
        if (t <= k) {
            cout << t << ' ' << -i << '\n';
            return;   
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
