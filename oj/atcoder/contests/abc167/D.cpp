/*
 * Author:  heyuhhh
 * Created Time:  2020/5/10 20:13:08
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
    int n; ll k; 
    cin >> n >> k;
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i]; --a[i];
    }
    vector <int> vis(n);
    vector <int> sta, cyc;
    int x = 0;
    while (1) {
        vis[x] = 1;
        sta.push_back(x);
        x = a[x];
        if (vis[x]) {
            while (1) {
                cyc.push_back(sta.back());
                int t = sta.back();
                sta.pop_back();
                if (t == x) {
                    break;
                }
            }
            break;
        }
    }
    reverse(all(cyc));
    if (k < sz(sta)) {
        cout << sta[k] + 1 << '\n';   
    } else {
        k -= sz(sta);
        k %= sz(cyc);
        cout << cyc[k] + 1 << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
