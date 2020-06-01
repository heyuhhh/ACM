/*
 * Author:  heyuhhh
 * Created Time:  2020/5/31 23:56:07
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
#include <random>
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
mt19937 rnd(time(NULL));

int n, k;

int query2(vector <int>& a) {
    cout << "? " << sz(a) << '\n';
    for (auto it : a) cout << it << ' ';
    cout << endl;
    int x; cin >> x;
    return x;   
}

int query(vector <int> a) {
    sort(all(a));
    vector <int> b;
    int j = 0;
    for (int i = 1; i <= n; i++) {
        if (j >= sz(a) || i != a[j]) {
            b.push_back(i);
        } else ++j;
    }
    return query2(b);
}

void run() {
    cin >> n >> k;
    vector <int> ans(k);
    vector <vector<int>> s(k);
    for (int i = 0; i < k; i++) {
        int c; cin >> c;
        s[i].resize(c);
        for (int j = 0; j < c; j++) {
            cin >> s[i][j];
        }
        sort(all(s[i]));
    }
    int Max;
    int m = (k - 1) / 2;
    vector <int> a, b;
    for (int i = 0; i <= m; i++) {
        for (auto it : s[i]) {
            a.push_back(it);
        }   
    }
    for (int i = m + 1; i < k; i++) {
        for (auto it : s[i]) {
            b.push_back(it);
        }
    }
    int Max1 = query(a), Max2 = query(b);
    Max = max(Max1, Max2);
    if (Max1 == Max2) {
        for (int i = 0; i < k; i++) {
            ans[i] = Max1;
        }
    } else {
        function <int(int, int)> solve;
        solve = [&] (int l, int r) -> int {
            if (l == r) return l;
            int m = (l + r) >> 1;
            vector <int> a;
            for (int i = l; i <= m; i++) {
                for (auto it : s[i]) {
                    a.push_back(it);
                }
            }
            int now = query(a);
            if (now == Max) return solve(m + 1, r);
            return solve(l, m);
        };
        int t;
        if (Max1 < Max2) t = solve(0, m);
        else t = solve(m + 1, k - 1);
        for (int i = 0; i < k; i++) {
            if (i != t) ans[i] = Max;
            else ans[i] = query(s[i]);
        }              
    }
    cout << "!";
    for (auto it : ans) cout << ' ' << it;
    cout << endl;
    string ok; cin >> ok;
    if (ok != "Correct") exit(0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    int T; cin >> T; while(T--)
    run();
    return 0;
}
