/*
 * Author:  heyuhhh
 * Created Time:  2020/6/9 15:25:32
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
const int N = 20 + 5;

int n;
string s;
int d;

void sayNo() {
    cout << "impossible" << '\n';
    exit(0);   
}

void run() {
    cin >> s;
    n = s.length();
    if (n >= 3 && s[n - 1] == s[n - 3]) {
        if (s[n - 1] == 'L' && s[n - 2] == 'R') sayNo();
        if (s[n - 1] == 'R' && s[n - 2] == 'L') sayNo();
        if (s[n - 1] == 'U' && s[n - 2] == 'D') sayNo();
        if (s[n - 1] == 'D' && s[n - 2] == 'U') sayNo();
    }
    d = 1;
    int x = 0, y = 0;
    vector <pii> ans;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'R') {
            x = d;
            ans.push_back(MP(x + 1, y));
        }
        if (s[i] == 'L') {
            x = -d;
            ans.push_back(MP(x - 1, y));
        }
        if (s[i] == 'D') {
            y = -d;
            ans.push_back(MP(x, y - 1));
        }
        if (s[i] == 'U') {
            y = d;
            ans.push_back(MP(x, y + 1));
        }
        if (i + 1 < n) {
            if (s[i] == 'L' && s[i + 1] == 'R') {}
            else if (s[i] == 'R' && s[i + 1] == 'L') {}
            else if (s[i] == 'U' && s[i + 1] == 'D') {}
            else if (s[i] == 'D' && s[i + 1] == 'U') {}
            else d += 2;
        }
    }
    
    cout << -x << ' ' << -y << '\n';
    sort(all(ans));
    ans.erase(unique(all(ans)), ans.end());
    cout << sz(ans) << '\n';
    for (auto it : ans) {
        cout << it.fi - x << ' ' << it.se - y << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
