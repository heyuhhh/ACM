/*
 * Author:  heyuhhh
 * Created Time:  2020/5/16 19:54:34
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

void run() {
    int A, B, C, D; cin >> A >> B >> C >> D;
    ll ans = 0;
    for (int i = A; i <= B; i++) {
        //i + j > C
        int j = max(B, C + 1 - i);
        if (j > C) continue;
        int t = min(D, i + j - 1);
        int d = min(C - j + 1, D - t + 1);
        int fir = t - C + 1;
        ans += 1ll * d * (d + fir - 1 + fir) / 2;
        if (j + d - 1 < C) {
            ans += 1ll * (C - j - d + 1) * (d + fir - 1);   
        }
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
