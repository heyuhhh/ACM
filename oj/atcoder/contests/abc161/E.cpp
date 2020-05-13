/*
 * Author:  heyuhhh
 * Created Time:  2020/5/13 17:07:47
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
const int N = 2e5 + 5;

int n, k, c;
char s[N];
int nxt[N], last[N];

void run() {
    cin >> n >> k >> c;
    cin >> (s + 1);
    int t = 0;
    int now;
    for (int i = 1, j; i <= n; i = j) {
        now = i;
        j = i + c + 1;
        while (j <= n && s[j] == 'x') ++j;
        if (j <= n) {
            nxt[i] = j;
            last[j] = i;
            ++t;
        }
    }
    ++t;
    if (t != k) {
        return;
    }
    vector <int> pre(n + 2);
    for (int i = 1; i <= n + 1; i++) {
        pre[i] = pre[i - 1] + (s[i] == 'o');
    }
    vector <int> ans;
    int rb = n + 1;
    for (int i = now; i; i = last[i]) {
        if (rb == i || pre[rb] - pre[i] == 0) {
            ans.push_back(i);
        }
        for (int j = min(rb, i + c); j >= i; j--) {
            if (s[j] == 'o') {
                rb = j - c - 1;
                break;
            }
        }
    }
    sort(all(ans));
    for (auto it : ans) cout << it << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
