/*
 * Author:  heyuhhh
 * Created Time:  2020/6/18 23:14:47
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

void run() {
    int n; cin >> n;
    int x = n;
    int nx = 0, ny = 0;
    vector <pii> ans;
    auto draw = [&] (int x, int y, int op) {
        if (op) ans.push_back(MP(x, y));
        ans.push_back(MP(x, y - 1));
        if (op) ans.push_back(MP(x, y + 1));
        if (op) ans.push_back(MP(x - 1, y));
        if (op) ans.push_back(MP(x - 1, y + 1));
        ans.push_back(MP(x + 1, y));
        ans.push_back(MP(x + 1, y - 1));
        return 1;
    };
    draw(nx, ny, 1), --n, ++nx, --ny;
    for (int i = n; i >= 1; i--) {
        draw(nx, ny, 0);
        ++nx, --ny;
    }
    cout << sz(ans) << '\n';
    for (auto it : ans) {
        cout << it.fi << ' ' << it.se << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
