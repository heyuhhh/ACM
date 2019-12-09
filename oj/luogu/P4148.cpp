/*
 * Author:  heyuhhh
 * Created Time:  2019/11/26 10:29:18
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <iomanip>
#define MP make_pair
#define fi first
#define se second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define INF 0x3f3f3f3f
#define Local
#ifdef Local
  #define dbg(args...) do { cout << #args << " -> "; err(args); } while (0)
  void err() { std::cout << '\n'; }
  template<typename T, typename...Args>
  void err(T a, Args...args) { std::cout << a << ' '; err(args...); }
#else
  #define dbg(...)
#endif
void pt() {std::cout << '\n'; }
template<typename T, typename...Args>
void pt(T a, Args...args) {std::cout << a << ' '; pt(args...); }
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
//head
const int N = 2e5 + 5;

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

void run(){
    int ans = 0;
    while(true) {
        int op; cin >> op;
        if(op == 3) return;
        if(op == 1) {
            int x, y, A; cin >> x >> y >> A;
            x ^= ans;
            y ^= ans;
            A ^= ans;
            T = Point {x, y, A};
            kd.insert(rt, 0);
        } else {
            int x1, x2, y1, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            x1 ^= ans;
            y1 ^= ans;
            x2 ^= ans;
            y2 ^= ans;
            kd.ans = 0;
            kd.query(rt, x1, y1, x2, y2);
            ans = kd.ans;
            cout << ans << '\n';
        }   
    }  
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    while(cin >> n) run();
    return 0;
}
