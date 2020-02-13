/*
 * Author:  heyuhhh
 * Created Time:  2020/2/9 22:07:26
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
const int N = 100 + 5;

int n;
int a[N];

void run(){
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    int sum = 0, ans = 0;
    for(int i = 1; i <= n; i++) {
        if(a[i] == 0) ++ans, ++a[i];
        sum += a[i];
    }
    if(sum == 0) {
        for(int i = 1; i <= n; i++) {
            if(a[i] != -1) {
                cout << ans + 1 << '\n';   
                return;
            }
        }
        cout << ans + 2 << '\n';
    } else cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    int T; cin >> T;
    while(T--) run();
    return 0;
}
