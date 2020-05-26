/*
 * Author:  heyuhhh
 * Created Time:  2020/5/24 22:33:18
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

void run() {
    int n, m;
    cin >> n >> m;
    vector <string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    string res = s[0];
    auto chk = [&] (int k) {
        for (int i = 0; i < n; i++) {
            vector <int> p;
            for (int j = 0; j < m; j++) {
                if (s[i][j] != res[j]) p.push_back(j);
            }
            if (sz(p) > 2) return false;
            if (sz(p) < 2) {
                if (sz(p) == 1) {
                    if (p[0] != k) k = -1;
                }
                continue;
            }
            if (p[0] == k || p[1] == k) {
                res[k] = s[i][k];
                k = -1;
            } else return false;
        }
        return true;
    };
    for (int k = 0; k < m; k++) {
        res = s[0];
        if (chk(k)) {
            cout << res << '\n';
            return;
        }
    }
    cout << -1 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    int T; cin >> T; while(T--)
    run();
    return 0;
}
