/*
 * Author:  heyuhhh
 * Created Time:  2020/3/17 16:35:58
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
const int N = 1000 + 5;

int n, m, q;
char s[N][N];
int mp[N][N];
int sum[N][N];

int find_bel(int r, int c, int x, int y) {
    if(x <= r / 2) {
        if(y <= c / 2) return 0;
        return 1;
    } else {
        if(y <= c / 2) return 2;
        return 3;
    }
}

int find(int x, int y, int v) {
    int r = 1, c = 1;
    if(x == r && y == c) return v;
    while(r < x || c < y) r <<= 1, c <<= 1;   
    int t = find_bel(r, c, x, y);
    if(t == 0) return v;
    if(t == 1) {
        y -= c / 2;
        return find(x, y, v ^ 1);
    }
    if(t == 2) {
        x -= r / 2;
        return find(x, y, v ^ 1);
    }
    if(t == 3) {
        x -= r / 2, y -= c / 2;
        return find(x, y, v);
    }
}

pii find_blo(int x, int y) {
    return MP((x + n - 1) / n, (y + m - 1) / m);
}

void run() {
    cin >> n >> m >> q;
    for(int i = 1; i <= n; i++) {
        cin >> (s[i] + 1);
        for(int j = 1; j <= m; j++) {
            mp[i][j] = (s[i][j] == '1');
            sum[i][j] = mp[i][j];
        }
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            sum[i][j] += sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
        }   
    }
    auto solve = [&] (int x, int y) {
        if(x < 1 || y < 1) return 0ll;
        pii block = find_blo(x, y);
        int r = x - n * (block.fi - 1), c = y - m * (block.se - 1);
        int t = find(block.fi, block.se, 0);
        ll res = 0;
        if(block.fi & 1) {
            if(block.se & 1) {
                res += 1ll * (block.fi - 1) * (block.se - 1) / 2 * n * m;
                res += 1ll * (block.se - 1) / 2 * r * m;
                res += 1ll * (block.fi - 1) / 2 * c * n;
                if(!t) res += sum[r][c];
                else res += r * c - sum[r][c];
            } else {
                res += 1ll * (block.fi - 1) * (block.se - 1) / 2 * n * m;
                res += 1ll * (block.fi - 1) / 2 * n * c;
                res += 1ll * (block.se - 2) / 2 * r * m;
                if(!t) res += sum[r][c];
                else res += r * c - sum[r][c];
                int t1 = find(block.fi, block.se - 1, 0);
                if(!t1) res += sum[r][m];
                else res += r * m - sum[r][m];
            }
        } else {
            if(block.se & 1) {
                res += 1ll * (block.fi - 1) * (block.se - 1) / 2 * n * m;
                res += 1ll * (block.fi - 2) / 2 * n * c;
                res += 1ll * (block.se - 1) / 2 * r * m;
                if(!t) res += sum[r][c];
                else res += r * c - sum[r][c];
                int t1 = find(block.fi - 1, block.se, 0);
                if(!t1) res += sum[n][c];
                else res += n * c - sum[n][c];
            } else {
                res += 1ll * (block.fi - 2) * (block.se - 2) / 2 * n * m;
                res += 1ll * (block.fi - 2) / 2 * n * (m + c);
                res += 1ll * (block.se - 2) / 2 * m * (n + r);
                int t1 = find(block.fi - 1, block.se - 1, 0);
                if(!t1) res += sum[n][m];
                else res += n * m - sum[n][m];
                t1 = find(block.fi - 1, block.se, 0);
                if(!t1) res += sum[n][c];
                else res += n * c - sum[n][c];
                t1 = find(block.fi, block.se - 1, 0);
                if(!t1) res += sum[r][m];
                else res += r * m - sum[r][m];
                if(!t) res += sum[r][c];
                else res += r * c - sum[r][c];               
            }
        }
        return res;
    };
    while(q--) {
        int r1, c1, r2, c2; 
        cin >> r1 >> c1 >> r2 >> c2;
        ll ans = solve(r2, c2) - solve(r1 - 1, c2) - solve(r2, c1 - 1) + solve(r1 - 1, c1 - 1);
        cout << ans << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
