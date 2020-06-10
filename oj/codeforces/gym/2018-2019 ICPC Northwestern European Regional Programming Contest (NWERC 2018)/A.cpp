/*
 * Author:  heyuhhh
 * Created Time:  2020/6/10 14:55:43
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
#include <functional>
#include <numeric>
#include <stack>
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
    int n; cin >> n;
    vector <int> x(n), y(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    
    auto gao = [&] (vector <int>& a) {
        stack <pair <ll, int>> s;
        for (int i = 0; i < n; i++) {
            pair <ll, int> now = MP(a[i], 1);
            while (!s.empty() && s.top().fi * now.se > now.fi * s.top().se) {
                pair <ll, int> t = s.top(); s.pop();
                now.fi += t.fi;
                now.se += t.se;
            }
            s.push(now);
        }
        double res = 0.0;
        int id = n - 1;
        while (!s.empty()) {
            pair <ll, int> t = s.top(); s.pop();
            double ave = 1.0 * t.fi / t.se;
            for (int i = id; i > id - t.se; i--) {
                res += (a[i] - ave) * (a[i] - ave);
            }
            id -= t.se;
        }
        return res;
    };
    
    double ans = 0.0;
    ans += gao(x);
    ans += gao(y);
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
