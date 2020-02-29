/*
 * Author:  heyuhhh
 * Created Time:  2020/2/28 19:20:47
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
const int N = 1e5 + 5;

void run(){
    int n, m, k;
    cin >> n >> m >> k;
    vector <vector <int> > a(n, vector <int> (m));
    vector <int> rows(n), cols(m);
    int all = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> a[i][j];
            all += a[i][j];
            rows[i] += a[i][j];
            cols[j] += a[i][j];
        }   
    }
    if(k > min(n, m)) {
        cout << all << '\n';
        return;   
    }
    vector <int> f(1 << n);
    int ans = 0;
    auto calc = [&] (vector <int>& v, int c) {
        int res = 0;
        for(auto it : v) res += a[it][c];
        return res;
    };
    for(int i = 0; i < 1 << n; i++) {
        vector <int> row, g(m + 1, 0);
        for(int j = 0; j < n; j++) {
            if(i >> j & 1) {
                f[i] += rows[j];
                row.push_back(j);
            }
        }
        if(sz(row) > k) continue;
        for(int j = 0; j < m; j++) {
            for(int t = min(k - sz(row), j + 1); t >= 1; t--) {
                g[t] = max(g[t], g[t - 1] + cols[j] - calc(row, j));
            }
        }
        //dbg(i, f[i]);
        for(int j = 1; j <= m; j++) {
            ans = max(ans, f[i] + g[j]);
            //dbg(j, g[j]);
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
