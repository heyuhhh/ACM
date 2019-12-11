/*
 * Author:  heyuhhh
 * Created Time:  2019/12/10 20:02:02
 * 第一类斯特林数，但要排除一号点独自成环的情况
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
const int N = 25;

ll s[N][N];
void init() {
    s[0][0] = 1;
    for(int i = 1; i < N; i++) {
        for(int j = 1; j <= i; j++) {
            s[i][j] = s[i - 1][j] * (i - 1) + s[i - 1][j - 1];
        }
    }
}

int n, k;

void run(){
    cin >> n >> k;
    ll tot = 1, ok = 0;
    for(int i = 1; i <= n; i++) tot *= i;
    for(int i = 1; i <= k; i++) ok += s[n][i] - s[n - 1][i - 1];
    cout << 1.0 * ok / tot << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(4);
    init();
    int T; cin >> T;
    while(T--) run();
    return 0;
}
