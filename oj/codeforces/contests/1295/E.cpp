/*
 * Author:  heyuhhh
 * Created Time:  2020/1/30 11:39:25
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
#define INF 0x3f3f3f3f3f3f3f3f
#define Local
#ifdef Local
  #define dbg(args...) do { cout << #args << " -> "; err(args); } while (0)
  void err() { std::cout << '\n'; }
  template<typename T, typename...Args>
  void err(T a, Args...args) { std::cout << a << ' '; err(args...); }
#else
  #define dbg(...)
#endif
void pt() {std::cout << '\n'; }
template<typename T, typename...Args>
void pt(T a, Args...args) {std::cout << a << ' '; pt(args...); }
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
//head
const int N = 2e5 + 5;

int n;
int p[N], a[N], b[N];

ll minv[N << 2], lz[N << 2];

void tag(int o, ll v) {
    minv[o] += v;
    lz[o] += v;   
}

void push_down(int o) {
    if(lz[o] != 0) {
        tag(o << 1, lz[o]);
        tag(o << 1|1, lz[o]);
        lz[o] = 0;
    }   
}

void push_up(int o) {
    minv[o] = min(minv[o << 1], minv[o << 1|1]);
}

void update(int o, int l, int r, int L, int R, int v) {
    if(L <= l && r <= R) {
        tag(o, v);
        return;
    }
    push_down(o);
    int mid = (l + r) >> 1;
    if(L <= mid) update(o << 1, l, mid, L, R, v);
    if(R > mid) update(o << 1|1, mid + 1, r, L, R, v);
    push_up(o);
}

void run(){
    for(int i = 1; i <= n; i++) {
        cin >> b[i]; p[b[i]] = i;   
    }
    for(int i = 1; i <= n; i++) {
        cin >> a[b[i]];
    }
    for(int i = 1; i <= n; i++) {
        if(p[i] < n) update(1, 1, n - 1, p[i], n - 1, a[i]);   
    }
    ll ans = minv[1];
    for(int i = 1; i <= n; i++) {
        if(p[i] < n) update(1, 1, n - 1, p[i], n - 1, -a[i]);
        if(p[i] > 1) update(1, 1, n - 1, 1, p[i] - 1, a[i]);
        ans = min(ans, minv[1]);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    while(cin >> n) run();
    return 0;
}
