/*
 * Author:  heyuhhh
 * Created Time:  2020/5/9 22:50:36
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
const int N = 1e5 + 5;

int a[5] = {0, 2, 4, 1, 3};
int b[6] = {0, 2, 4, 1, 3, 5};
int c[7] = {0, 2, 4, 6, 3, 1, 5};
int d[8] = {0, 2, 4, 6, 3, 1, 5, 7};

void run() {
    int n; cin >> n;
    if (n <= 3) {
        cout << -1 << '\n';
        return;   
    }
    int r = n % 4;
    if (r == 0) {
        int cur = 0;
        for (int i = 1; i <= n / 4; i++) {
            for (int j = 1; j <= 4; j++) {
                cout << cur + a[j] << ' ';   
            }
            cur += 4;
        }   
        cout << '\n';
        return;
    }
    int cur = 0;
    for (int i = 1; i <= n / 4 - 1; i++) {
        for (int j = 1; j <= 4; j++) {
            cout << cur + a[j] << ' ';   
        }
        cur += 4;
    }
    if (r == 1) {
        for (int i = 1; i <= 5; i++) {
            cout << cur + b[i] << ' ';   
        }
        cout << '\n';
    }
    if (r == 2) {
        for (int i = 1; i <= 6; i++) {
            cout << cur + c[i] << ' ';   
        }
        cout << '\n';       
    }
    if (r == 3) {
        for (int i = 1; i <= 7; i++) {
            cout << cur + d[i] << ' ';   
        }
        cout << '\n';          
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
