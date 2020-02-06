/*
 * Author:  heyuhhh
 * Created Time:  2020/2/3 0:18:18
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
const int N = 3500 + 5;

int n, m, k;
int a[N];

void run(){
    cin >> n >> m >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];
    int ans = 0;
    if(k >= m) k = m - 1;
    int d = m - k - 1;
    for(int j = 0; j <= k; j++) {
        int res = INF;
        for(int l = 1; l <= n; l++) {
            int r = l + n - d - 1;
            if(r > n) break;
            int L = l + j, R = r - (k - j);
            res = min(res, max(a[L], a[R]));
        }      
        ans = max(ans, res);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    int T; cin >> T;
    while(T--) run();
    return 0;
}
