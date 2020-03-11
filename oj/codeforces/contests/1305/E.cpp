/*
 * Author:  heyuhhh
 * Created Time:  2020/3/4 0:38:46
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

int n, m;

void run() {
    cin >> n >> m;
    if(n == 1) {
        if(m == 0) cout << 1 << '\n';
        else cout << -1 << '\n';   
        return;
    }
    vector <int> a;
    a.push_back(1);
    a.push_back(2);
    int now = 1, cnt = 0;
    int t = 0, p = 3;
    while(t < m) {
        if(t + now > m) {
            int r = m - t;
            --p;
            for(int i = p + 1;; i++) {
                int L = i - p, R = p;
                if((R - L + 1) / 2 == r) {
                    a.push_back(i);
                    t += r;
                    break;
                }
            }
        } else {
            a.push_back(p++);
            t += now;
            if(++cnt == 2) {
                ++now, cnt = 0;   
            }
        }
    }
    if(sz(a) > n) {
        cout << -1 << '\n';
        return;   
    }
    int s = 1e9;
    while(sz(a) < n) {
        a.push_back(s);
        s -= 50000;   
    }
    sort(all(a));
    for(auto it : a) cout << it << ' ';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
