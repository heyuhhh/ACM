/*
 * Author:  heyuhhh
 * Created Time:  2020/3/31 22:49:29
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
const int N = 1e5 + 5;

int k;
int a[4][4];

void run() {
    cin >> k;
    if(k == 0) {
        cout << 1 << ' ' << 1 << '\n' << 0 << '\n';
        return;   
    }
    int lim = 1;
    while(lim < 3e5) lim <<= 1;
    lim >>= 2;
    int MAX = (lim << 1) - 1;
    cout << 3 << ' ' << 3 << '\n';
    a[1][1] = MAX;
    a[2][1] = k;
    a[1][2] = lim;
    a[2][2] = lim + k;
    a[2][3] = a[3][2] = (MAX ^ lim);
    a[3][3] = MAX;
    for(int i = 1; i <= 3; i++) {
        for(int j = 1; j <= 3; j++) {
            cout << a[i][j] << ' ';
        }   cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
