/*
 * Author:  heyuhhh
 * Created Time:  2019/12/21 20:39:59
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
const int N = 2000 + 5;

int n, m;
int a[N], b[N];

void run(){
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];
    sort(a + 1, a + n + 1);
    sort(b + 1, b + n + 1);
    int ans = INF;
    for(int i = 0; i < n; i++) {
        int x = -1, ok = 1;
        for(int j = 1; j <= n; j++) {
            int p = j, q = (j + i - 1) % n + 1;
            int d = (b[p] - a[q] + m) % m;
            if(x == -1) x = d;
            else if(x != d) ok = 0;
        }   
        if(ok) ans = min(ans, x);
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
