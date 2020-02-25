/*
 * Author:  heyuhhh
 * Created Time:  2020/2/24 23:59:19
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
pii a[N];

struct Bit {
    int c[N];
    void clear() {
        memset(c, 0, sizeof(c));   
    }
    int lowbit(int x) {return x & (-x);}
    void add(int x) {
        for(; x < N; x += lowbit(x)) ++c[x];
    }
    int query(int x) {
        int res = 0;
        for(;x ; x -= lowbit(x)) res += c[x];   
        return res;   
    }
    int query(int l, int r) {
        return query(r) - query(l - 1);
    }
}bit[2];

int ans[N];

void run(){
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i].fi;
    for(int i = 1; i <= n; i++) cin >> a[i].se;
    sort(a + 1, a + n + 1, [&](pii A, pii B) {
        if(A.fi == B.fi) return A.se < B.se;
        return A.fi < B.fi;
    });
    vector <int> f, z;
    for(int i = 1; i <= n; i++) {
        if(a[i].se > 0) z.push_back(a[i].se);
        else f.push_back(a[i].se);
    }
    sort(all(f)), sort(all(z));
    f.erase(unique(all(f)), f.end()), z.erase(unique(all(z)), z.end());
    auto find = [&](int it, vector <int>& v) {
        return lower_bound(all(v), it) - v.begin() + 1;
    };
    for(int i = 1; i <= n; i++) {
        if(a[i].se > 0) {
            int t = find(a[i].se, z);
            ans[i] += bit[0].query(t);
            ans[i] += bit[1].query(N - 1);
            bit[0].add(t);
        } else {
            int t = find(a[i].se, f);
            ans[i] += bit[1].query(t);
            bit[1].add(t);
        }
    }
    bit[0].clear(), bit[1].clear();
    for(int i = n; i >= 1; i--) {
        if(a[i].se > 0) {
            int t = find(a[i].se, z);
            ans[i] -= bit[0].query(t, N - 1);
            bit[0].add(t);
        } else {
            int t = find(a[i].se, f);
            ans[i] -= bit[1].query(t, N - 1);
            ans[i] -= bit[0].query(N - 1);
            bit[1].add(t);
        }   
    }
    ll res = 0;
    for(int i = 1; i <= n; i++) res += 1ll * a[i].fi * ans[i];
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
