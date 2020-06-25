/*
 * Author:  heyuhhh
 * Created Time:  2020/6/24 15:08:23
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

int Win(ll s, ll e) {
    if (e & 1) {
        if (s & 1) return 0;
        return 1;
    }
    if (s > e / 2) {
        if (s & 1) return 1;
        return 0;
    }
    if (s > e / 4) {
        return 1;
    }
    return Win(s, e / 4);
}

int Lose(ll s, ll e) {
    if (s > e / 2) {
        return 1;
    }
    return Win(s, e / 2);
}

void run() {
    int n; cin >> n;
    vector <pii> r(n);
    for (int i = 0; i < n; i++) {
        ll s, e; cin >> s >> e;
        r[i] = MP(Win(s, e), Lose(s, e));
    }
    int f = 1, s = 0;
    for (int i = 0; i < n; i++) {
        if (f == s) break;
        r[i].fi ^= s;
        r[i].se ^= s;
        f = r[i].se;
        s = r[i].fi;
    }
    cout << s << ' ' << f << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
