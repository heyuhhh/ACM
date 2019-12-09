//kd-tree
//一种多维二叉搜索树，每一层有不同的排序规则。

//矩阵修改，单点查询
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

//带修改，支持重构，询问矩阵和 
int n;
int D;
struct Point {
    int d[2], val;  
}tmp[N], T;
struct Node {
    int mn[2], mx[2];
    int l, r, sumv, sz;
    Point t;
}tr[N];
bool operator < (const Point &A, const Point &B) {
    return A.d[D] < B.d[D];   
}
int rt;
int rub[N], top, tot;
struct kdtree {
    const double E = 0.75;
    int ans;
    int new_node() {
        if(top) return rub[top--];
        return ++tot;
    }
    void push_up(int o) {
        int ls = tr[o].l, rs = tr[o].r;
        for(int i = 0; i < 2; i++) {
            tr[o].mn[i] = tr[o].mx[i] = tr[o].t.d[i];
            if(ls) {
                tr[o].mn[i] = min(tr[o].mn[i], tr[ls].mn[i]);
                tr[o].mx[i] = max(tr[o].mx[i], tr[ls].mx[i]);   
            }
            if(rs) {
                tr[o].mn[i] = min(tr[o].mn[i], tr[rs].mn[i]);
                tr[o].mx[i] = max(tr[o].mx[i], tr[rs].mx[i]);
            }
        }
        tr[o].sumv = tr[ls].sumv + tr[rs].sumv + tr[o].t.val;
        tr[o].sz = 1 + tr[ls].sz + tr[rs].sz;
    }
    void pia(int o, int num) {
        int ls = tr[o].l, rs = tr[o].r;
        if(ls) pia(ls, num);
        tmp[tr[ls].sz + num + 1] = Point{tr[o].t.d[0], tr[o].t.d[1], tr[o].t.val}; 
        rub[++top] = o;
        if(rs) pia(rs, tr[ls].sz + num + 1);
    }
    int rebuild(int l, int r, int now) {
        if(l > r) return 0;
        D = now;
        int mid = (l + r) >> 1;
        nth_element(tmp + l, tmp + mid, tmp + r + 1);
        int node = new_node();
        tr[node].t = tmp[mid];
        tr[node].l = rebuild(l, mid - 1, now ^ 1);
        tr[node].r = rebuild(mid + 1, r, now ^ 1);
        push_up(node);
        return node;
    }
    void chk(int &o, int now) {
        if(tr[o].sz * E <= tr[tr[o].l].sz || tr[o].sz * E <= tr[tr[o].r].sz) {
            pia(o, 0);
            o = rebuild(1, tr[o].sz, now);
        }   
    }
    void insert(int &o, int now) {
        if(!o) {
            tr[o = new_node()].t = T;
            tr[o].l = tr[o].r = 0;
            push_up(o);
            return;   
        }
        D = now;
        if(tr[o].t.d[D] < T.d[D]) insert(tr[o].r, now ^ 1);
        else insert(tr[o].l, now ^ 1);
        push_up(o);
        chk(o, now);
    }
    bool in(int x, int y, int x1, int y1, int x2, int y2) {
        return x >= x1 && x <= x2 && y >= y1 && y <= y2;   
    }
    void query(int o, int x1, int y1, int x2, int y2) {
        if(o == 0) return;
        if(tr[o].mn[0] >= x1 && tr[o].mx[0] <= x2 && tr[o].mn[1] >= y1 && tr[o].mx[1] <= y2) {
            ans += tr[o].sumv;
            return;   
        }
        if(tr[o].mn[0] > x2 || tr[o].mx[0] < x1 || tr[o].mn[1] > y2 || tr[o].mx[1] < y1) return;
        if(in(tr[o].t.d[0], tr[o].t.d[1], x1, y1, x2, y2)) ans += tr[o].t.val;
        query(tr[o].l, x1, y1, x2, y2);
        query(tr[o].r, x1, y1, x2, y2);
    }
}kd; 
