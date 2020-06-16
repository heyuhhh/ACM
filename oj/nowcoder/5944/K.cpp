/*
 * Author:  heyuhhh
 * Created Time:  2020/6/13 15:41:01
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
const int N = 15;

int x[N], y[N];
int sg[1 << N];
bool check[2];
int a[N], tot;

void run() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    for (int s = 1; s < 1 << n; s++) {
        check[0] = check[1] = 0;
        for (int sub = s & (s - 1); sub >= 0; sub = (sub - 1) & s) {
            tot = 0;
            int t = (s ^ sub);
            for (int i = 0; i < n; i++) {
                if (t >> i & 1) {
                    a[tot++] = i;
                }
            }
            bool ok = true;
            for (int i = 2; i < tot; i++) {
                int j = a[i - 1], k = a[i - 2];
                if (1ll * (y[a[i]] - y[j]) * (x[j] - x[k]) != 1ll * (y[j] - y[k]) * (x[a[i]] - x[j])) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                check[sg[sub]] = 1;
                if (sg[sub] == 0) {
                    break;
                }
            }
            if (sub == 0) break;
        }
        if (check[0]) sg[s] = 1;
        else sg[s] = 0;
    }
    if (sg[(1 << n) - 1]) {
        cout << "zyh" << '\n';
    } else {
        cout << "fzj" << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
