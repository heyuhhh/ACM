/*
 * Author:  heyuhhh
 * Created Time:  2020/6/19 1:01:08
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
const int N = 1e3 + 5;

int n;

int query(vector <int>& a) {
    cout << sz(a);
    for (auto it : a) {
        cout << ' ' << it;
    }
    cout << endl;
    int s; cin >> s;
    return s;
}

int answer() {
    cout << 0 << endl;
    exit(0);;
}

void run() {
    cin >> n;
    if (n <= 3) {
        answer();
    }
    int k, Max = -1;
    for (int i = 1; i <= n; i++) {
        if (n - i - (n + i - 1) / i + 1 > Max) {
            Max = n - i - (n + i - 1) / i + 1;
            k = i;
        }
    }
    vector <bool> ban(n + 1, true);
    for (int i = k; i <= n; i += k) {
        ban[i] = true;
    }
    vector <int> on(n + 1);
    while (1) {
        if (count(all(on), 0) >= Max) {
            answer();
        }
        int cnt = k;
        vector <int> q;
        for (int i = 1; i <= n && cnt; i++) {
            if (!ban[i] && !on[i]) {
                on[i] = 1;
                q.push_back(i);
                --cnt;
            }
        }
        int s = query(q);
        cnt = k;
        while (cnt--) {
            on[s] = 0;
            ++s;
            if (s > n) s -= n;
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
