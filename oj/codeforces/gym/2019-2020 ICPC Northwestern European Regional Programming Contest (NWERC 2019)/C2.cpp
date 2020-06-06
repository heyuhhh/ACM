/*
 * Author:  heyuhhh
 * Created Time:  2020/5/26 14:56:02
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
const int N = 1e4 + 5;

int n;
struct node {
    int l, r;
} a[N];

int p;
int x[N], cnt[N];

void run() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].l >> a[i].r;
    }
    cin >> p;
    for (int i = 1; i <= p; i++) {
        cin >> x[i];
    }
    for (int i = 1; i <= p; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[j].l <= x[i] && x[i] <= a[j].r) {
                ++cnt[j];
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (cnt[i] > 2) {
            cout << "impossible" << '\n';
            return;
        }
    }
    vector <int> ans;
    for (int i = 1; i <= n; i++) {
        if (cnt[i] == 2) {
            continue;
        } 
        if (cnt[i] == 0) {
            int p1 = a[i].l, p2 = a[i].r;
            if (cnt[i - 1] == 2) ++p1;
            if (a[i + 1].l == p2) {
                if (cnt[i + 1] == 2) --p2;
                else ++cnt[i + 1];
            }
            ans.push_back(p1);
            ans.push_back(p2);
        } else {
            int p1 = a[i].r;
            for (int j = 1; j <= p; j++) {
                if (x[j] == p1) {
                    --p1;
                    break;
                }
            }
            if (a[i + 1].l == p1) {
                if (cnt[i + 1] == 2) --p1;
                else ++cnt[i + 1];
            }
            ans.push_back(p1);
        }
        cnt[i] = 2;
    }
    sort(all(ans));
    cout << sz(ans) << '\n';
    for (int i = 0; i < sz(ans); i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
