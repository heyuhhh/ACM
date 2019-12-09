/*
 * Author:  heyuhhh
 * Created Time:  2019/11/27 19:34:08
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <iomanip>
#define MP make_pair
#define fi first
#define se second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
//head
const int N = 1e5 + 5, MOD = 1e9 + 7;

int D;
struct Point {
    int d[2];
    Point(int x = 0, int y = 0) {
        d[0] = x, d[1] = y; 
    }  
    int& operator[] (int x) {return d[x];}
}p[N];
struct Node{
    int mn[2], mx[2];
    int l, r, col;
    bool lz;
    Point t;
}tr[N];
bool operator < (const Point &A, const Point &B) {
    return A.d[D] < B.d[D];   
}
bool operator == (const Point &A, const Point &B) {
    return A.d[0] == B.d[0] && A.d[1] == B.d[1];   
}
int rt;
struct kdtree {
    void push_up(int o) {
        int ls = tr[o].l, rs = tr[o].r;
        for(int i = 0; i < 2; i++) {
            tr[o].mn[i] = tr[o].mx[i] = tr[o].t[i];
            if(ls) {
                tr[o].mn[i] = min(tr[o].mn[i], tr[ls].mn[i]);
                tr[o].mx[i] = max(tr[o].mx[i], tr[ls].mx[i]);   
            }
            if(rs) {
                tr[o].mn[i] = min(tr[o].mn[i], tr[rs].mn[i]);
                tr[o].mx[i] = max(tr[o].mx[i], tr[rs].mx[i]);
            }
        }
    }
    void push_down(int o) {
        if(tr[o].lz) {
            if(tr[o].l) {
                tr[tr[o].l].lz = true;
                tr[tr[o].l].col = tr[o].col;
            }
            if(tr[o].r) {
                tr[tr[o].r].lz = true;
                tr[tr[o].r].col = tr[o].col;
            }
            tr[o].lz = false;
        }   
    }
    int build(int l, int r, int now) {
        D = now;
        int mid = (l + r) >> 1;
        nth_element(p + l, p + mid, p + r + 1);
        tr[mid].t = p[mid];
        tr[mid].lz = false;
        tr[mid].col = 1; 
        if(l < mid) tr[mid].l = build(l, mid - 1, now ^ 1);
        else tr[mid].l = 0;
        if(r > mid) tr[mid].r = build(mid + 1, r, now ^ 1);
        else tr[mid].r = 0;
        push_up(mid);
        return mid;
    }
    int query(int o, Point T, int now) {
        if(o == 0) return 0;
        if(tr[o].t == T) return tr[o].col;
        push_down(o);
        D = now;
        if(T.d[D] < tr[o].t.d[D]) return query(tr[o].l, T, now ^ 1);
        else return query(tr[o].r, T, now ^ 1);
    }
    void update(int o, int l, int r, int d, int u, int c) {
        if(tr[o].mn[0] >= l && tr[o].mx[0] <= r && tr[o].mn[1] >= d && tr[o].mx[1] <= u) {
            tr[o].col = c; tr[o].lz = true;
            return;   
        }
        if(tr[o].mn[0] > r || tr[o].mx[0] < l || tr[o].mn[1] > u || tr[o].mx[1] < d) return;
        push_down(o);
        if(tr[o].t[0] >= l && tr[o].t[0] <= r && tr[o].t[1] >= d && tr[o].t[1] <= u) {
            tr[o].col = c;   
        }
        if(tr[o].l) update(tr[o].l, l, r, d, u, c);
        if(tr[o].r) update(tr[o].r, l, r, d, u, c);
    }
}kd;

int dfn[N], dfn2[N], deep[N], T;
int n, c, q;
vector <int> g[N];

void dfs(int u, int d) {
    dfn[u] = ++T; 
    deep[u] = d;
    for(int i = 0; i < sz(g[u]); i++) {
        int v = g[u][i];
        dfs(v, d + 1);
    }
    dfn2[u] = T;
}

void run(){
    T = rt = 0;
    cin >> n >> c >> q;
    for(int i = 1; i <= n; i++) g[i].clear();
    for(int i = 2; i <= n; i++) {
        int x; cin >> x;
        g[x].push_back(i);
    }
    dfs(1, 1);
    for(int i = 1; i <= n; i++) {
        p[i] = Point(dfn[i], deep[i]);
    }
    rt = kd.build(1, n, 0);
    int ans = 0;
    for(int i = 1; i <= q; i++) {
        int a, k, x; cin >> a >> k >> x;
        if(x == 0) {
            ans = (ans + 1ll * i * kd.query(rt, Point(dfn[a], deep[a]), 0) % MOD) % MOD;
        } else {
            int l = dfn[a], r = dfn2[a];
            int u = min(n, deep[a] + k), d = deep[a];
            kd.update(rt, l, r, d, u, x);
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    int T; cin >> T;
    while(T--) run();
    return 0;
}
