/*
 * Author:  heyuhhh
 * Created Time:  2020/6/2 13:27:05
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

int w, h;

void ok(int x, int y) {
    if (x > y) swap(x, y);   
    if (x <= w && y <= h) {
        cout << "Yes" << '\n';
        exit(0);
    }
}

void run() {
    int a[3];
    for (int i = 0; i < 3; i++) {
        cin >> a[i];
    }
    cin >> w >> h;
    if (w > h) swap(w, h);
    sort(a, a + 3);
    do {
        ok(2 * a[2] + a[0], 2 * a[2] + 2 * a[1]);
        ok(3 * a[0] + a[1] + a[2], a[1] + a[2]);
        ok(2 * a[2] + 2 * a[1], a[0] + a[1] + a[2]);
        ok(2 * a[0] + a[1] + a[2], a[0] + a[1] + a[2]);
    } while (next_permutation(a, a + 3));
    cout << "No" << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
