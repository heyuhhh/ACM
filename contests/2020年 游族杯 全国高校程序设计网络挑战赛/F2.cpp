
/*
 * Author:  heyuhhh
 * Created Time:  2020/5/23 13:35:27
 */
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
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
  void err() { std::cout << std::endl; }
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
const int N = 1e6 + 5;

void run() {
    int n; cin >> n;
    vector <string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    sort(all(s));
    int ans = 0;
    auto chk = [&] (string& str) {
        int len = str.length();
        if (len > 3 && str.substr(len - 4) == ".eoj") return 1;
        return 0;        
    };
    for (int i = 0, j; i < n; i++) {
        //j = i;
        //while (j + 1 < n && s[j + 1].se >= s[j].se) ++j;
        //int k = j;
        //while (k - 1 >= i && s[k - 1].se == s[k].se) --k;
        //for (int p = k; p <= j; p++) {
            //string str = s[p].fi;
            //int len = str.length();
            //if (len > 3 && str.substr(len - 4) == ".eoj") ++ans;
        //}
        if (i == n - 1) {
            ans += chk(s[i]);
        } else {
            int l1 = s[i].length(), l2 = s[i + 1].length();
            if (l1 > l2) {
                ans += chk(s[i]);
            } else if (s[i + 1].substr(0, l1) != s[i]) {
                ans += chk(s[i]);
            }
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
