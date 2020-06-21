/*
 * Author:  heyuhhh
 * Created Time:  2020/6/21 7:35:28
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
const int N = 2e3 + 5;

void run() {
    int n; cin >> n;
    vector <int> a(2 * n);
    for (int i = 0; i < 2 * n; i++) {
        cin >> a[i];
    }
    for (int x = 2; x < N; x++) {
        vector <vector<int>> v(N);
        vector <pii> ans;
        for (int i = 0; i < 2 * n; i++) {
            int t = (a[i] % x);
            if (sz(v[(x - t) % x])) {
                ans.push_back(MP(v[(x - t) % x].back(), i + 1));
                v[(x - t) % x].pop_back();
            } else {
                v[t].push_back(i + 1);
            }
        }
        int cnt = 0;
        for (int i = 0; i < N; i++) {
            cnt += sz(v[i]);
        }
        if (cnt == 0 || cnt == 2) {
            if (cnt == 0) ans.pop_back();
            for (auto it : ans) {
                cout << it.fi << ' ' << it.se << '\n';
            }
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    int T; cin >> T; while(T--)
    run();
    return 0;
}
