/*
 * Author:  heyuhhh
 * Created Time:  2020/5/23 14:57:55
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

unsigned long long k1, k2;
unsigned long long CoronavirusBeats() {
    unsigned long long k3 = k1, k4 = k2;
    k1 = k4;
    k3 ^= k3 << 23;
    k2 = k3 ^ k4 ^ (k3 >> 17) ^ (k4 >> 26);
    return k2 + k4;
}
unsigned long long x[N], y[N], z[N];

struct Point {
    unsigned long long x, y, z;
    int id;   
}a[N], b[N];

int n;
int ans[N];

void Hash(unsigned long long* a) {
    sort(a + 1, a + n + 1);
    a[0] = unique(a + 1, a + n + 1) - a - 1;
}

int find(unsigned long long* a, unsigned long long x) {
    return lower_bound(a + 1, a + a[0] + 1, x) - a;
}

int c[N];

int lowbit(int x) {
    return x & (-x);
}
void del(int x) {
    for (int i = x; i < N; i += lowbit(i)) c[i] = 0;
}
void add(int x, int v) {
    for(int i = x; i < N; i += lowbit(i)) c[i] = max(c[i], v);
}
int query(int x) {
    int ans = 0;
    for(int i = x; i; i -= lowbit(i)) ans = max(ans, c[i]);
    return ans;
}
void cdq(int l, int r) {
    if(l == r) return ;
    int mid = (l + r) >> 1;
    cdq(l, mid);
    sort(a + l, a + mid + 1, [&](Point A, Point B) {
        return A.y < B.y;
    });
    sort(a + mid + 1, a + r + 1, [&](Point A, Point B) {
        return A.y < B.y;
    });
    int t1 = l, t2 = mid + 1;
    for(int i = l; i <= r; i++) {
        if((t1 <= mid && a[t1].y <= a[t2].y) || t2 > r) {
            add(a[t1].z, ans[a[t1].id]);
            b[i] = a[t1++];
        } else {
            ans[a[t2].id] = max(ans[a[t2].id], query(a[t2].z) + 1);
            b[i] = a[t2++];
        }
    }
    for(int i = l; i <= mid; i++) del(a[i].z);
    sort(a + mid + 1, a + r + 1, [&](Point A, Point B) {
        return A.x < B.x;
    });
    cdq(mid + 1, r);
}

void run() {
    cin >> n >> k1 >> k2;
    for (int i = 1; i <= n; ++i) {
        x[i] = CoronavirusBeats();
        y[i] = CoronavirusBeats();
        z[i] = CoronavirusBeats();
        a[i] = Point{x[i], y[i], z[i], i};
    }
    Hash(x), Hash(y), Hash(z);
    for (int i = 1; i <= n; i++) {
        a[i].x = find(x, a[i].x);
        a[i].y = find(y, a[i].y);
        a[i].z = find(z, a[i].z);
    }   
    sort(a + 1, a + n + 1, [&](Point A, Point B) {
        return A.x < B.x;
    });
    for (int i = 1; i <= n; i++) {
        ans[i] = 1;
    }
    cdq(1, n);
    int res = 0;
    for (int i = 1; i <= n; i++) {
        res = max(res, ans[i]);
        --ans[i];
    }
    cout << res << '\n';
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " \n"[i == n];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
