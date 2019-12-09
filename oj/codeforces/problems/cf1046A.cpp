/*
 * Author:  heyuhhh
 * Created Time:  2019/11/12 20:42:29
 */
#include <bits/stdc++.h>
#define MP make_pair
#define fi first
#define se second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define INF 0x3f3f3f3f
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
const int N = 1e5 + 25;

int n, k;
struct node{
    int x, r, q;
    bool operator < (const node &A) const{
        return r > A.r;
    }
}a[N];

unordered_map <int, int> mp;
int tot;
int rt[N * 35], ls[N * 35], rs[N * 35], sum[N * 35];

void upd(int &o, int l, int r, int p, int v) {
    if(!o) o = ++tot;   
    if(l == r) {
        sum[o] += v;
        return;
    }
    int mid = (l + r) >> 1;
    if(p <= mid) upd(ls[o], l, mid, p, v);
    else upd(rs[o], mid + 1, r, p, v);
    sum[o] = sum[ls[o]] + sum[rs[o]];
}

int query(int o, int l, int r, int L, int R) {
    if(!o) return 0;
    if(L <= l && r <= R) {
        return sum[o];   
    }
    int res = 0, mid = (l + r) >> 1;
    if(L <= mid) res += query(ls[o], l, mid, L, R);
    if(R > mid) res += query(rs[o], mid + 1, r, L, R);
    return res;
}

void run(){
    for(int i = 1; i <= n; i++) cin >> a[i].x >> a[i].r >> a[i].q;
    sort(a + 1, a + n + 1);
    ll ans = 0;
    for(int i = 1; i <= n; i++) {
        int l = max(0, a[i].x - a[i].r);
        int r = a[i].x + a[i].r;
        int L = max(0, a[i].q - k);
        int R = a[i].q + k;  
        for(int j = L; j <= R; j++) {
            if(mp.find(j) == mp.end()) continue;
            ans += query(rt[mp[j]], 0, INF, l, r);
        } 
        if(mp.find(a[i].q) == mp.end()) mp[a[i].q] = ++tot;
        upd(rt[mp[a[i].q]], 0, INF, a[i].x, 1);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    while(cin >> n >> k) run();
	return 0;
}
