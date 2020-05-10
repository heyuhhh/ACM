/*
 * Author:  heyuhhh
 * Created Time:  2020/5/9 22:37:14
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

int a[3];

void run() {
    for (int i = 0; i < 3; i++) cin >> a[i];
    string s = "";
    int cur = 0;
    if (a[0] == 0) cur = 1;
    s += (cur + '0');
    cur ^= 1;
    for (; a[1] > 1; --a[1]) {
        s += (cur + '0');
        cur ^= 1;
    }
    int x = (cur ^ 1);
    while (a[x + x] > 0) {
        s += (x + '0');
        --a[x + x];   
    }
    x = cur;
    if (a[1] > 0) s += (x + '0');
    while (a[x + x] > 0) {
        s += (x + '0');
        --a[x + x];   
    }   
    cout << s << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    int T; cin >> T; while(T--)
    run();
    return 0;
}
