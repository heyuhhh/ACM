/*
	题意：
	现有两种操作，插入和查询，插入操作则插入一个点$(x,y,z)$，查询操作给出两个点$(x1,y1,z1),(x2,y2,z2)$，回答满足$x1≤x≤x2,y1≤y≤y2,z1≤z≤z2$的(x,y,z)的个数为多少。
	
	带修改的四维偏序，四维分别为时间、x、y、z，直接cdq套cdq就行。
*/ 
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 50005;

int T, q;

struct node{
    int x, y, z, op, id, part;
}a[N * 10], b[N * 10], d[N * 10];

int hs[N << 2];

bool isq[N];
int ans[N];

int c[N << 2];
int lowbit(int x) {return x & (-x);}

void update(int x, int v) {
    for(; x < N << 2; x += lowbit(x)) c[x] += v;
}

int query(int x) {
    int ans = 0;
    for(; x; x -= lowbit(x)) ans += c[x];
    return ans;
}

void cdq2(int l, int r) {
    if(l == r) return ;
    int mid = (l + r) >> 1;
    cdq2(l, mid); cdq2(mid + 1, r);
    int t1 = l, t2 = mid + 1;
    for(int i = l; i <= r; i++) {
        if(t2 > r || (t1 <= mid && b[t1].y <= b[t2].y)) {
            if(b[t1].part == 0 && b[t1].op == 0) {
                update(b[t1].z, 1);
            }
            d[i] = b[t1++];
        } else {
            if(b[t2].part && b[t2].op != 0) {
                ans[b[t2].id] += b[t2].op * query(b[t2].z);
            }
            d[i] = b[t2++];
        }
    }
    for(int i = l; i <= mid; i++) {
        if(b[i].part == 0 && b[i].op == 0) update(b[i].z, -1);
    }
    for(int i = l; i <= r; i++) b[i] = d[i];
}

void cdq(int l, int r) {
    if(l == r) return ;
    int mid = (l + r) >> 1;
    cdq(l, mid); cdq(mid + 1, r);
    int t1 = l, t2 = mid + 1;
    for(int i = l; i <= r; i++) {
        if(t2 > r || (t1 <= mid && a[t1].x <= a[t2].x)) {
            b[i] = a[t1++];
            b[i].part = 0;
        } else {
            b[i] = a[t2++];
            b[i].part = 1;
        }
    }
    for(int i = l; i <= r; i++) a[i] = b[i];
    cdq2(l, r);
}

int main() {
//    freopen("input.in", "r", stdin);
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> T;
    while(T--) {
        cin >> q;
        for(int i = 1; i <= q; i++) ans[i] = 0, isq[i] = false;
        int cnt = 0; hs[0] = 0;
        for(int i = 1; i <= q; i++) {
            int op; cin >> op;
            if(op == 1) {
                int x, y, z; cin >> x >> y >> z;
                a[++cnt] = {x, y, z, 0, i, -1};
                hs[++hs[0]] = z;
            } else {
                isq[i] = true;
                int x1, y1, z1, x2, y2, z2;
                cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
                --x1, --y1, --z1;
                a[++cnt] = {x1, y1, z1, -1, i, -1};
                a[++cnt] = {x1, y2, z1, 1, i, -1};
                a[++cnt] = {x2, y2, z1, -1, i, -1};
                a[++cnt] = {x2, y1, z1, 1, i, -1};
                a[++cnt] = {x1, y1, z2, 1, i, -1};
                a[++cnt] = {x1, y2, z2, -1, i, -1};
                a[++cnt] = {x2, y2, z2, 1, i, -1};
                a[++cnt] = {x2, y1, z2, -1, i, -1};
                hs[++hs[0]] = z1, hs[++hs[0]] = z2;
            }
        }
        sort(hs + 1, hs + hs[0] + 1);
        hs[0] = unique(hs + 1, hs + hs[0] + 1) - hs - 1;
        for(int i = 1; i <= cnt; i++) a[i].z = lower_bound(hs + 1, hs + hs[0] + 1, a[i].z) - hs;
        cdq(1, cnt);
        for(int i = 1; i <= q; i++) {
            if(isq[i]) cout << ans[i] << '\n';
        }
    }
    return 0;
}
