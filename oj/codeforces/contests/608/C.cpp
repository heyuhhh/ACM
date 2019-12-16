/*
 * Author:  heyuhhh
 * Created Time:  2019/12/15 17:28:16
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

int n, sx, sy;
int d[4];

void run(){
    for(int i = 1; i <= n; i++) {
        int x, y; cin >> x >> y;
        if(x > sx) ++d[0];
        else if(x < sx) ++d[1];
        if(y > sy) ++d[2];
        else if(y < sy) ++d[3];   
    }
    int mx = *max_element(d, d + 4);
    cout << mx << '\n';
    if(d[0] == mx) {
        cout << sx + 1 << ' ' << sy << '\n';
    } else if(d[1] == mx) {
        cout << sx - 1 << ' ' << sy << '\n';
    } else if(d[2] == mx) {
        cout << sx << ' ' << sy + 1 << '\n';
    } else {
        cout << sx << ' ' << sy - 1 << '\n';
    }   
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    while(cin >> n >> sx >> sy) run();
    return 0;
}
