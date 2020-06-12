/*
 * Author:  heyuhhh
 * Created Time:  2020/6/11 22:44:42
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
#define l first
#define r second
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
    int n, m, x;
    cin >> n >> x >> m;
    vector <pii> a(m);
    
    for (int i = 0; i < m; i++) {
        int l, r; cin >> l >> r;
        a[i] = MP(l, r);
    }
    
    int Min = x, Max = x;
    for (int i = 0; i < m; i++) {
        if (min(a[i].r, Max) >= max(a[i].l, Min)) {
            Min = min(a[i].l, Min);
            Max = max(a[i].r, Max);
        }
    }
    cout << Max - Min + 1 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    int T; cin >> T; while(T--)
    run();
    return 0;
}
