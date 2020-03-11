/*
 * Author:  heyuhhh
 * Created Time:  2020/3/9 22:44:25
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
const int N = 30 + 5;

int n, k;
ll a[N];
ll powk[N << 1];

void run() {
    cin >> n >> k;
    for(int i = 1; i <= n; i++) cin >> a[i];
    powk[0] = 1;
    int t;
    for(int i = 1;; i++) {
        powk[i] = powk[i - 1] * k;
        if(powk[i] > 1e16) {
            t = i - 1; break;
        }
    }
    for(int i = t; i >= 0; i--) {
        ll Max = -1;
        int id;
        for(int j = 1; j <= n; j++) {
            if(a[j] > Max) {
                Max = a[j];
                id = j;
            }
        }   
        if(Max >= powk[i]) {
            a[id] -= powk[i];   
        }
    }
    for(int i = 1; i <= n; i++) {
        if(a[i] > 0) {
            cout << "NO" << '\n';
            return;
        }   
    }
    cout << "YES" << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    int T; cin >> T;
    while(T--) run();
    return 0;
}
