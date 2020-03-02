/*
 * Author:  heyuhhh
 * Created Time:  2020/2/10 11:02:03
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
#define MP make_pair
#define fi first
#define se second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define INF 0x3f3f3f3f
#define Local
#ifdef Local
  #define dbg(args...) do { cout << #args << " -> "; err(args); } while (0)
  void err() { std::cout << '\n'; }
  template<typename T, typename...Args>
  void err(T a, Args...args) { std::cout << a << ' '; err(args...); }
#else
  #define dbg(...)
#endif
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
//head
const int N = 2e5 + 5;

int n;
int a[N], p[N];

int maxv[N << 2], minv[N << 2], lz[N << 2];
ll sumv[N << 2];

void tag(int o, int l, int r, int v) {
    lz[o] = minv[o] = maxv[o] = v;
    sumv[o] = 1ll * (r - l + 1) * v;   
}

void push_up(int o) {
    maxv[o] = max(maxv[o << 1], maxv[o << 1|1]);
    minv[o] = min(minv[o << 1], minv[o << 1|1]);
    sumv[o] = sumv[o << 1] + sumv[o << 1|1];   
}

void push_down(int o, int l, int r) {
    if(lz[o] != -1) {
        int mid = (l + r) >> 1;
        tag(o << 1, l, mid, lz[o]);
        tag(o << 1|1, mid + 1, r, lz[o]);
        lz[o] = -1;
    }   
}

void build(int o, int l, int r) {
    lz[o] = -1;
    if(l == r) {
        minv[o] = maxv[o] = l - 1;
        sumv[o] = l - 1;
        return;
    }   
    int mid = (l + r) >> 1;
    build(o << 1, l, mid); 
    build(o << 1|1, mid + 1, r);
    push_up(o);
}

void update(int o, int l, int r, int L, int R, int v) {
    if(L <= l && r <= R) {
        if(minv[o] >= v) return;
        if(maxv[o] < v) {
            tag(o, l, r, v);
            return;
        }
    }
    push_down(o, l, r);
    int mid = (l + r) >> 1;
    if(L <= mid) update(o << 1, l, mid, L, R, v);
    if(R > mid) update(o << 1|1, mid + 1, r, L, R, v);
    push_up(o);
}

void run(){
    memset(p, 0, sizeof(p));
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i], p[a[i]] = i;
    build(1, 1, n);
    ll ans = 0;
    for(int i = N - 1; i >= 1; i--) {
        int a = N, b = N, c = -N, d = -N;
        for(int j = i; j < N; j += i) if(p[j]) {
            if(a > p[j]) {
                b = a, a = p[j];
            } else if(b > p[j]) b = p[j];
            if(d < p[j]) {
                c = d, d = p[j];   
            } else if(c < p[j]) c = p[j];
        }
        if(b == N) continue;
        ll last = sumv[1];
        if(b < n) update(1, 1, n, b + 1, n, n);
        update(1, 1, n, a + 1, b, d - 1);
        update(1, 1, n, 1, a, c - 1);
        ans += (sumv[1] - last) * i;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    int T; cin >> T;
    while(T--) run();
    return 0;
}
