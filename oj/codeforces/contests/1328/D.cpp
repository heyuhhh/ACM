/*
 * Author:  heyuhhh
 * Created Time:  2020/3/27 8:52:24
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

int n;
int t[N];

void run() {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> t[i];
    t[0] = t[n];
    bool same = true;
    for(int i = 1; i <= n; i++) {
        if(t[i] != t[i - 1]) same = false;
    }
    if(same) {
        cout << 1 << '\n';
        for(int i = 1; i <= n; i++) cout << 1 << " \n"[i == n];
        return;   
    }
    int p;
    for(int i = 1; i <= n; i++) if(t[i] == t[i - 1]) {
        same = true, p = i;
    }
    if(!same && (n & 1)) {
        cout << 3 << '\n';
        for(int i = 1; i < n; i++) {
            cout << (i % 2 + 1) << ' ';   
        }
        cout << 3 << '\n';
        return;
    }
    vector <int> ans(n + 1);
    for(int i = 1; i <= n; i++) ans[i] = (i - 1) % 2 + 1;
    if(t[1] != t[n] && ans[1] == ans[n]) {
        for(int i = p; i <= n; i++) ans[i] = 3 - ans[i];
    }
    cout << 2 << '\n';
    for(int i = 1; i <= n; i++) cout << ans[i] << " \n"[i == n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    int T; cin >> T;
    while(T--) run();
    return 0;
}
