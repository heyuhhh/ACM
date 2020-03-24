/*
 * Author:  heyuhhh
 * Created Time:  2020/3/23 23:07:11
 */
#include <iostream>
#include <algorithm>
#include <cstring>
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
  void err() { std::cout << '\n'; }
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

int n, m, k;

void run() {
    cin >> n >> m >> k;
    for(int i = 1; i <= k; i++) {
        int x, y; cin >> x >> y;   
    }
    for(int i = 1; i <= k; i++) {
        int x, y; cin >> x >> y;   
    }   
    string res = "";
    for(int i = 0; i < n - 1; i++) res += "U";
    for(int i = 0; i < m - 1; i++) res += "L";
    for(int i = 0; i < n; i++) {
        if(i & 1) {
            for(int j = 0; j < m - 1; j++) res += "L";
        } else {
            for(int j = 0; j < m - 1; j++) res += "R";
        }                 
        if(i < n - 1) res += "D";
    }
    cout << res.length() << '\n';
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
