/*
 * Author:  heyuhhh
 * Created Time:  2020/5/23 14:57:55
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

unsigned long long k1, k2;
unsigned long long CoronavirusBeats() {
    unsigned long long k3 = k1, k4 = k2;
    k1 = k4;
    k3 ^= k3 << 23;
    k2 = k3 ^ k4 ^ (k3 >> 17) ^ (k4 >> 26);
    return k2 + k4;
}
struct Point {
    unsigned long long x, y, z;
    int id;   
}a[N];

vector <int> G[N];
int in[N], ans[N];

void run() {
    int n;
    cin >> n >> k1 >> k2;
    for (int i = 1; i <= n; ++i) {
        unsigned long long x, y, z;
        x = CoronavirusBeats();
        y = CoronavirusBeats();
        z = CoronavirusBeats();
        a[i] = Point{x, y, z, i};
    }
    sort(a + 1, a + n + 1, [&](Point A, Point B) {
        if (A.x != B.x) return A.x < B.x;
        if (A.y != B.y) return A.y < B.y;
        return A.z < B.z;
    });
    auto ok = [&] (Point A, Point B) {
        return A.x <= B.x && A.y <= B.y && A.z <= B.z;
    };
    set <int> s;
    s.insert(n);
    int sq = sqrt(n + 0.5);
    for (int i = n - 1; i >= 1; i--) {
        vector <int> t;
        for (auto j : s) {
            if (ok(a[i], a[j])) {
                int u = a[i].id, v = a[j].id;
                G[u].push_back(v);
                ++in[v];
                if (in[v] >= sq) t.push_back(j);
            }
        }
        for (auto it : t) {
            s.erase(it);
        }
        s.insert(i);
    }
    queue <int> q;
    for (auto it : s) q.push(it);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (auto v : G[u]) {
            if (--in[v] == 0) {
                ans[v] = ans[u] + 1;
                q.push(v);
            }   
        }
    }
    int res = 0;
    for (int i = 1; i <= n; i++) {
        res = max(res, ans[i] + 1);
    }
    cout << res << '\n';
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " \n"[i == n];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
