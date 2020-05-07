/*
 * Author:  heyuhhh
 * Created Time:  2020/5/7 14:02:54
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
const int N = 1e5 + 5;

int a[10], b[10], pos[10], vis[10];

void run() {
    int n, k;
    cin >> n >> k;
    int tot = 0;
    while (n) {
        a[tot++] = n % 10;
        n /= 10;
    }
    reverse(a, a + tot);
    if (k >= tot) {
        sort(a, a + tot);
        for (int i = 0; i < tot; i++) {
            if (a[i] != 0) {
                cout << a[i];
                break;
            }
        }
        for (int i = 0; i < tot; i++) {
            if (a[i] == 0) {
                cout << 0;
            }
        }
        int cnt = 0;
        for (int i = 0; i < tot; i++) {
            if (a[i] != 0 && cnt) cout << a[i];
            if (a[i] != 0) ++cnt;
        }
        cout << ' ';
        reverse(a, a + tot);
        for (int i = 0; i < tot; i++) cout << a[i];
        cout << '\n';
        return;
    }
    for (int i = 0; i < tot; i++) b[i] = i;
    int ans1 = 2e9, ans2 = -1;
    do {
        if (a[b[0]] == 0) continue;
        for (int i = 0; i < tot; i++) {
            pos[b[i]] = i;
            vis[i] = 0;
        }
        int t = 0;
        for (int i = 0; i < tot; i++) if (!vis[i]) {
            int x = i, len = 0;
            while (!vis[x]) {
                vis[x] = 1;
                x = pos[x];
                ++len;
            }
            t += len - 1;
            if (t > k) break;
        }
        if (t > k) continue;
        int res = 0;
        for (int i = 0; i < tot; i++) {
            res = res * 10 + a[b[i]];
        }
        ans1 = min(ans1, res);
        ans2 = max(ans2, res);
    } while(next_permutation(b, b + tot));
    cout << ans1 << ' ' << ans2 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    int T; cin >> T; while(T--)
    run();
    return 0;
}
