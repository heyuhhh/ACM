/*
 * Author:  heyuhhh
 * Created Time:  2020/6/2 20:15:44
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
const int N = 100 + 5;

pii a[3];
int mp[N][N];

void run() {
    for (int i = 0; i < 3; i++) {
        cin >> a[i].fi;
        a[i].se = i;
    }
    sort(a, a + 3);
    if (a[0].fi * a[1].fi < a[2].fi) {
        cout << -1 << '\n';
        return;
    }
    for (int i = 0; i < a[0].fi; i++) {
        mp[i][i] = 1;
    }
    int d = a[1].fi - a[0].fi;
    for (int i = 0; i < d; i++) {
        mp[a[0].fi + i][a[0].fi - 1] = 1;
    }
    d = a[2].fi - a[1].fi;
    for (int i = 0; i < a[1].fi && d; i++) {
        for (int j = 0; j < a[0].fi && d; j++) {
            if (mp[i][j]) continue;
            mp[i][j] = 1;   
            --d;
        }
    }
    cout << a[2].fi << '\n';
    if (a[0].se == 1 && a[1].se == 0) {
        for (int y = 0; y <= 100; y++) {
            for (int z = 0; z <= 100; z++) {
                if (mp[y][z]) {
                    cout << 0 << ' ' << y << ' ' << z << '\n';
                }
            }
        }
    }
    if (a[0].se == 0 && a[1].se == 1) {
        for (int y = 0; y <= 100; y++) {
            for (int z = 0; z <= 100; z++) {
                if (mp[z][y]) {
                    cout << 0 << ' ' << y << ' ' << z << '\n';
                }
            }
        }       
    }
    if (a[0].se == 1 && a[1].se == 2) {
        for (int x = 0; x <= 100; x++) {
            for (int y = 0; y <= 100; y++) {
                if (mp[y][x]) {
                    cout << x << ' ' << y << ' ' << 0 << '\n';
                }
            }
        }
    }
    if (a[0].se == 2 && a[1].se == 1) {
        for (int x = 0; x <= 100; x++) {
            for (int y = 0; y <= 100; y++) {
                if (mp[x][y]) {
                    cout << x << ' ' << y << ' ' << 0 << '\n';
                }
            }
        }       
    }
    if (a[0].se == 0 && a[1].se == 2) {
        for (int x = 0; x <= 100; x++) {
            for (int z = 0; z <= 100; z++) {
                if (mp[z][x]) {
                    cout << x << ' ' << 0 << ' ' << z << '\n';
                }
            }
        }       
    }
    if (a[0].se == 2 && a[1].se == 0) {
        for (int x = 0; x <= 100; x++) {
            for (int z = 0; z <= 100; z++) {
                if (mp[x][z]) {
                    cout << x << ' ' << 0 << ' ' << z << '\n';
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
