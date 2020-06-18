/*
 * Author:  heyuhhh
 * Created Time:  2020/6/16 23:14:00
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
    int n, m;
    string s; cin >> s;
    n = s.length();
    vector <int> cnt(26);
    for (int i = 0; i < n; i++) {
        ++cnt[s[i] - 'a'];
    }
    cin >> m;
    vector <int> b(m);
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    vector <int> fixed(m);
    for (int i = 0; i < m; i++) {
        if (b[i] == 0) {
            fixed[i] = 1;
        }
    }
    int T = 1;
    while (count(all(fixed), 0)) {
        ++T;
        vector <int> will;
        for (int i = 0; i < m; i++) {
            if (!fixed[i]) {
                int t = 0;
                for (int j = 0; j < m; j++) {
                    if (fixed[j]) {
                        t += abs(i - j);
                    }
                }
                if (t == b[i]) {
                    will.push_back(i);
                }
            }
        }
        for (auto it : will) {
            fixed[it] = T;
        }
    }
    int p = 25;
    vector <char> ans(m);
    for (int t = 1; t <= T; t++) {
        int num = 0;
        for (int i = 0; i < m; i++) {
            if (fixed[i] == t) {
                ++num;
            }
        }
        while (p >= 0 && cnt[p] < num) --p;
        for (int i = 0; i < m; i++) {
            if (fixed[i] == t) {
                ans[i] = (p + 'a');
            }
        }
        --p;
    }
    for (auto it : ans) {
        cout << it;
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    int T; cin >> T; while(T--)
    run();
    return 0;
}
