/*
 * Author:  heyuhhh
 * Created Time:  2019/11/12 19:33:21
 */
#include <bits/stdc++.h>
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
void pt() {std::cout << '\n'; }
template<typename T, typename...Args>
void pt(T a, Args...args) {std::cout << a << ' '; pt(args...); }
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
//head
const int N = 4e5 + 5;

int n, q;
int tot;
int rt[1];
int lc[N * 40], rc[N * 40], sum[N * 40], lz[N * 40];

void push_up(int o) {
    sum[o] = sum[lc[o]] + sum[rc[o]];    
}
void push_down(int o, int l, int r) {
    if(lz[o] != -1) {
        if(!lc[o]) lc[o] = ++tot;
        if(!rc[o]) rc[o] = ++tot;
        int mid = (l + r) >> 1;
        sum[lc[o]] = (mid - l + 1) * lz[o];
        lz[lc[o]] = lz[o];
        sum[rc[o]] = (r - mid) * lz[o];
        lz[rc[o]] = lz[o];
        lz[o] = -1;
    }   
}
void upd(int &o, int l, int r, int L, int R, int v) {
    if(!o) o = ++tot;
    if(L <= l && r <= R) {
        if(v == 0) sum[o] = lz[o] = 0;
        else sum[o] = r - l + 1, lz[o] = 1;
        return;
    }
    push_down(o, l, r);
    int mid = (l + r) >> 1;
    if(L <= mid) upd(lc[o], l, mid, L, R, v);
    if(R > mid) upd(rc[o], mid + 1, r, L, R, v);
    push_up(o);
}

void run(){
    memset(lz, -1, sizeof(lz));
    while(q--) {
        int l, r, k; cin >> l >> r >> k;
        if(k == 1) upd(rt[0], 1, n, l, r, 1);
        else upd(rt[0], 1, n, l, r, 0);
        int ans = n - sum[rt[0]];
        cout << ans << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    while(cin >> n >> q) run();
	return 0;
}
