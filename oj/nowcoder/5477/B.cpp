/*
 * Author:  heyuhhh
 * Created Time:  2020/5/10 13:57:43
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
const int N = 5000 + 5;

char s[N];
int n;
const double eps = 1e-6;

void run() {
    cin >> (s + 1);
    n = strlen(s + 1);
    double res = 0;
    for (int i = 1, j; i <= n; i = j) {
        j = i;
        int x = 0, y = 0;
        while (j <= n && s[j] <= '9' && s[j] >= '0') {
            x = x * 10 + s[j] - '0';
            ++j;
        }
        if (j <= n && s[j] == '+') {
            res += x;
            ++j; continue;
        } else if(j > n) {
            res += x;
            continue;
        }
        ++j;
        while (j <= n && s[j] <= '9' && s[j] >= '0') {
            y = y * 10 + s[j] - '0';
            ++j;
        }
        res += 1.0 * x * (y + 1) * y / 2 / y;
    }
    if (fabs(res - round(res)) <= eps) {
        cout << (ll) res << '\n';   
    } else {
        cout << fixed << setprecision(1) << res << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    run();
    return 0;
}
