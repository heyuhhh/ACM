/*
 * Author:  heyuhhh
 * Created Time:  2020/3/4 23:22:56
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
#include <assert.h>
#define MP make_pair
#define fi first
#define se second
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define INF 0x3f3f3f3f
#define Local
#ifdef Local
  #define dbg(args...) do { cout << #args << " -> "; err(args); } while (0)
  void err() { std::cout << '\n'; }
  template<typename T, typename...Args>
  void err(T a, Args...args) { std::cout << a << ' '; err(args...); }
  template <template<typename...> class T, typename t, typename... A> 
  void err(const T <t> &arg, const A&... args) {
  for (auto &v : arg) std::cout << v << ' '; err(args...); }
#else
  #define dbg(...)
#endif
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
//head
const int N = 5000 + 5;

int n;
string s;

void run() {
    cin >> n >> s;
    pair <string, int> ans(s, 1);
    for(int i = n - 1; i >= 0; i--) {
        string S = s.substr(i);
        int len = n - i;
        string T = s.substr(0, i);
        if(len & 1) reverse(all(T));
        string res = S + T;
        if(res <= ans.fi) {
            ans = MP(res, i + 1);
        }
    }
    cout << ans.fi << '\n' << ans.se << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    int T; cin >> T;
    while(T--) run();
    return 0;
}
