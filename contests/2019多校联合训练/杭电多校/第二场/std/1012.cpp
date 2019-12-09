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

const int N = 101010;

int n, C, k;
vi vec[N];

struct Seg {
#define ls rt << 1
#define rs ls | 1
    static const int N = ::N << 2;
    int ma[N], la[N], pos[N];
    void gao(int rt, int c) {
        ma[rt] += c; la[rt] += c;
    }
    void down(int rt) {
        if(!la[rt]) return ;
        gao(ls, la[rt]);
        gao(rs, la[rt]);
        la[rt] = 0;
    }
    void up(int rt) {
        ma[rt] = max(ma[ls], ma[rs]);
        pos[rt] = (ma[rt] == ma[ls] ? pos[ls] : pos[rs]);
    }
    void build(int l, int r, int rt) {
        ma[rt] = la[rt] = 0, pos[rt] = l;
        if(l == r) return ;
        int mid = l + r >> 1;
        build(l, mid, ls);
        build(mid + 1, r, rs);
    }
    void upd(int L, int R, int c, int l, int r, int rt) {
        if(L > R) return ;
        if(L <= l && r <= R) {
            gao(rt, c);
            return ;
        }
        int mid = l + r >> 1;
        down(rt);
        if(L <= mid) upd(L, R, c, l, mid, ls);
        if(R > mid) upd(L, R, c, mid + 1, r, rs);
        up(rt);
    }
    int qry(int L, int R, int l, int r, int rt) {
        if(ma[rt] != C) return 0;
        if(L <= l && r <= R) return pos[rt];
        int mid = l + r >> 1;
        down(rt);
        if(L <= mid) {
            int t = qry(L, R, l, mid, ls);
            if(t) return t;
        }
        if(R > mid) return qry(L, R, mid + 1, r, rs);
        return 0;
    }
}seg;

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    while(cin >> n >> C >> k) {
        rep(i, 1, C + 1) vec[i].clear(), vec[i].pb(0);
        int ans = 0;
        seg.build(1, n, 1);
        rep(i, 1, n + 1) {
            int c; cin >> c;
            seg.upd(i, i, C - 1, 1, n, 1);
            seg.upd(vec[c].back() + 1, i - 1, -1, 1, n, 1);
            vec[c].pb(i);
            int p = sz(vec[c]) - k - 1;
            if(p >= 0) seg.upd(vec[c][p] + 1, vec[c][p + 1], 1, 1, n, 1);
            int j = seg.qry(1, i, 1, n, 1); if(!j) continue;
            ans = max(ans, i - j + 1);
        }
        cout << ans << endl;
    }
    return 0;
}

