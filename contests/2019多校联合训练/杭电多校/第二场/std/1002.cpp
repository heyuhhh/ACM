#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define dd(a) cout << #a << " = " << a << " " 
#define de(a) cout << #a << " = " << a << endl
#define sz(a) (int)a.size()
#define all(a) a.begin(), a.end()
#define pw(a) (1ll << (a))
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef double db;

const int N = 303030, inf = 1e9 + 1;

int n, a[N], f[N][2], g[N][2], b[N];
vi V, vec[2][N], ans[2];

int F(int x) { return lower_bound(all(V), x) - V.begin() + 1; }

struct Seg {
#define ls rt << 1
#define rs ls | 1
    static const int N = ::N << 2;
    int ma[N], ans;
    void init(int n) {
        fill_n(ma, n << 2 | 1, 0);
    }

    void Qry(int L, int R, int l, int r, int rt) {
        if (ma[rt] <= ans) return;
        if(L <= l && r <= R) {
            ans = max(ans, ma[rt]);
            return;
        }
        int mid = l + r >> 1;
        if(L <= mid) Qry(L, R, l, mid, ls);
        if(R > mid) Qry(L, R, mid + 1, r, rs);
        return;
    }
    int qry(int L, int R, int l, int r, int rt) {
        ans = 0; if (L > R) return 0;
        Qry(L, R, l, r, rt);
        return ans;
    }
    void upd(int p, int c, int l, int r, int rt) {
        ma[rt] = max(ma[rt], c);
        if(l == r) return;
        int mid = l + r >> 1;
        if(p <= mid) upd(p, c, l, mid, ls);
        else upd(p, c, mid + 1, r, rs);
    }
}seg[2];

void solve(int f[][2], int a[]) {
    V.clear();
    rep(i, 1, n + 1) V.pb(a[i]);
    sort(all(V));
    V.erase(unique(all(V)), V.end());
    seg[0].init(sz(V));
    seg[1].init(sz(V));
    rep(i, 1, n + 1) {
        int x = F(a[i]);
        f[i][0] = seg[0].qry(1, x - 1, 1, sz(V), 1) + 1;
        f[i][1] = max(f[i][0], seg[1].qry(x + 1, sz(V), 1, sz(V), 1) + 1);
        seg[0].upd(x, f[i][0], 1, sz(V), 1);
        seg[1].upd(x, f[i][1], 1, sz(V), 1);
    }
}

bool cmp(int i, int j) { return a[i] > a[j]; }
bool cmp2(int i, int j) { return a[i] < a[j]; }

int main() {
    while(~scanf("%d", &n)) {
        // get f, g
        a[0] = 0; rep(i, 1, n + 1) scanf("%d", &a[i]);
        solve(f, a);
        rep(i, 1, n + 1) b[i] = a[n + 1 - i];
        solve(g, b);
        for(int i = 1, j = n; i < j; ++i, --j) swap(g[i][0], g[j][0]), swap(g[i][1], g[j][1]);
        // get max len
        int ma = 0; rep(i, 1, n + 1) ma = max(ma, f[i][0] + g[i][0] - 1);
        // get vec
        rep(o, 0, 2) rep(i, 1, n + 1) vec[o][i].clear();
        rep(i, 1, n + 1) {
            if(f[i][0] + g[i][1] - 1 == ma) vec[0][f[i][0]].pb(i);
            if(f[i][1] + g[i][0] - 1 == ma) vec[1][g[i][0]].pb(i);
        }
        // get ans[0]
        ans[0].clear(); ans[1].clear();
        int i = 0, o = 0;
        rep(_, 0, ma) {
            a[0] = 0;
            int mi[2] = {n + 1, n + 1};
            if(!o) {
                auto &v = vec[0][_ + 1];
                int p = upper_bound(all(v), i) - v.begin();
                if(p < sz(v) && a[i] < a[v[p]]) mi[0] = v[p];
            }
            a[0] = inf;
            auto &v = vec[1][ma - _];
            int p = upper_bound(all(v), i) - v.begin();
            if(p < sz(v) && a[i] > a[v[p]]) mi[1] = v[p];
            (mi[0] < mi[1]) ? (i = mi[0]) : (i = mi[1], o = 1);
            ans[0].pb(i);
        }
        //de(ma);
        rep(i, 0, ma) printf("%d%c", ans[0][i], " \n"[i == ma - 1]);
        // get ans[1]
        i = o = 0; 
        rep(_, 0, ma) {
            a[0] = 0;
            int Ma[2] = {0, 0};
            if(!o) {
                auto &v = vec[0][_ + 1];
                int p = lower_bound(all(v), i, cmp) - v.begin() - 1;
                if(p >= 0 && a[i] < a[v[p]]) Ma[0] = v[p];
            }
            a[0] = inf;
            auto &v = vec[1][ma - _];
            int p = lower_bound(all(v), i, cmp2) - v.begin() - 1;
            if(p >= 0 && a[i] > a[v[p]]) Ma[1] = v[p];
            (Ma[0] > Ma[1]) ? (i = Ma[0]) : (i = Ma[1], o = 1);
            ans[1].pb(i);
        }
        rep(i, 0, ma) printf("%d%c", ans[1][i], " \n"[i == ma - 1]);
    }
    return 0;
}
