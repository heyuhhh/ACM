/*
 * Author:  heyuhhh
 * Created Time:  2020/4/10 19:16:57
 */
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
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
  void err() { std::cout << std::endl; }
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
const int N = 13;

ll dp[N][N][N][N][N];
int f[N];
int m, na, nb, nc, nd;

int find(int x) {return f[x] == x ? f[x] : f[x] = find(f[x]);}

void Union(int x, int y) {
    int fx = find(x), fy = find(y);
    if(fx != fy) f[fx] = fy;   
}

int s[N], tot;
int mp[N];

void add(ll& x, ll y) {x += y;}

void run() {
    cin >> na >> nb >> nc >> nd >> m;
    for(int i = 1; i <= 12; i++) f[i] = i;
    for(int i = 1; i <= m; i++) {
        int x, y; cin >> x >> y;
        Union(x, y);   
    }
    for(int i = 1; i <= 12; i++) {
        int fa = find(i);
        if(!mp[fa]) mp[fa] = ++tot;
        ++s[mp[fa]];
    }
    dp[0][0][0][0][0] = 1;
    for(int i = 0; i < tot; i++) {
        for(int a = 0; a <= na; a++) {
            for(int b = 0; b <= nb; b++) {
                for(int c = 0; c <= nc; c++) {
                    for(int d = 0; d <= nd; d++) {
                        int t = s[i + 1];
                        if(a + t <= na) add(dp[i + 1][a + t][b][c][d], dp[i][a][b][c][d]);
                        if(b + t <= nb) add(dp[i + 1][a][b + t][c][d], dp[i][a][b][c][d]);
                        if(c + t <= nc) add(dp[i + 1][a][b][c + t][d], dp[i][a][b][c][d]);
                        if(d + t <= nd) add(dp[i + 1][a][b][c][d + t], dp[i][a][b][c][d]);
                    }
                }   
            }
        }   
    }
    cout << dp[tot][na][nb][nc][nd] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
