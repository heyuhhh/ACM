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

const int N = 101010, M = 55;

int n, q, a[N];
int rt[N], ls[N * 22], rs[N * 22], cnt[N * 22], cntn;
int sta[M], top;
vi V;

int F(int x) {
    return lower_bound(all(V), x) - V.begin() + 1;
}

void upd(int pre, int &now, int p, int l, int r) {
    now = ++cntn;
    ls[now] = ls[pre];
    rs[now] = rs[pre];
    cnt[now] = cnt[pre] + 1;
    if(l == r) return ;
    int mid = l + r >> 1;
    if(p <= mid) upd(ls[pre], ls[now], p, l, mid);
    else upd(rs[pre], rs[now], p, mid + 1, r);
}

void qry(int L, int R, int l, int r) {
    if(cnt[R] - cnt[L] == 0 || top == M) return ;
    if(l == r) {
        rep(i, 0, cnt[R] - cnt[L]) if(top < M) sta[top++] = V[l - 1];
        return ;
    }
    int mid = l + r >> 1;
    qry(rs[L], rs[R], mid + 1, r);
    qry(ls[L], ls[R], l, mid);
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    while(cin >> n >> q) {
        cntn = 0;
        V.clear();
        rep(i, 1, n + 1) cin >> a[i], V.pb(a[i]);
        sort(all(V));
        V.erase(unique(all(V)), V.end());
        rep(i, 1, n + 1) {
            int x = F(a[i]);
            rt[i] = 0;
            upd(rt[i - 1], rt[i], x, 1, sz(V));
        }
        while(q--) {
            int l, r; cin >> l >> r;
            top = 0; qry(rt[l - 1], rt[r], 1, sz(V));
            ll res = -1;
            rep(i, 2, top) if(sta[i - 2] < sta[i - 1] + sta[i]) {
                res = sta[i - 2] + 0ll + sta[i - 1] + sta[i];
                break;
            }
            cout << res << endl;
        }
    }
    return 0;
}

