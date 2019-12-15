/*
 * Author:  heyuhhh
 * Created Time:  2019/12/12 21:39:43
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

int a[3];

void run(){
    for(int i = 0; i < 3; i++) cin >> a[i];
    sort(a, a + 3);
    if(a[2] == a[1] && a[1] == a[0]) {
        cout << 0 << '\n';
        return;   
    }
    if(a[2] == a[1]) {
        --a[1], --a[2];
        if(a[0] < a[1]) ++a[0];
    }
    else if(a[0] == a[1]) {
        ++a[0], ++a[1];
        if(a[2] > a[1]) --a[2];
    }
    else --a[2], ++a[0];   
    ll ans = a[1] - a[0] + a[2] - a[0] + a[2] - a[1];
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    int T; cin >> T;
    while(T--) run();
    return 0;
}
