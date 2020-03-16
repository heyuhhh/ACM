/*
 * Author:  heyuhhh
 * Created Time:  2020/3/13 19:00:59
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
const int N = 1000 + 5;

const string s = "XiaoQiao", t = "XiaoHuiHui";

string ss;

void run() {
    cin >> ss;
    int len = ss.length();
    int t1 = 0, t2 = 0;
    for(int i = 0; i < len; i++) {
        if(t1 < 8 && ss[i] == s[t1]) ++t1;
        if(t2 < 10 && ss[i] == t[t2]) ++t2;
    }
    if(t1 == 8 && t2 == 10) {
        cout << "Happy" << '\n';   
    } else cout << "emm" << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
