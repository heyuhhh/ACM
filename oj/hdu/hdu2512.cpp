/*
 * Author:  heyuhhh
 * Created Time:  2019/12/10 21:02:07
 */
// 第二类斯特林数
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
const int N = 2000 + 5, MOD = 1000;

int s[N][N];
void init() {
    s[0][0] = 1;
    for(int i = 1; i < N; i++) 
        for(int j = 1; j <= i; j++) 
            s[i][j] = (1ll * j * s[i - 1][j] % MOD + s[i - 1][j - 1]) % MOD;
}

int n;

void run(){
    cin >> n;
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        ans = (ans + s[n][i]) % MOD;   
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    init();
    int T; cin >> T;
    while(T--) run();
    return 0;
}
