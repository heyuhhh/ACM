/*
	题意：
	现在需要维护两种操作，一种是插入一条线段，另一种是询问$x=k$时，最上方线段的编号，如有多个线段处于最大值状态，那么就输出编号最小的。
	强制在线。
	
	李超树模板题，注意其标记可持久化。
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5, MAX = 50005;
int n;

struct node{
    bool sign; int id;
    double k, b;
    void upd(int _id, double _k, double _b) {
        id = _id, k = _k, b = _b;
    }
}tr[MAX << 3];

void update(int o, int l, int r, int id, double k, double b) {
    if(!tr[o].sign) {
        tr[o].sign = 1;
        tr[o].upd(id, k, b);
        return;
    }
    double l1 = l * tr[o].k + tr[o].b, l2 = l * k + b;
    double r1 = r * tr[o].k + tr[o].b, r2 = r * k + b;
    if(l2 <= l1 && r2 <= r1) return;
    if(l2 > l1 && r2 > r1) {
        tr[o].upd(id, k, b); return;
    }
    int mid = (l + r) >> 1;
    double x = (tr[o].b - b) / (k - tr[o].k);
    if(x <= mid) {
        if(l1 > l2) update(o << 1, l, mid, tr[o].id, tr[o].k, tr[o].b), tr[o].upd(id, k, b);
        else update(o << 1, l, mid, id, k, b);
    } else {
        if(l1 > l2) update(o << 1|1, mid + 1, r, id, k, b);
        else update(o << 1|1, mid + 1, r, tr[o].id, tr[o].k, tr[o].b), tr[o].upd(id, k, b);
    }
}

void update(int o, int l, int r, int L, int R, int id, double k, double b) {
    if(L <= l && r <= R) {
        update(o, l, r, id, k, b); return;
    }
    int mid = (l + r) >> 1;
    if(L <= mid) update(o << 1, l, mid, L, R, id, k, b);
    if(R > mid) update(o << 1|1, mid + 1, r, L, R, id, k, b);
}

void chk(int &res, int o1, int o2, int x) {
    double y1, y2;
    y1 = x * tr[o1].k + tr[o1].b;
    y2 = x * tr[o2].k + tr[o2].b;
    if(y1 > y2 && tr[o1].sign) res = o1;
    else if(y1 < y2 && tr[o2].sign) res = o2;
    else if(y1 == y2){
        if(tr[o1].id < tr[o2].id && tr[o1].sign) res = o1;
        else if(tr[o1].id > tr[o2].id && tr[o2].sign) res = o2;
    }
    return;
}

int query(int o, int l, int r, int p) {
    if(l == r) return o;
    int mid = (l + r) >> 1, res = 0;
    if(p <= mid) chk(res, query(o << 1, l, mid, p), o, p);
    else chk(res, query(o << 1|1, mid + 1, r, p), o, p);
    return res;
}

int main() {
//    freopen("input.in", "r", stdin);
    scanf("%d", &n);
    int lastans = 0, cnt = 0;
    for(int i = 1; i <= n; i++) {
        int op; scanf("%d", &op);
        if(op == 0) {
            int k; scanf("%d", &k);
            int x = (k + lastans - 1) % 39989 + 1;
            int o = query(1, 1, MAX, x);
            lastans = tr[o].id;
            printf("%d\n", lastans);
        } else {
            int x1, x2, y1, y2; ++cnt;
            scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
            x1 = (x1 + lastans - 1) % 39989 + 1;
            y1 = (y1 + lastans - 1) % 1000000000 + 1;
            x2 = (x2 + lastans - 1) % 39989 + 1;
            y2 = (y2 + lastans - 1) % 1000000000 + 1;
            if(x1 > x2) swap(x1, x2), swap(y1, y2);
            double k = 1.0 * (y1 - y2) / (x1 - x2), b = y1 - k * x1;
            update(1, 1, MAX, x1, x2, cnt, k, b);
        }
    }
    return 0;
}
