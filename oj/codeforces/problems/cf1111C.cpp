/*
 * Author:  heyuhhh
 * Created Time:  2019/11/13 10:12:42
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
const int N = 1e5 + 5;

int n, k, A, B;
int rt[1], ls[N * 40], rs[N * 40], sum[N * 40];
int tot;
ll ans[N * 40];

void upd(int &o, int l, int r, int p) {
    if(!o) o = ++tot;
    ++sum[o];
    if(l == r) return;
    int mid = (l + r) >> 1;
    if(p <= mid) upd(ls[o], l, mid, p);
    else upd(rs[o], mid + 1, r, p);
}

void dfs(int o, int l, int r) {
    if(!o) {
        ans[o] = A;
        return;
    }
    ans[o] = 1ll * B * sum[o] * (r - l + 1);
    int mid = (l + r) >> 1;
    if(l != r) {
        dfs(ls[o], l, mid); dfs(rs[o], mid + 1, r);
        ans[o] = min(ans[o], ans[ls[o]] + ans[rs[o]]);
    }
}

void run(){
    memset(ans, INF, sizeof(ans));
    for(int i = 1; i <= k; i++) {
        int x; cin >> x;
        upd(rt[0], 1, 1 << n, x);
    }
    dfs(rt[0], 1, 1 << n);
    cout << ans[rt[0]] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    while(cin >> n >> k >> A >> B) run();
	return 0;
}
