/*
 * Author:  heyuhhh
 * Created Time:  2020/5/17 18:20:26
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

struct BIT {
    int c[N];
    int lowbit(int x) {
        return x & (-x);   
    }
    void add(int x, int v = 1) {
        for (; x < N; x += lowbit(x)) {
            c[x] += v;
        }
    }
    int query(int x) {
        int res = 0;
        for (;x ; x -= lowbit(x)) {
            res += c[x];
        }
        return res;
    }
}bit;

void run() {
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        bit.add(x);
    }
    while (q--) {
        int k; cin >> k;
        if (k > 0) {
            bit.add(k);
        } else {
            k = -k;
            int l = 1, r = N, mid;
            while (l < r) {
                mid = (l + r) >> 1;
                if (bit.query(mid) >= k) r = mid;
                else l = mid + 1;
            }
            bit.add(r, -1);
        }
    } 
    int t = bit.query(N - 1);
    if (t == 0) {
        cout << 0 << '\n';
    } else {
        for (int i = 1; i < N; i++) {
            if (bit.query(i) - bit.query(i - 1) > 0) {
                cout << i << '\n';
                break;
            }   
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
