/*
 * Author:  heyuhhh
 * Created Time:  2020/6/11 15:57:13
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
const int N = 3e5 + 5, MAX = 1e6 + 5;

int n;
int cnt[MAX];
struct node {
    int c, v;
    bool operator < (const node& A)const {
        return c > A.c;
    }
};

int ans1[MAX], ans2[MAX], to[MAX];

void solve1(int* ans) {
    int k = n;
    priority_queue <node> q;
    for (int i = 1; i < MAX; i++) if (cnt[i]) {
        q.push(node {cnt[i], i});
    }
    int cur = 0;
    while (!q.empty()) {
        node now = q.top(); q.pop();
        if (k < now.c) break;
        if (to[now.v] == now.v) continue;
        cur += now.c;
        --ans[cur];
        k -= now.c;
    }
}

void solve2(int* ans) {
    int k = n;
    priority_queue <node> q;
    for (int i = 1; i < MAX; i++) if (cnt[i]) {
        q.push(node {cnt[i], i});
    }
    int cur = 0;
    while (!q.empty()) {
        node now = q.top(); q.pop();
        if (k < now.c) break;
        cur += now.c;
        if (cur != now.c) --ans[cur];
        k -= now.c;
    }   
}

void run() {
    freopen("equal.in", "r", stdin);
    freopen("equal.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        ++cnt[x];
    }
    int tot = 0;
    for (int i = 1; i < MAX; i++) if (cnt[i]) {
        ++tot;
        for (int j = i; j < MAX; j += i) {
            if (cnt[j]) {
                to[i] = j;
            }
        }
    }
    solve1(ans1), solve2(ans2);
    ans1[0] += tot, ans2[0] += tot;
    for (int i = 1; i <= n; i++) {
        ans1[i] += ans1[i - 1];
        ans2[i] += ans2[i - 1];
    }
    for (int i = 0; i <= n; i++) {
        int ans = min(ans1[i], ans2[i]);   
        cout << ans << " \n"[i == n];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
