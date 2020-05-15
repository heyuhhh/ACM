/*
 * Author:  heyuhhh
 * Created Time:  2020/5/15 0:08:23
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

struct node {
    int l, len;
    bool operator < (const node &A) const {
        if (len != A.len) return len < A.len;
        return l > A.l;
    }
};

void run() {
    int n; cin >> n;
    priority_queue <node> q;
    q.push(node{1, n});
    int T = 0;
    vector <int> a(n + 1);
    while (!q.empty()) {
        ++T;
        node cur = q.top(); q.pop();
        int l = cur.l, r = cur.l + cur.len - 1;
        int m = (l + r) / 2;
        a[m] = T;
        if (cur.len & 1) {
            if (m > l) q.push(node{l, cur.len / 2});
        } else {
            if (m > l) q.push(node{l, cur.len / 2 - 1});
        }
        if (m < r) q.push(node{l + (cur.len + 1) / 2, cur.len / 2});
    }
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " \n"[i == n];
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
