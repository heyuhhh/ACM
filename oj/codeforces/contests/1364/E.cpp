/*
 * Author:  heyuhhh
 * Created Time:  2020/6/15 10:16:32
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
#include <random>
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

mt19937 rnd(time(NULL));

void run() {
    int n; cin >> n;
    auto query = [&] (int i, int j) {
        cout << "? " << i << ' ' << j << endl;
        int x; cin >> x;
        return x;
    };
    
    int high;
    for (int i = 11; i >= 0; i--) {
        if ((n - 1) >> i & 1) {
            high = i + 1;
            break;
        }
    }
    vector <int> z(high, -1);
    while (count(all(z), -1)) {
        int i = rand() % n + 1, j = rand() % n + 1;
        if (i == j) continue;
        int val = query(i, j);
        for (int k = 0; k < high; k++) {
            if (!(val >> k & 1)) {
                z[k] = i;
            }
        }
    }
    
    auto get = [&](int p) {
        int res = 0;
        for (int i = 0; i < high; i++) {
            if (z[i] == p) continue;
            int val = query(z[i], p);
            if (val >> i & 1) {
                res += 1 << i;
            }
        }
        return res;
    };
    
    vector <int> ans(n, -1);
    int zero = 1;
    int val = get(1);
    ans[0] = val;
    for (int i = 2; i <= n; i++) {
        int v = query(zero, i);
        if (v & val == v) {
            ans[i - 1] = v;
            zero = i;
            val = v;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (ans[i - 1] != -1) {
           ans[i - 1] = query(zero, i);
        } 
    }
    cout << "!";
    for (auto it : ans) {
        cout << ' ' << it;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
