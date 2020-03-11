/*
 * Author:  heyuhhh
 * Created Time:  2020/3/7 17:39:12
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
const int N = 1e6 + 5;

int n;
char s[N];

void run() {
    cin >> n >> (s + 1);
    int ans = 0;
    for(int i = 1, j; i <= n; i = j) {
        int d = 0;
        j = i;
        bool ok = true;
        while(j <= n) {
            (s[j++] == '(' ? ++d : --d);
            if(d == 0) break;
            if(d < 0) ok = false;
        }
        if(!ok) ans += j - i;
        if(d != 0) {
            cout << -1 << '\n';
            return;
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
