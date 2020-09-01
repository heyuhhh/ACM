// Author : heyuhhh
// Created Time : 2020/08/23 15:35:17
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
const int N = 2e5 + 5;

int sz[N * 21];
ll sum[N * 21];
int ch[N * 21][2];
int rt, tot;

void pushup(int o) {
    sum[o] = sum[ch[o][0]] + sum[ch[o][1]];
    sz[o] = sz[ch[o][0]] + sz[ch[o][1]];
}

void insert(int& o, int l, int r, int v, int t) {
    if (!o) o = ++tot;
    if (l == r) {
        sum[o] = v;
        ++sz[o];
        return;
    }
    int mid = (l + r) >> 1;
    if (v <= mid) insert(ch[o][0], l, mid, v, t);
    else insert(ch[o][1], mid + 1, r, v, t);
    pushup(o);
}

void erase(int& o, int l, int r, int v, int t) {
    if (!o) o = ++tot;
    if (l == r) {
        sum[o] = 0;
        --sz[o];
        return;
    }
    int mid = (l + r) >> 1;
    if (v <= mid) erase(ch[o][0], l, mid, v, t);
    else erase(ch[o][1], mid + 1, r, v, t);
    pushup(o);
}

ll query(int o, int l, int r, int cnt) {
    if (!o) return 0;
    if (sz[o] == cnt) return sum[o];
    int mid = (l + r) >> 1;
    if (sz[ch[o][1]] >= cnt) return query(ch[o][1], mid + 1, r, cnt);
    return query(ch[o][0], l, mid, cnt - sz[ch[o][1]]) + sum[ch[o][1]];
}

int queryK(int o, int l, int r, int k) {
    if (!o) return 0;
    if (l == r) return sum[o];
    int mid = (l + r) >> 1;
    if (sz[ch[o][1]] >= k) return queryK(ch[o][1], mid + 1, r, k);
    return queryK(ch[o][0], l, mid, k - sz[ch[o][1]]);
}

void run() {
    int n;
    cin >> n;
    int cnt = 0, all = 0;
    ll res = 0;
    set<int> s0, s1;
    for (int i = 0; i < n; i++) {
        int op, d;
        cin >> op >> d;
        res += d;
        if (op == 0) {
            if (d > 0) {
                ++all;
                s0.insert(d);
                insert(rt, 1, 1000000000, d, 0);
            } else {
                --all;
                s0.erase(-d);
                erase(rt, 1, 1000000000, -d, 0);
            }
        } else {
            if (d > 0) {
                ++all;
                s1.insert(d);
                insert(rt, 1, 1000000000, d, 1);
                ++cnt;
            } else {
                --all;
                s1.erase(-d);
                erase(rt, 1, 1000000000, -d, 1);
                --cnt;
            }
        }
        if (all == cnt) {
            auto it = s1.begin();
            cout << res + res - *it << '\n';
            continue;
        }
        if (cnt == 0) {
            cout << res << '\n';
            continue;
        }
        int val = queryK(rt, 1, 1000000000, cnt);
        auto it = s0.end(); --it;
        ll p = query(rt, 1, 1000000000, cnt);
        if (*it < val) {
            ll now = res + p - val + queryK(rt, 1, 1000000000, cnt + 1);
            cout << now << '\n';
        } else {
            cout << res + p << '\n';
        }
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