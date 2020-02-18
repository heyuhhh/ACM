/*
 * Author:  heyuhhh
 * Created Time:  2020/2/13 22:39:33
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
const int N = 1e5 + 5;

int n;
int a[N];

void run(){
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    a[n + 1] = 0;
    int Max = -INF, Min = INF, d = -INF;
    for(int i = 1; i <= n; i++) {
        if(a[i] >= 0 && (a[i - 1] == -1 || a[i + 1] == -1)) {
            if(a[i] < Min) {
                Min = a[i];   
            }
            if(a[i] > Max) {
                Max = a[i];   
            }
        }   
        if(i > 1 && a[i - 1] >= 0 && a[i] >= 0) {
            d = max(d, abs(a[i - 1] - a[i]));
        }
    }
    if(Max == -INF) {
        cout << 0 << ' ' << 0 << '\n';   
    } else {
        d = max(d, (Max - Min + 1) / 2);
        cout << d << ' ' << (Min + Max) / 2 << '\n';
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
