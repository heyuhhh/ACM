/*
 * Author:  heyuhhh
 * Created Time:  2020/5/10 21:13:22
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
    vector <pii> z(n), f(n), o(n);
    for (int i = 1; i <= n; i++) {
        string s; cin >> s;
        int k = s.length();
        int x = 0, Min = INF;
        for (int j = 0; j < k; j++) {
            if (s[j] == '(') ++x;
            else --x;
            Min = min(Min, x);
        }
        if (x > 0) z.push_back(MP(Min, x));
        else if (x == 0) o.push_back(MP(Min, x));
        else f.push_back(MP(Min, x));
    }
    sort(all(z), [&] (pii A, pii B) {
        return A.fi > B.fi;
    });
    sort(all(f), [&] (pii A, pii B) {
        return A.se + B.fi > A.fi + B.se;
    });
    int tot = 0;
    for (int i = 0; i < sz(z); i++) {
        pii now = z[i];
        if (tot + now.fi >= 0) {
            tot += now.se;   
        } else {
            cout << "No" << '\n';
            return;
        }
    }
    for (int i = 0; i < sz(o); i++) {
        pii now = o[i];
        if (tot + now.fi < 0) {
            cout << "No" << '\n';
            return;
        }
    }
    for (int i = 0; i < sz(f); i++) {
        pii now = f[i];
        if (tot + now.fi >= 0) {
            tot += now.se;   
        } else {
            cout << "No" << '\n';
            return;
        } 
    }
    if (tot != 0) cout << "No" << '\n';
    else cout << "Yes" << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
