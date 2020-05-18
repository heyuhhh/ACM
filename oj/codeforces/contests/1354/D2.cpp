/*
 * Author:  heyuhhh
 * Created Time:  2020/5/18 22:31:33
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
const int N = (1 << 20) + 5;
const int MAX = (1 << 20);

int n, q;

struct BIT {
    int c[N];
    int lowbit(int x) {
        return x & (-x);   
    }
    void add(int x, int val) {
        for (;x < N; x += lowbit(x)) {
            c[x] += val;
        }
    }
    int kth(int k) {
        int p = 0;
        for (int i = MAX >> 1; i; i >>= 1) {
            if (c[p + i] < k) {
                k -= c[p + i];
                p += i;
            }
        }
        return p + 1;
    } 
}bit;

void run() {
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        bit.add(x, 1);
    }
    for (int i = 1; i <= q; i++) {
        int k; cin >> k;
        if (k > 0) {
            bit.add(k, 1);
        } else {
            int t = bit.kth(-k);
            bit.add(t, -1);
        }
    }
    int t = bit.kth(1);
    if (t == MAX) {
        cout << 0 << '\n';
    } else {
        cout << t << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
