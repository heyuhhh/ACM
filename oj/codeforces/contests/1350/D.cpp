/*
 * Author:  heyuhhh
 * Created Time:  2020/5/12 21:36:28
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

int n;
int a[N];

void run() {
    int n, k; cin >> n >> k;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        if (x > k) a[i] = 1;
        else if (x < k) a[i] = -1;
        else a[i] = 0;
        if (a[i] == 0) ++cnt;
    }
    auto chk = [&] () {
        if (cnt == n) return true;
        if (cnt == 0) return false;
        for (int i = 1; i < n; i++) {
            if (a[i] >= 0 && a[i + 1] >= 0) return true;
        }
        for (int i = 1; i < n - 1; i++) {
            if (a[i] >= 0 && a[i + 2] >= 0) return true;       
        }
        return false;
    };
    if (chk()) cout << "yes" << '\n';
    else cout << "no" << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    int T; cin >> T; while(T--)
    run();
    return 0;
}
//0 -1 -1 -1 1 1 0
