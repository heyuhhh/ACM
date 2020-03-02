/*
 * Author:  heyuhhh
 * Created Time:  2020/2/17 20:53:27
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
int f[N], ans[N];
bool chk[N];

void run(){
    memset(chk, 0, sizeof(chk));
    int Min = 1;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> f[i];
    while(1) {
        int fir = -1;
        for(int i = 1; i <= n; i++) {
            if(!chk[i]) {
                if(f[i] == -1) f[i] = 1;
                fir = i; break;
            }
        }
        if(fir == -1) break;
        for(int i = n; i >= 1; i--) if(!chk[i]) {
            if(f[i] == 1) {
                chk[i] = true;
                ans[i] = Min++;
            } else if(f[i] > 1) {
                f[i] -= 1; 
            }
        }
    }
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
