/*
 * Author:  heyuhhh
 * Created Time:  2020/3/3 23:20:27
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
const int N = 2e5 + 5;

int n, m;
int a[N];

void run() {
    vector <int> mod(m);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        ++mod[a[i] % m];
    }
    for(int i = 0; i < m; i++) {
        if(mod[i] > 1) {
            cout << 0 << '\n';
            return;
        }   
    }
    int ans = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = i + 1; j <= n; j++) {
            ans = 1ll * ans * abs(a[i] - a[j]) % m;
        }   
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
