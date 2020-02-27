/*
 * Author:  heyuhhh
 * Created Time:  2020/2/26 9:34:06
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
const int N = 2000 + 5;

int n;
int a[N];

void run(){
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    set <int> s;
    int ans = n;
    for(int l = 0; l <= n; l++) {
        if(s.count(a[l])) break;
        s.insert(a[l]);
        ans = min(ans, n - l);              
        set <int> t;
        for(int r = n; r > l; r--) {
            if(s.count(a[r]) || t.count(a[r])) break;
            t.insert(a[r]);
            ans = min(ans, r - l - 1);
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}