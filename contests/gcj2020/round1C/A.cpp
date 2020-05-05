/*
 * Author:  heyuhhh
 * Created Time:  2020/5/2 17:04:59
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

int _;

void run() {
    ++_;
    int x, y; cin >> x >> y;
    string s; cin >> s;
    int len = s.length();
    cout << "Case #" << _ << ": ";
    for (int i = 0; i <= len; i++) {
        if (abs(x) + abs(y) <= i) {
            cout << i << '\n';
            return;   
        }
        if (i < len) {
            if (s[i] == 'E') ++x;
            if (s[i] == 'N') ++y;
            if (s[i] == 'S') --y;
            if (s[i] == 'W') --x;
        }
    }
    cout << "IMPOSSIBLE" << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    int T; cin >> T; while(T--)
    run();
    return 0;
}
