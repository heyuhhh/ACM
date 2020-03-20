/*
 * Author:  heyuhhh
 * Created Time:  2020/3/20 10:13:26
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
const int N = 3e5 + 5;

int n;
int p[N], q[N], pos[N];

int maxv[N << 2], lz[N << 2];

void tag(int o, int l, int r, ll v) {
    maxv[o] += v;
    lz[o] += v;
}

void push_up(int o) {
    maxv[o] = max(maxv[o << 1], maxv[o << 1|1]);
}

void push_down(int o, int l, int r) {
    if(lz[o] != 0) {
        int mid = (l + r) >> 1;
        tag(o << 1, l, mid, lz[o]);
        tag(o << 1|1, mid + 1, r, lz[o]);
        lz[o] = 0;   
    }
}

void update(int o, int l, int r, int L, int R, ll v) {
    if(L <= l && r <= R) {
        tag(o, l, r, v);
        return;
    }   
    push_down(o, l, r);
    int mid = (l + r) >> 1;
    if(L <= mid) update(o << 1, l, mid, L, R, v);
    if(R > mid) update(o << 1|1, mid + 1, r, L, R, v);
    push_up(o);
}

void run() {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> p[i], pos[p[i]] = i;
    for(int i = 1; i <= n; i++) cin >> q[i];
    int k = n;
    cout << k << ' ';
    update(1, 1, n, 1, pos[k], 1);
    for(int i = 1; i < n; i++) {
        update(1, 1, n, 1, q[i], -1);
        while(1) {
            int Max = maxv[1];
            if(Max <= 0) {
                update(1, 1, n, 1, pos[--k], 1);
            } else break;
        }
        cout << k << ' ';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
