/*
 * Author:  heyuhhh
 * Created Time:  2020/3/19 18:08:08
 */
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <iomanip>
#include <assert.h>
#include <bitset>
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
  void err() { std::cout << '\n'; }
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
const int N = 3e4 + 5, M = 20;

int n, q;
int a[N];
vector <int> v[M];

struct Edge {
    int v, next;   
}e[N * M];
int head[N], tot;
int in[N];
void adde(int u, int v) {
    e[tot].v = v, e[tot].next = head[u], head[u] = tot++;
}

int T[N], b[N];

bitset <N> to[N];

void run() {
    cin >> n >> q;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        for(int j = 0; j < M; j++) if(a[i] >> j & 1) {
            v[j].push_back(i);
        }
    }
    memset(head, -1, sizeof(head));
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < M; j++) if(a[i] >> j & 1) {
            int t = upper_bound(all(v[j]), i) - v[j].begin();
            if(t < sz(v[j])) {
                adde(i, v[j][t]);
                ++in[v[j][t]];
            }
        }   
    }
    auto topsort = [&]() {
        queue <int> q;
        int t = 0;
        for(int i = 1; i <= n; i++) if(!in[i]) q.push(i), T[i] = ++t;
        while(!q.empty()) {
            int u = q.front(); q.pop();
            for(int i = head[u]; i != -1; i = e[i].next) {
                int v = e[i].v;
                if(--in[v] == 0) {
                    q.push(v), T[v] = ++t;   
                }
            }
        }
    };
    topsort();
    for(int i = 1; i <= n; i++) b[i] = i;
    sort(b + 1, b + n + 1, [&](int A, int B) {
        return T[A] > T[B];
    });
    for(int t = 1; t <= n; t++) {
        int u = b[t];
        to[u].set(u);
        
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
