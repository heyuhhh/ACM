/*
 * Author:  heyuhhh
 * Created Time:  2019/12/10 21:14:22
 * 将阶乘用斯特林公式表示为较易求解的式子
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

bool chk(double x) {
    return 0.5 * log(2 * 3.1415926 * x) + x * log(x) - x <= pow(2, n) * log(2);
}

void run(){
    if(n == 0) return;
    n = (n - 1940) / 10 * 10 / 10;
    double l = 1, r = 1000000000000000, mid;
    for(int i = 0; i < 1000; i++) {
        mid = (l + r) / 2;
        if(chk(mid)) l = mid;
        else r = mid;   
    }
    cout << (ll)l << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    while(cin >> n) run();
    return 0;
}
