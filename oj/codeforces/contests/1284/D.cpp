/*
 * Author:  heyuhhh
 * Created Time:  2020/2/29 15:38:48
 */
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <iomanip>
#define MP make_pair
#define fi first
#define se second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define INF 0x3f3f3f3f
//#define Local
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
const int N = 1e5 + 5;

int n;
struct node {
    int sa, ea, sb, eb;
    bool operator < (const node &A) const {
        return sa < A.sa;   
    }
}a[N];

int maxv[N << 2], minv[N << 2];

void build(int o, int l, int r) {
    if(l == r) {
        maxv[o] = a[l].sb;
        minv[o] = a[l].eb;
        return;
    }
    int mid = (l + r) >> 1;
    build(o << 1, l, mid), build(o << 1|1, mid + 1, r);
    maxv[o] = max(maxv[o << 1], maxv[o << 1|1]);
    minv[o] = min(minv[o << 1], minv[o << 1|1]);
}

int query(int o, int l, int r, int L, int R, int op) {
    if(L <= l && r <= R) {
        if(op) return maxv[o];
        return minv[o];   
    }
    int mid = (l + r) >> 1;
    int res;
    if(op) res = 0; else res = INF;
    if(L <= mid) res = query(o << 1, l, mid, L, R, op);
    if(R > mid) {
        int t = query(o << 1|1, mid + 1, r, L, R, op);
        if(op) res = max(res, t);
        else res = min(res, t);   
    }
    return res;
}

bool solve() {
    sort(a + 1, a + n + 1);
    vector <int> b;
    for(int i = 1; i <= n; i++) b.push_back(a[i].sa);
    build(1, 1, n);
    for(int i = 1; i <= n; i++) {
        dbg(a[i].sa, a[i].ea, a[i].sb, a[i].eb);
        int p = upper_bound(all(b), a[i].ea) - b.begin();
        dbg(p);
        int Max = query(1, 1, n, i + 1, p, 1);
        int Min = query(1, 1, n, i + 1, p, 0);
        dbg(Min, Max);
        if(Min < a[i].sb || Max > a[i].eb) {
            return false;   
        }
    }
    return true;
}

void run() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i].sa >> a[i].ea >> a[i].sb >> a[i].eb;   
    }
    bool ok = true;
    ok &= solve();
    for(int i = 1; i <= n; i++) {
        swap(a[i].sa, a[i].sb), swap(a[i].ea, a[i].eb);
    }
    ok &= solve();
    if(ok) cout << "YES" << '\n';
    else cout << "NO" << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
