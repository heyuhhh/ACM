// Author : heyuhhh
// Created Time : 2020/10/22 09:31:47
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
//head
const int N = 1e6 + 5;

int n;
int a[N], b[N];

struct node {
    int val, d, siz;
    int ch[2];
} t[N];

int merge(int x, int y) {
    if (!x || !y) return x | y;
    if (t[x].val < t[y].val) swap(x, y);
    t[x].ch[1] = merge(t[x].ch[1], y);
    t[x].d = t[t[x].ch[1]].d + 1;
    t[x].siz = t[t[x].ch[0]].siz + t[t[x].ch[1]].siz + 1;
    if (t[t[x].ch[0]].d < t[t[x].ch[1]].d) {
        swap(t[x].ch[0], t[x].ch[1]);
    }
    return x;
}

struct seg {
    int l, r, rt;
    int val;
};

void del(int& x) {
    x = merge(t[x].ch[0], t[x].ch[1]);
}

seg sta[N];
int tot;

void run() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] -= i;
    }
    for (int i = 1; i <= n; i++) {
        sta[++tot] = seg{i, i, i, a[i]};
        t[i].val = a[i], t[i].siz = 1;
        while (tot > 1 && sta[tot].val < sta[tot - 1].val) {
            seg L = sta[tot - 1], R = sta[tot];
            tot -= 2;
            int rt = merge(L.rt, R.rt);
            int l = L.l, r = R.r;
            while (t[rt].siz > (r - l + 2) / 2) {
                del(rt);
            }
            sta[++tot] = seg{l, r, rt, t[rt].val};
        }
    }
    for (int i = 1; i <= tot; i++) {
        int l = sta[i].l, r = sta[i].r;
        for (int j = l; j <= r; j++) {
            b[j] = sta[i].val;
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += abs(a[i] - b[i]);
        b[i] += i;
    }

    cout << ans << '\n';
    for (int i = 1; i <= n; i++) {
        cout << b[i] << " \n"[i == n];
    }
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