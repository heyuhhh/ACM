#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
const int rb = 1e9;

int Add[N * 21], ls[N * 21], rs[N * 21];
int T, rt;
void update(int& o, int l, int r, int L, int R, int v) {
    if (!o) o = ++T;
    if (L <= l && r <= R) {
        Add[o] += v;
        return;
    }
    int mid = (l + r) >> 1;
    if (L <= mid) update(ls[o], l, mid, L, R, v);
    if (R > mid) update(rs[o], mid + 1, r, L, R, v);
}
void update(int l, int r, int v) {
    ++l, --r;
    l = max(l, 1), r = min(r, rb);
    if (l > r) return;
    update(rt, 1, rb, l, r, v);
}
int query(int o, int l, int r, int p) {
    if (!o) return 0;
    if (l == r) return Add[o];
    int mid = (l + r) >> 1;
    if (p <= mid) return query(ls[o], l, mid, p) + Add[o];
    else return query(rs[o], mid + 1, r, p) + Add[o];
}

int main() {
    multiset<int> s;
    int op, x, q;
    auto gao = [&](multiset<int>::iterator l, multiset<int>::iterator r, int v) {
        if (l != s.begin()) {
            --l;
            update(x - *l, x + *l, v);
            if (r != s.end()) update(*r - *l, *r + *l, -v);
        }
        if (r != s.end()) update(*r - x, *r + x, v);
        return 0;
    };
    scanf("%d", &q);
    while (q--) {
        scanf("%d%d", &op, &x);
        if (op == 1) {
            auto r = s.upper_bound(x), l = r;
            gao(l, r, 1);
            s.insert(x);
        } else if (op == 2) {
            auto r = s.upper_bound(x), l = r; --l;
            gao(l, r, -1);
            s.erase(--r);
        } else {
            int t = query(rt, 1, rb, x);
            if (t > 0) cout << "Yes" << '\n';
            else cout << "No" << '\n';
        }
    }
    return 0;
}