/*
 * Author:  heyuhhh
 * Created Time:  2020/6/18 13:21:12
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
//#define Local
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

const char ss[] = {'g', 'a', 'o'};

void run() {
    string s; cin >> s;
    vector <int> p(3);
    iota(all(p), 0);
    int n;
    auto check3 = [&] (string&s, int i) {
        int j = i + 1, k = i + 2;
        if (k >= n) return false;
        return s[i] == s[j] && s[j] == s[k];
    };
    auto check2 = [&] (string&s, int i) {
        int j = i + 1;
        if (j >= n) return false;
        return s[i] == s[j];
    };
    int ans = 0;
    do {
        n = 9;
        int res = 0;
        string t = s;
        for (int k = 0; k < 3; k++) {
            int flag = 1;
            dbg(t, n);
            for (int i = 0; i < n; i++) if (t[i] == ss[p[k]]) {
                if (check3(t, i)) {
                    flag = 3;
                    break;
                } 
                if (check2(t, i)) {
                    flag = 2;
                    break;
                }
            }
            string tmp = "";
            dbg(flag);
            if (flag == 3) ++res;
            for (int i = 0; i < n; i++) {
                if (t[i] != ss[p[k]]) {
                    tmp += t[i];
                }
            }
            swap(t, tmp);       
            n = t.length();
        }
        dbg(res);
        ans = max(res, ans);
    } while (next_permutation(all(p)));
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    int T; cin >> T; while(T--)
    run();
    return 0;
}
