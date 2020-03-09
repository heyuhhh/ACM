/*
 * Author:  heyuhhh
 * Created Time:  2020/3/8 20:03:44
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
const int N = 1e5 + 5;

int A, B, M;
int a[N], b[N];
int x[N], y[N], c[N];

void run() {
    cin >> A >> B >> M;
    for(int i = 1; i <= A; i++) cin >> a[i];
    for(int i = 1; i <= B; i++) cin >> b[i];
    for(int i = 1; i <= M; i++) {
        cin >> x[i] >> y[i] >> c[i];   
    }
    int ans = *min_element(a + 1, a + A + 1) + *min_element(b + 1, b + B + 1);
    for(int i = 1; i <= M; i++) {
        ans = min(ans, a[x[i]] + b[y[i]] - c[i]);   
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
