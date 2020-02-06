/*
 * Author:  heyuhhh
 * Created Time:  2020/2/4 22:59:21
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
const int N = 2e5 + 5;

int n, a, b, k;
int h[N];

void run(){
    int ans = 0;
    vector <int> v;
    for(int i = 1; i <= n; i++) {
        cin >> h[i];
        int r = (h[i] - 1) % (a + b) + 1;
        if(r <= a) {
            ++ans;
        } else {
            int need = (r - 1) / a;
            v.push_back(need);
        }
    }
    sort(all(v));
    for(auto it : v) {
        if(k >= it) k -= it, ++ans;   
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    while(cin >> n >> a >> b >> k) run();
    return 0;
}
