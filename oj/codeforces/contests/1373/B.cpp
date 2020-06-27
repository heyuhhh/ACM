/*
 * Author:  heyuhhh
 * Created Time:  2020/6/25 22:43:59
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

void run() {
    string s; cin >> s;
    int n = s.length();
    int cnt0 = 0, cnt1 = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') ++cnt0;
        else ++cnt1;
    }
    if (cnt0 == n || cnt1 == n) {
        cout << "NET" << '\n';
        return;
    }
    int cnt = 0;
    vector <int> sta;
    for (int i = 0; i < n; i++) {
        if (sz(sta) == 0) {
            sta.push_back(s[i] - '0');
        } else {
            if (sta.back() != s[i] - '0') {
                sta.pop_back();
                ++cnt;
            } else {
                sta.push_back(s[i] - '0');
            }
        }
    }
    if (cnt & 1) {
        cout << "DA" << '\n';
    } else {
        cout << "NET" << '\n';
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
