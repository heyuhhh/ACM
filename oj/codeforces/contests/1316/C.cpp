/*
 * Author:  heyuhhh
 * Created Time:  2020/3/4 23:03:37
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

int n, m, p;
int a[N], b[N];

void run() {
    cin >> n >> m >> p;
    int p1 = -1, p2 = -1;
    for(int i = 0; i < n; i++) {
        cin >> a[i], a[i] %= p;
        if(a[i] && p1 == -1) p1 = i;
    }
    for(int i = 0; i < m; i++) {
        cin >> b[i], b[i] %= p;
        if(b[i] && p2 == -1) p2 = i;
    }
    cout << p1 + p2 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
