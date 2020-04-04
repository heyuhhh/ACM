/*
 * Author:  heyuhhh
 * Created Time:  2020/4/4 11:30:23
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
const int N = 50 + 5;

int _;
int n, k;
int a[N][N];

int sum(int n, int i) {
    return (2 * n - i + 1) * i / 2;
}

bool dfs(int x) {
    
}

void run() {
    ++_;
    cin >> n >> k;
    int now = n;
    for(int i = n; i >= 2; i--) {
        if(sum(now, i) >= k) {
            a[i][i] = now;
            k -= now;
            --now;
        } else {
            a[i][i] = now;
            k -= now;
        }
    }
    if(k <= n) a[1][1] = k;
    else {
        cout << "Case #" << _ << ": IMPOSSIBLE" << '\n';
        return;   
    }
    int d = 1, Max = 1;
    for(int i = 2; i <= n; i++) {
        if(a[i][i] == a[i - 1][i - 1]) {
            ++d;
            Max = max(Max, d);   
        } else d = 1;
    }
    d = Max;
    if(d == n - 1) {
        cout << "Case #" << _ << ": IMPOSSIBLE" << '\n';
        return;   
    }
    bool f = dfs(1, 1);
    if(f) {
        cout << "Case #" << _ << ": POSSIBLE" << '\n';
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                cout << a[i][j] << " \n"[j == n]; 
            }  
        } 
    } else {
        cout << "Case #" << _ << ": IMPOSSIBLE" << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    int T; cin >> T;
    while(T--) run();
    return 0;
}
