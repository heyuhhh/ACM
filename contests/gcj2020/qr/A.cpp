/*
 * Author:  heyuhhh
 * Created Time:  2020/4/4 10:14:28
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
const int N = 100 + 5;

int n;
int a[N][N];
int _;

void run() {
    ++_;
    cin >> n;
    int sum = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> a[i][j];
            if(i == j) sum += a[i][j];
        }   
    }
    int rows = 0, cols = 0;
    for(int i = 1; i <= n; i++) {
        vector <int> v(n + 1, 0);
        for(int j = 1; j <= n; j++) {
            if(v[a[i][j]] > 0) {
                rows++; break;
            }   
            ++v[a[i][j]];
        }
    }
    for(int j = 1; j <= n; j++) {
        vector <int> v(n + 1, 0);
        for(int i = 1; i <= n; i++) {
            if(v[a[i][j]] > 0) {
                cols++; break;   
            }
            ++v[a[i][j]];
        }   
    }
    cout << "Case #" << _ << ": ";
    cout << sum << ' ' << rows << ' ' << cols << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    int T; cin >> T;
    while(T--) run();
    return 0;
}
