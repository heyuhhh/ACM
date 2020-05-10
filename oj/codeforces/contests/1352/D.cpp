/*
 * Author:  heyuhhh
 * Created Time:  2020/5/9 23:28:59
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
const int N = 1000 + 5;

int n;
int a[N];

void run() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int totA = 0, totB = 0, res = 0;
    int cur = 0;
    int l = 1, r = n;
    int last;
    while (l <= r) {
        ++res;
        if (cur == 0) {
            if (l == 1) {
                last = a[l++];
            } else {
                int tot = 0;
                while (l <= r && tot <= last) {
                    tot += a[l++];
                }   
                last = tot;
            }
            totA += last;
        } else {
            int tot = 0;
            while (l <= r && tot <= last) {
                tot += a[r--];
            }
            last = tot;
            totB += last;
        }
        cur ^= 1;
    }
    cout << res << ' ' << totA << ' ' << totB << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    int T; cin >> T; while(T--)
    run();
    return 0;
}
