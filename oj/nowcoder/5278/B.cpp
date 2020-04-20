/*
 * Author:  heyuhhh
 * Created Time:  2020/4/18 12:42:34
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
const int N = 1e5 + 5;

void run() {

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
    int n; cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i].day >> a[i].num >> a[i].t;
    }   
    sort(a + 1, a + n + 1);
    vector <p> ans;
    for(int i = 1; i <= n; i++) if(a[i].t >= 38.0) {
        ans.push_back(a[i]);   
    }
    cout << sz(ans) << '\n';
    for(auto it : ans) {
        cout << it.day << ' ' << it.num << ' ' << it.t << '\n';   
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(1);
    run();
    return 0;
}