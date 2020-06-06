/*
 * Author:  heyuhhh
 * Created Time:  2020/5/21 13:45:08
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
const int N = 1e6 + 5;

void run() {
    int n; cin >> n;
    vector <int> a;
    for (int i = 1; i <= n; i++) {
        string s; cin >> s;
        int len = s.length();
        if (s[0] == '-' || len > 100) continue;
        if (len < 9) {
            int x = 0;
            for (int j = 0; j < len; j++) {
                x = x * 10 + s[j] - '0';
            }
            a.push_back(x);
        }
    }
    sort(all(a));
    for (int i = 0, j = 0;; i++, j++) {
        if (j >= sz(a) || i != a[j]) {
            cout << i << '\n';
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
