/*
 * Author:  heyuhhh
 * Created Time:  2020/3/5 19:57:13
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
const int N = 5005, M = 16;

int k;
int n[M], a[M][N];
map <ll, pair<int, int>> mp;
ll S[M];
ll t;
bool f[1 << M], g[1 << M];
int pre[1 << M];
pii to[M], where[M][N];
vector <pii> way[1 << M];

void run() {
    scanf("%d", &k);
    ll sum = 0;
    for(int i = 1; i <= k; i++) {
        scanf("%d", &n[i]);
        for(int j = 1; j <= n[i]; j++) {
            scanf("%d", &a[i][j]);
            sum += a[i][j];
            mp[a[i][j]] = MP(i, j);
            S[i] += a[i][j];
        }
    }
    if(sum % k != 0) {
        cout << "NO" << '\n';
        return;
    }
    t = sum / k;
    for(int i = 1; i <= k; i++) {
        for(int j = 1; j <= n[i]; j++) {
            ll need = t - (S[i] - a[i][j]);
            where[i][j] = mp.count(need) ? mp[need] : MP(-1, -1);
        }
    }
    for(int i = 1; i <= k; i++) {
        for(int j = 1; j <= n[i]; j++) {
            pii now = MP(i, j);
            vector <pii> cyc;
            int s = 0, flag = 1;
            while(1) {
                s ^= (1 << (now.fi - 1));
                cyc.push_back(now);
                pii to = where[now.fi][now.se];
                if(to == MP(-1, -1)) {
                    flag = 0;
                    break;
                }
                now = to;
                if(s & (1 << (now.fi - 1))) {
                    if(now != MP(i, j)) flag = 0;
                    break;
                }
            }
            if(flag == 0) continue;
            way[s] = cyc;
            f[s] = 1;
        }
    }
    g[0] = true;
    for(int sta = 0; sta < 1 << k; sta++) {
        for(int s = sta; s; s = (s - 1) & sta) {
            if(g[sta ^ s] & f[s]) {
                g[sta] = true;
                pre[sta] = s;   
                break;
            }
        }
    }
    if(g[(1 << k) - 1] == false) cout << "NO" << '\n';
    else {
        cout << "YES" << '\n';   
        int now = (1 << k) - 1;
        while(now) {
            int p = pre[now];
            for(auto it : way[p]) {
                pii go = where[it.fi][it.se];
                to[go.fi] = MP(a[go.fi][go.se], it.fi);
            }
            now -= p;
        }
        for(int i = 1; i <= k; i++) {
            cout << to[i].fi << ' ' << to[i].se << '\n';
        }
    }
}

int main() {
    run();
    return 0;
}
