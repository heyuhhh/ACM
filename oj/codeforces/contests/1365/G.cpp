/*
 * Author:  heyuhhh
 * Created Time:  2020/6/8 19:27:10
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
const int N = 1000 + 5, P = 13;

void run() {
    int n;
    cin >> n;
    vector <vector <int>> bit(P);
    vector <int> change(n);
    int k = 0;
    for (int i = 0; i < 1 << P; i++) {
        if (__builtin_popcount(i) != P / 2) continue;
        for (int j = 0; j < P; j++) {
            if (!(i >> j & 1)) {
                bit[j].push_back(k + 1);
            }
        }   
        change[k++] = i;
        if (k == n) break;
    }
    auto query = [&] (vector <int>& q) {
        cout << '?' << ' ' << sz(q);
        for (auto it : q) {
            cout << ' ' << it;
        }
        cout << '\n' << endl;
        ll t; cin >> t;
        return t;
    };
    vector <ll> val(P);
    for (int i = 0; i < P; i++) {
        if (sz(bit[i])) {
            val[i] = query(bit[i]);
        }
    }
    vector <ll> A(n);
    for (int i = 0; i < n; i++) {
        int x = change[i];
        for (int j = 0; j < P; j++) {
            if (x >> j & 1) {
                A[i] |= val[j];
            }
        }
    }
    cout << "!";
    for (int i = 0; i < n; i++) {
        cout << ' ' << A[i];
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
