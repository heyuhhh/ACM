/*
 * Author:  heyuhhh
 * Created Time:  2020/2/15 21:19:20
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

int n, m;
ll t[N], l[N], r[N];

void run(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> t[i] >> l[i] >> r[i];   
    }
    ll prel = m, prer = m;
    for(int i = 1; i <= n; i++) {
        int d = t[i] - t[i - 1];
        prer = min(r[i], prer + d);
        prel = max(l[i], prel - d);
        if(prel > r[i] || prer < l[i]) {
            cout << "NO" << '\n';
            return;   
        }
    }
    cout << "YES" << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    int q; cin >> q;
    while(q--) run();
    return 0;
}
