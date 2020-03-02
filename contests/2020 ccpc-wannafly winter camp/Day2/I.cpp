/*
 * Author:  heyuhhh
 * Created Time:  2020/2/8 19:53:15
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
void pt() {std::cout << '\n'; }
template<typename T, typename...Args>
void pt(T a, Args...args) {std::cout << a << ' '; pt(args...); }
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
//head
const int N = 1500 + 5;

namespace R {
    int n;
    int w[N][N], kx[N], ky[N], py[N], vy[N], slk[N], pre[N];
    ll KM() {
        fill(kx, kx + n + 1, 0);
        fill(ky, ky + n + 1, 0);
        fill(py, py + n + 1, 0);
        for(int i = 1; i <= n; i++) 
            for(int j = 1; j <= n; j++)
                kx[i] = max(kx[i], w[i][j]);
                
        for(int i = 1; i <= n; i++) {
            fill(vy, vy + n + 1, 0);
            fill(slk, slk + n + 1, INF);
            fill(pre, pre + n + 1, 0);
            int k = 0, p = -1;
            for(py[k = 0] = i; py[k]; k = p) {
                int d = INF;
                vy[k] = 1;
                int x = py[k];
                for(int j = 1; j <= n; j++)
                    if (!vy[j]) {
                        int t = kx[x] + ky[j] - w[x][j];
                        if (t < slk[j]) { slk[j] = t; pre[j] = k; }
                        if (slk[j] < d) { d = slk[j]; p = j; }
                    }
                for(int j = 0; j <= n; j++)
                    if (vy[j]) { kx[py[j]] -= d; ky[j] += d; }
                    else slk[j] -= d;
            }
            for (; k; k = pre[k]) py[k] = py[pre[k]];
        }
        ll ans = 0;
        for(int i = 1; i <= n; i++) ans += kx[i] + ky[i];
        return ans;
    }
}

int n, m, k;
int id[N];
int t1, t2;

int get(int x, int y) {
    return (x - 1) * m + y;   
}

void run(){
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            id[get(i, j)] = ((i + j) & 1) ? ++t1 : ++t2;
        }   
    }
    for(int i = 1; i <= k; i++) {
        int x1, x2, y1, y2, w;
        cin >> x1 >> y1 >> x2 >> y2 >> w;
        if((x1 + y1) & 1) swap(x1, x2), swap(y1, y2);
        R::w[id[get(x1, y1)]][id[get(x2, y2)]] = max(R::w[id[get(x1, y1)]][id[get(x2, y2)]], w);
    }
    R::n = max(t1, t2);
    ll ans = R::KM();
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
