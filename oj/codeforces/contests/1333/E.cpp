/*
 * Author:  heyuhhh
 * Created Time:  2020/4/9 16:41:05
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
const int N = 500 + 5;

int now, n;
int a[N][N];

void work() {
    int t = n;
    int x, y;
    if((t & 1) == 0) {
        x = t, y = 1;
        while(1) {
            a[x][y] = ++now;
            if(++y > t) break;
        }
        x = t - 1, y = t;
        while(1) {
            a[x][y] = ++now;
            if(--x == 0) break;
        }
        --t;       
    }
    while(t > 3) {
        x = 1, y = t;
        while(1) {
            a[x][y] = ++now;
            if(++x > t) break;
        }
        x = t, y = t - 1;
        while(1) {
            a[x][y] = ++now;
            if(--y == 0) break;
        }
        --t;
        x = t, y = 1;
        while(1) {
            a[x][y] = ++now;
            if(++y > t) break;
        }
        x = t - 1, y = t;
        while(1) {
            a[x][y] = ++now;
            if(--x == 0) break;
        }
        --t;
    }
}

void run() {
    cin >> n;
    if(n <= 2) {
        cout << -1 << '\n';
        return;   
    }
    work();
    a[1][3] = ++now, a[1][1] = ++now, a[1][2] = ++now;
    a[2][2] = ++now, a[2][1] = ++now, a[3][2] = ++now;
    a[3][3] = ++now, a[2][3] = ++now, a[3][1] = ++now;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++)
            cout << a[i][j] << " \n"[j == n];   
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
