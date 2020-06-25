/*
 * Author:  heyuhhh
 * Created Time:  2020/6/23 15:26:10
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
const int N = 1e5 + 5;

void run() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int h, w; cin >> h >> w;
    if (h == 1 || w == 1) {
        cout << 0 << '\n';
        return;
    }
    vector <pii> ans;
    if (w % 2 == 0) {
        for (int i = 1; i < w; i += 2) {
            for (int j = 1; j < h; j++) {
                ans.push_back(MP(j, i));
            }
            if (h > 1 && i + 1 < w) ans.push_back(MP(h - 1, i + 1));
        }
    } else if (h % 2 == 0) {
        for (int i = 1; i < h; i += 2) {
            for (int j = 1; j < w; j++) {
                ans.push_back(MP(i, j));
            }
            if (w > 1 && i + 1 < h) ans.push_back(MP(i + 1, w - 1));
        }
    } else {
        int f = 0;
        if (h > w) {
            swap(h, w);
            f = 1;
        }
        int D = 1, R = h - 1, U = w - 1, L = 1;
        int i = D, j = L;
        auto check = [&] () {
            return L <= R && D <= U && i >= D && i <= U && j >= L && j <= R;
        };
        while (1) {
            int t = sz(ans);
            while (j <= R) {
                ans.push_back(MP(i, j));
                ++j;
            }
            j = R;
            ++i;
            if (!check()) break;
            D += 2;
            while (i <= U) {
                ans.push_back(MP(i, j));
                ++i;
            }
            i = U;
            --j;
            if (!check()) break;
            R -= 2;
            while (j >= L) {
                ans.push_back(MP(i, j));
                --j;
            }
            j = L;
            --i;
            if (!check()) break;
            U -= 2;
            while (i >= D) {
                ans.push_back(MP(i, j));
                --i;
            }
            i = D;
            ++j;
            if (!check()) break;
            L += 2;
        }
        if (!f) {
            for (auto& it : ans) {
                swap(it.fi, it.se);
            }
        }
    }    
    cout << sz(ans) << '\n';
    for (auto it : ans) {
        cout << it.fi << ' ' << it.se << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
