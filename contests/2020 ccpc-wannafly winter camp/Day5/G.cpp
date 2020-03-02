/*
 * Author:  heyuhhh
 * Created Time:  2020/1/16 21:33:24
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
const int N = 1e6 + 5;

int MOD;
int inv[N];

void run(){
    cin >> MOD;
    inv[0] = inv[1] = 1;
    vector <pii> ans;
    int Min = INF;
    for(int i = 2; i < MOD; i++) {
        inv[i] = 1ll * (MOD - MOD / i) * inv[MOD % i] % MOD;
        if(inv[i] <= Min) {
            if(i > inv[i]) break;   
            Min = inv[i];
            ans.push_back(MP(i, inv[i]));   
        }
    }
    vector <pii> res = ans;
    reverse(all(res));
    for(auto it : res) if(it.fi != it.se) ans.push_back(MP(it.se, it.fi));
    cout << sz(ans) << '\n';
    for(auto it : ans) cout << it.fi << ' ' << it.se << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    int T; cin >> T;
    while(T--) run();
    return 0;
}
