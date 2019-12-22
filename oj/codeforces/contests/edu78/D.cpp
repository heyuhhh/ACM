/*
 * Author:  heyuhhh
 * Created Time:  2019/12/21 11:16:58
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
const int N = 1e6 + 5;

int L[N], R[N];
struct seg {
    int l, r;   
    bool operator < (const seg &A) const {
        return l < A.l;
    }
}a[N];
int n, tot;
set <pii> s;
int f[N];
int find(int x) {return f[x] == x ? f[x] : f[x] = find(f[x]);}
int Union(int x, int l) {
    int res = 0;
    auto p = s.lower_bound(MP(l, 0));
    while(p != s.end()) {
        int y = p -> second;
        int fx = find(x), fy = find(y);
        if(fx == fy) return -1;
        f[fx] = fy;        
        if(++tot >= n) return -1;
        ++p;
    }
    return 1;
}

void run(){
    for(int i = 1; i <= 2 * n; i++) f[i] = i;
    for(int i = 1; i <= n; i++) cin >> a[i].l >> a[i].r;
    for(int i = 1; i <= n; i++) L[a[i].l] = R[a[i].r] = i;
    for(int i = 1; i < N; i++) {
        if(L[i]) s.insert(MP(a[L[i]].l, L[i]));
        if(R[i]) {
            int id = R[i];
            s.erase(MP(a[id].l, id));
            int t = Union(id, a[id].l);
            if(t == -1) {
                cout << "NO" << '\n';
                return;   
            }
        }
    }
    if(tot == n - 1) cout << "YES" << '\n';
    else cout << "NO" << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    while(cin >> n) run();
    return 0;
}
