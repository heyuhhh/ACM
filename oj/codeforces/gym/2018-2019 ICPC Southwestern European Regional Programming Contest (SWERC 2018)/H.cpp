// Author : heyuhhh
// Created Time : 2020/08/15 14:49:05
#include<bits/stdc++.h>
#define MP make_pair
#define fi first
#define se second
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
void err(int x) {cerr << x;}
void err(long long x) {cerr << x;}
void err(double x) {cerr << x;}
void err(char x) {cerr << '"' << x << '"';}
void err(const string &x) {cerr << '"' << x << '"';}
void _print() {cerr << "]\n";}
template<typename T, typename V>
  void err(const pair<T, V> &x) {cerr << '{'; err(x.first); cerr << ','; err(x.second); cerr << '}';}
template<typename T>
  void err(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), err(i); cerr << "}";}
template <typename T, typename... V>
  void _print(T t, V... v) {err(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifdef Local
#define dbg(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define dbg(x...)
#endif
//head
const int N = 1e6 + 5, M = 1e6 + 5;
int n, m;
struct Edge{
    int v, w, next;   
}e[M << 1];
int dis[N];
struct Dijkstra{
    struct node{
        int d, u;
        bool operator < (const node &A) const {
            return d > A.d;
        }   
    };
    int head[N], tot;
    bool vis[N];
    void init() {
        memset(head, -1, sizeof(head)); tot = 0;   
    }
    void adde(int u, int v, int w) {
        e[tot].v = v; e[tot].w = w; e[tot].next = head[u]; head[u] = tot++;   
    }
    void dij(int s) {
        priority_queue <node> q;
        memset(dis, INF, sizeof(dis));
        memset(vis, 0, sizeof(vis));
        dis[s] = 0;
        q.push(node{0, s});
        while(!q.empty()) {
            node cur = q.top(); q.pop();
            int u = cur.u, d = cur.d;
            if(vis[u]) continue;
            vis[u] = 1;
            for(int i = head[u]; i != -1; i = e[i].next) {
                int v = e[i].v;
                if(dis[v] > dis[u] + e[i].w) {
                    dis[v] = dis[u] + e[i].w;
                    q.push(node{dis[v], v});   
                }
            }   
        }
    }
}solver;

struct Point {
    int x, y, z, id;   
}a[N], b[N];
int ans[N];

void Hash(int* a) {
    sort(a + 1, a + n + 1);
    a[0] = unique(a + 1, a + n + 1) - a - 1;
}

int find(int* a, int x) {
    return lower_bound(a + 1, a + a[0] + 1, x) - a;
}

int x[N], y[N], z[N];
int c[N];

int lowbit(int x) {
    return x & (-x);
}
void del(int x) {
    for (int i = x; i < N; i += lowbit(i)) c[i] = 0;
}
void add(int x, int v) {
    for(int i = x; i < N; i += lowbit(i)) c[i] = max(c[i], v);
}
int query(int x) {
    int ans = 0;
    for(int i = x; i; i -= lowbit(i)) ans = max(ans, c[i]);
    return ans;
}
void cdq(int l, int r) {
    if(l == r) return ;
    int mid = (l + r) >> 1;
    cdq(l, mid);
    sort(a + l, a + mid + 1, [&](Point A, Point B) {
        return A.y < B.y;
    });
    sort(a + mid + 1, a + r + 1, [&](Point A, Point B) {
        return A.y < B.y;
    });
    int t1 = l, t2 = mid + 1;
    for(int i = l; i <= r; i++) {
        if((t1 <= mid && a[t1].y <= a[t2].y) || t2 > r) {
            add(a[t1].z, ans[a[t1].id]);
            ++t1;
        } else {
            ans[a[t2].id] = max(ans[a[t2].id], query(a[t2].z) + 1);
            ++t2;
        }
    }
    for(int i = l; i <= mid; i++) del(a[i].z);
    sort(a + mid + 1, a + r + 1, [&](Point A, Point B) {
        if (A.x != B.x) return A.x < B.x;
        if (A.y != B.y) return A.y < B.y;
        return A.z < B.z;
    });
    cdq(mid + 1, r);
}

void run() {
    cin >> n >> m;
    solver.init();
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        solver.adde(u, v, w);
        solver.adde(v, u, w);
    }
    solver.dij(0);
    for (int i = 0; i < n; i++) {
        x[i + 1] = dis[i];
    }
    solver.dij(1);
    for (int i = 0; i < n; i++) {
        y[i + 1] = dis[i];
    }
    solver.dij(2);
    for (int i = 0; i < n; i++) {
        z[i + 1] = dis[i];
    }

    for (int i = 1; i <= n; i++) {
        a[i] = Point{x[i], y[i], z[i], i};
    }
    Hash(x), Hash(y), Hash(z);
    map<pair<pii, int>, int> mp;
    for (int i = 1; i <= n; i++) {
        a[i].x = find(x, a[i].x);
        a[i].y = find(y, a[i].y);
        a[i].z = find(z, a[i].z);
        ++mp[MP(MP(a[i].x, a[i].y), a[i].z)];
        b[i] = a[i];
    }

    sort(a + 1, a + n + 1, [&](Point A, Point B) {
        if (A.x != B.x) return A.x < B.x;
        if (A.y != B.y) return A.y < B.y;
        return A.z < B.z;
    });

    for (int i = 1; i <= n; i++) {
        ans[i] = 1;
    }
    cdq(1, n);
    int res = 0;
    for (int i = 1; i <= n; i++) {
        if (ans[i] == 1) {
            res += mp[MP(MP(b[i].x, b[i].y), b[i].z)];
        }
    }
    cout << res << '\n';
}
int main() {
#ifdef Local
    freopen("input.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}