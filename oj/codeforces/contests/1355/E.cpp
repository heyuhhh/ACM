/*
 * Author:  heyuhhh
 * Created Time:  2020/5/16 22:21:11
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

int n, A, R, M;
int h[N];

void run() {
    cin >> n >> A >> R >> M;
    M = min(M, A + R);
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }
    auto f = [&] (int x) {
        ll cnt_a = 0, cnt_b = 0;
        for (int i = 1; i <= n; i++) {
            if (h[i] < x) cnt_a += x - h[i];
            if (h[i] > x) cnt_b += h[i] - x;   
        }
        ll cnt_c = min(cnt_a, cnt_b);
        cnt_a -= cnt_c;
        cnt_b -= cnt_c;
        return cnt_a * A + cnt_b * R + cnt_c * M;
    };
    int l = 0, r = INF, lmid, rmid;
    while (l < r) {
        lmid = l + ((r - l) / 3);   
        rmid = r - ((r - l) / 3);
        if (f(lmid) < f(rmid)) {
            r = rmid - 1;
        } else {
            l = lmid + 1;
        }
    }
    cout << f(l) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
