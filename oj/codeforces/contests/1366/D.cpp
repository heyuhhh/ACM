/*
 * Author:  heyuhhh
 * Created Time:  2020/6/11 23:23:11
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
const int N = 5e5 + 5, M = 2e7 + 5;

int n;

int cnt;
int p[M];
bool chk[M];
void init() {
    for(int i = 2; i < M; i++) {
        if(!chk[i]) p[++cnt] = i;
        for(int j = 1; j <= cnt && 1ll * i * p[j] < M; j++) {
            chk[i * p[j]] = 1;
            if (i % p[j] == 0) {
                break;
            }
        }
    }
} 

pii ans[N];

void run() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        int tmp = x;
        vector <int> v;
        for (int j = 1; j <= cnt; j++) {
            if (1ll * p[j] * p[j] > x) {
                break;
            }
            if (x % p[j] == 0) {
                int t = 1;
                while (x % p[j] == 0) {
                    x /= p[j];
                    t *= p[j];
                }
                v.push_back(t);
            }
        }
        if (x > 1) {
            v.push_back(x);
        }
        if (sz(v) < 2) {
            v = {-1, -1};
        } else {
            v = {v[0], tmp / v[0]};
        }
        ans[i] = MP(v[0], v[1]);
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i].fi << " \n"[i == n];
    }
    for (int i = 1; i <= n; i++) {
        cout << ans[i].se << " \n"[i == n];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    init();
    run();
    return 0;
}
