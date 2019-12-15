/*
 * Author:  heyuhhh
 * Created Time:  2019/12/15 13:43:06
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
const int MOD = 1e9 + 7;

string s;
ll x;

void run(){
    cin >> x >> s;
    ll len = s.length(), i = 0;
    for(;; i++) {
        if(len >= x) break;
        string tmp = s.substr(i + 1);
        for(int j = 0; j < s[i] - '0' - 1; j++) s += tmp;
        len = s.length();
    }
    for(; i < x; i++) {
        len = ((i + 1) + (len - i - 1)  % MOD * (s[i] - '0') % MOD) % MOD;
    }
    if(len < 0) len += MOD;
    cout << len << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    int T; cin >> T;
    while(T--) run();
    return 0;
}
