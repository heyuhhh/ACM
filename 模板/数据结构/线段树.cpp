int minv[N << 2], maxv[N << 2];
ll sumv[N << 2], lz[N << 2];

//区间加
void tag(int o, int l, int r, ll v) {
    minv[o] += v, maxv[o] += v;
    sumv[o] += 1ll * (r - l + 1) * v;
    lz[o] += v;
}

//区间set
void tag(int o, int l, int r, ll v) {
    minv[o] = v, maxv[o] = v;
    sumv[o] = 1ll * (r - l + 1) * v;
    lz[o] = v;
}

void push_up(int o) {
    maxv[o] = max(maxv[o << 1], maxv[o << 1|1]);
    minv[o] = min(minv[o << 1], minv[o << 1|1]);
    sumv[o] = sumv[o << 1] + sumv[o << 1|1];
}

void push_down(int o, int l, int r) {
    if(lz[o] != -1) {
        int mid = (l + r) >> 1;
        tag(o << 1, l, mid, lz[o]);
        tag(o << 1|1, mid + 1, r, lz[o]);
        lz[o] = -1;   
    }
}

void build(int o, int l, int r) {
    lz[o] = -1;
    if(l == r) {
        minv[o] = sumv[o] = maxv[o] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(o << 1, l, mid), build(o << 1|1, mid + 1, r);
    push_up(o);
}

void update(int o, int l, int r, int L, int R, ll v) {
    if(L <= l && r <= R) {
        tag(o, l, r, v);
        return;
    }   
    push_down(o, l, r);
    int mid = (l + r) >> 1;
    if(L <= mid) update(o << 1, l, mid, L, R, v);
    if(R > mid) update(o << 1|1, mid + 1, r, L, R, v);
    push_up(o);
}

ll query(int o, int l, int r, int L, int R) {
    if(L <= l && r <= R) {
        return sumv[o];
    }
    push_down(o, l, r);
    int mid = (l + r) >> 1;
    ll res = 0;
    if(L <= mid) res += query(o << 1, l, mid, L, R);
    if(R > mid) res += query(o << 1|1, mid + 1, r, L, R);
    return res;
}

int query(int o, int l, int r, int L, int R) {
    if(L <= l && r <= R) {
        return maxv[o];
    }
    push_down(o, l, r);
    int mid = (l + r) >> 1;
    int res = 0;
    if(L <= mid) res = query(o << 1, l, mid, L, R);
    if(R > mid) res = max(res, query(o << 1|1, mid + 1, r, L, R));
    return res;
}

int query(int o, int l, int r, int L, int R) {
    if(L <= l && r <= R) {
        return minv[o];
    }
    push_down(o, l, r);
    int mid = (l + r) >> 1;
    int res = INF;
    if(L <= mid) res = query(o << 1, l, mid, L, R);
    if(R > mid) res = min(res, query(o << 1|1, mid + 1, r, L, R));
    return res;
}
