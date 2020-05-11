/*
 * Author:  heyuhhh
 * Created Time:  2020/5/11 10:42:59
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

int n;
ll k;
int base[N], a[N];

int tmp[N << 1], res[N];

void Iter(int x, int* a) {
    for (int i = 1;  i<= n; i++) {
        tmp[2 * i - 1] = i;
        tmp[2 * i] = 0;
    }
    int p = 1;
    for (int i = 1; i <= x; i++) {
        while (tmp[p] == 0) ++p;
        swap(tmp[p], tmp[(i + 1) * 2]);
    }
    int t = 0;
    for (int i = 1; i <= 2 * n; i++) {
        if (tmp[i] > 0) {
            a[++t] = tmp[i];
        }
    }
}

void mul(int* a, int* b) {
    for (int i = 1; i <= n; i++) {
        res[i] = a[b[i]];
    }
    for (int i = 1; i <= n; i++) {
        a[i] = res[i];
    }
}

void run() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        base[i] = a[i] = i;
    }
    ll t = k / (n - 1), r = k % (n - 1);
    Iter(n - 1, base);
    while (t) {
        if (t & 1) mul(a, base);
        mul(base, base);
        t >>= 1;
    }
    Iter(r, a);
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " \n"[i == n];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
