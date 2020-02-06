/*
 * Author:  heyuhhh
 * Created Time:  2019/12/12 22:07:41
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
const int N = 2e5 + 5;

int n;
int a[N];
int dp1[N], dp2[N];

void run(){
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) dp1[i] = dp2[i] = 1;
    int ans = 0;
    for(int i = 2; i <= n; i++) {
        if(a[i] > a[i - 1]) dp1[i] = dp1[i - 1] + 1;
        ans = max(ans, dp1[i]);
    }
    for(int i = n - 1; i >= 1; i--) {
        if(a[i] < a[i + 1]) dp2[i] = dp2[i + 1] + 1;   
    }
    for(int i = 2; i < n; i++) {
        if(a[i + 1] > a[i - 1]) ans = max(ans, dp1[i - 1] + dp2[i + 1]);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    while(cin >> n) run();
    return 0;
}
