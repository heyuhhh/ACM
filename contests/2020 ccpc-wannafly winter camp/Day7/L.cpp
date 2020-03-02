/*
 * Author:  heyuhhh
 * Created Time:  2020/1/18 16:25:39
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
//#define Local
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
const int N = 20 + 1;

int n, m, q;
int a[N], d[N];

int cnt[N][1 << N], tot[N], num[N], sum[N];

vector <int> rg[N];
int mark[1 << N];

int get() {
    int res = 0;
    for(int i = 1; i <= n; i++) if(a[i]) {
        res ^= (1 << (i - 1));
    }   
    return res;
}

void run() {
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        if(a[i]) cnt[i][++tot[i]] = 0;
    }
    for(int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        rg[v].push_back(u);
        d[v] ^= a[u];
    }
    memset(mark, -1, sizeof(mark));
    mark[get()] = 0;
    int len = 1 << n, s = 0;
    for(int T = 1; T < (1 << n); T++) {
        for(int u = 1; u <= n; u++) {
            if(d[u]) a[u] = 1;
            else a[u] = 0;
        }
        int tmp = get();
        if(mark[tmp] != -1) {
            s = mark[tmp];
            len = T - s;
            break;
        }
        mark[tmp] = T;
        for(int u = 1; u <= n; u++) {
            d[u] = 0;
            for(auto v : rg[u]) {
                d[u] ^= a[v];
            }
        }
        for(int i = 1; i <= n; i++) if(a[i]) {
            cnt[i][++tot[i]] = T;   
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int T = 1; T <= tot[i]; T++) {
            if(cnt[i][T] >= s) break;
            ++sum[i];
        }
    }
    //cout << "--------" << '\n';
    //for(int i = 1; i <= n; i++) cout << sum[i] << ' ' << tot[i] << '\n';
    while(q--) {
        int x; ll k; cin >> x >> k;
        if(k <= (ll)sum[x]) {
            cout << cnt[x][k] << '\n';
            continue;   
        }
        if(tot[x] == sum[x]) {
            cout << -1 << '\n';
            continue;   
        }
        k -= sum[x];
        dbg(k);
        ll ans = s + 1ll * len * ((k - 1) / (tot[x] - sum[x]));
        dbg(ans);
        int r = k - 1ll * (tot[x] - sum[x]) * ((k - 1) / (tot[x] - sum[x]));
        dbg(r, sum[x]);
        ans += cnt[x][r + sum[x]] - s;
        cout << ans << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    while(cin >> n >> m >> q) run();
    return 0;
}
