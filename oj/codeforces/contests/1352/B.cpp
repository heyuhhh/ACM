/*
 * Author:  heyuhhh
 * Created Time:  2020/5/10 0:08:33
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

void run() {
    int n, k; cin >> n >> k;
    if (n & 1) {
        if (k & 1 && n >= k) {
            cout << "YES" << '\n';
            for (int i = 1; i <= k - 1; i++) cout<< 1 << ' ';
            cout << n - (k - 1) << '\n';
        } else {
            cout << "NO" << '\n';   
        }
    } else {
        if (k & 1) {
            if (2 * (k - 1) < n) {
                cout << "YES" << '\n';
                for (int i = 1; i < k; i++) cout << 2 << ' ';
                cout << n - 2 * (k - 1) << '\n';
            } else {
                cout << "NO" << '\n';   
            }
        } else {
            if (n >= k) {
                cout << "YES" << '\n';
                for (int i = 1; i < k; i++) cout << 1 << ' ';
                cout << n - (k - 1) << '\n';               
            } else {
                cout << "NO" << '\n';   
            }
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
