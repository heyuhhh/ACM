/*
 * Author:  heyuhhh
 * Created Time:  2020/1/23 20:06:31
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

int n, m;

void run(){
    vector <vector<int>> a(n, vector<int> (m)), sum(n, vector<int> (m, n));
    for(int i = 0; i < n; i++) 
        for(int j = 0; j < m; j++) 
            cin >> a[i][j];
    for(int j = 0; j < m; j++) {
        for(int i = 0; i < n; i++) {
            if(a[i][j] % m == (j + 1) % m) {
                int x = a[i][j] / m;
                if(j == m - 1) --x;
                if(x < n) --sum[(i - x + n) % n][j];
            }   
        }
    }
    ll ans = 0;
    for(int j = 0; j < m; j++) {
        int res = INF;
        for(int i = 0; i < n; i++) {
            res = min(res, sum[i][j] + i);
        }
        ans += res;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    while(cin >> n >> m) run();
    return 0;
}
