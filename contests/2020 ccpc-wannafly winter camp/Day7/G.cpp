/*
 * Author:  heyuhhh
 * Created Time:  2020/2/20 11:46:33
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
const int N = 20 + 5;

int n, m, x, y;
ll k, ans;
int a[N][N];
pii T[N];

const int dx[] = {1, -1, 0, 0, 0}, dy[] = {0, 0, 1, -1, 0};

void dfs(int cur, int x, int y, int sum) {
    if(cur == k + 1) {
        ans = max(ans, (ll)sum);
        return;
    }
    int t = 0;
    for(int i = cur - 1; i > 0; i--) {
        if(T[i] == MP(x, y)) {
            t = i; break;
        }   
    }
    T[cur] = MP(x, y); 
    if(t == 0) sum += a[x][y] + cur - 1;
    else sum += cur - t;
    for(int i = 0; i < 5; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if(nx >= 1 && nx <= n && ny >= 1 && ny <= m) {
            dfs(cur + 1, nx, ny, sum);
        }   
    }
}

void run() {
    cin >> n >> m >> x >> y >> k;
    int sum = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> a[i][j];
            sum += a[i][j];
        }
    }
    if(k > n * m) {
        int t = n * m;
        ans = sum + (t - 1) * t / 2;
        ans += 1ll * ((k - t) / t) * (t * t);
        ans += t * (k % t);
    } else {
        dfs(1, x, y, 0);
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
