/*
 * Author:  heyuhhh
 * Created Time:  2020/2/12 15:22:56
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
const int N = 5e5 + 5;

int n, m;
int a[N], b[N], c[N];
map <int, pii> mp[N];
int f[N], last[N];

void run(){
    for(int i = 1; i <= n; i++) f[i] = 1;
    for(int i = 1; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    for(int i = 1; i <= m; i++) cin >> c[i];
    for(int i = m; i >= 1; i--) {
        int u = a[c[i]], v = b[c[i]];
        last[c[i]] = f[u] = f[v] = f[u] + f[v] - last[c[i]];
    }
    cout << f[1];
    for(int i = 2; i <= n; i++) cout << " " << f[i];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    while(cin >> n >> m) run();
    return 0;
}
