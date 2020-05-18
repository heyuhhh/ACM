/*
 * Author:  heyuhhh
 * Created Time:  2020/5/16 23:03:40
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
const int N = 1e6 + 5;

int cnt[N];

void run() {
    int A, B, C, D; cin >> A >> B >> C >> D;
    ++cnt[A + B], --cnt[B + B + 1];
    --cnt[A + C + 1], ++cnt[B + C + 2];
    for (int i = 1; i < N; i++) {
        cnt[i] += cnt[i - 1];
    }
    for (int i = 1; i < N; i++) {
        cnt[i] += cnt[i - 1];
    }
    ll ans = 0;
    for (int i = C + 1; i < N; i++) {
        int val = min(i - 1, D) - C + 1;
        ans += 1ll * val * cnt[i];
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
