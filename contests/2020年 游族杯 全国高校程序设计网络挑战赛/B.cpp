/*
 * Author:  heyuhhh
 * Created Time:  2020/5/24 18:33:37
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

int qry(string s) {
    cout << "? " << s << endl;
    int x; cin >> x;
    return x;   
}
int f;
int query(string s) {
    for (auto& it : s) it ^= f;
    return qry(s);
}

void run() {
    int n; cin >> n;
    int k = n / 2 + 1;
    f = query(string(k, '0'));
    int l = 1, r = k + 1, mid;
    while (l < r) {
        mid = (l + r) >> 1;
        if (query(string(mid, '0'))) l = mid + 1;
        else r = mid;
    }
    int m = l - 1;
    auto solve = [&] (int x, int y) {
        for (int i = y + 1; i + m - x <= k && i <= n - m; i++) {
            if (!query(string(i, '1') + string(m - x, '0'))) return i - 1;
        }
        for (int i = max(y, n - m - k + x + 1); i <= n - m; i++) {
            if (query(string(x + 1, '0') + string(n - m - i, '1'))) return i;
        }
    };
    string res = "";
    int i, j;
    for (i = 0, j = 0; i < m; i++) {
        int k = solve(i, j);
        res += string(k - j, '1');
        res += '0';
        j = k;
    }
    if (j < n - m) {
    	res += string(n - m - j, '1');
	}
    for (auto& it : res) it ^= f;
    cout << "! " << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
