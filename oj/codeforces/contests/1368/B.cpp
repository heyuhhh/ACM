/*
 * Author:  heyuhhh
 * Created Time:  2020/6/18 22:51:51
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

ll qpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;   
}

const string str = "codeforces";

void run() {
    long long k; cin >> k;
    int t;
    for (int i = 1;;i++) {
        if (qpow(i, 10) > k) {
            t = i - 1;
            break;
        }
    }
    for (int i = 0; i <= 10; i++) {
        ll res = 1;
        for (int j = 1; j <= i; j++) {
            res *= (t + 1);
        }
        for (int j = 1; j <= 10 - i; j++) {
            res *= (t);
        }
        if (res >= k) {
            string res = "";
            int now = 0;
            for (int j = 1; j <= i; j++) {
                res += string(t + 1, str[now++]);
            }
            for (int j = 1; j <= 10 - i; j++) {
                res += string(t, str[now++]);
            }
            cout << res << '\n';
            return;
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
