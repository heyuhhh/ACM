/*
 * Author:  heyuhhh
 * Created Time:  2020/6/9 23:22:06
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

typedef pair <vector <int>, vector<pii>> result;

result get(string& s) {
    int n = s.length();
    vector <int> a, sum(n, -1);
    for (int i = 0, j; i < n; i = j + 1) {
        j = i;
        if (s[i] >= '0' && s[i] <= '9') {
            int x = 0;
            while (j < n && s[j] >= '0' && s[j] <= '9') {
                x = x * 10 + (s[j] - '0');
                ++j;
            }
            sum[j - 1] = sz(a);
            a.push_back(x);
        }
    }
    vector <pii> seg;
    for (int i = 0, j; i < n; i = j + 1) {
        j = i;
        if (s[i] != 's') continue;
        int cnt = 0;
        while (j < n && (s[j] < '0' || s[j] > '9')) {
            if (s[j] == '(') ++cnt;
            ++j;
        }
        int L = INF, R = -1;
        while (j < n && cnt > 0) {
            if (s[j] == '(') ++cnt;
            if (s[j] == ')') --cnt;
            if (sum[j] != -1) {
                L = min(L, sum[j]);
                R = max(R, sum[j]);
            }
            ++j;
        }
        if (L > R) continue;
        sort(a.begin() + L, a.begin() + R + 1);
        if (s[i + 1] == 'h' && a[L] != a[R]) {
            seg.push_back(MP(L, R));
        }
    }
    return MP(a, seg);
}

void run() {
    string s, t; cin >> s >> t;
    result A = get(s), B = get(t);
    if (A == B) {
        cout << "equal" << '\n';
    } else {
        cout << "not equal" << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
