/*
 * Author:  heyuhhh
 * Created Time:  2020/2/4 23:48:52
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
char s[N];
int c[N];

int minv[N << 2];
int query(int o, int l, int r, int v) {
    if(l == r) return l;
    int mid = (l + r) >> 1;
    if(minv[o << 1] <= v) return query(o << 1, l, mid, v);
    return query(o << 1|1, mid + 1, r, v);
}
void update(int o, int l, int r, int p, int v) {
    if(l == r) {
        minv[o] = max(v, minv[o]);
        return;
    }   
    int mid = (l + r) >> 1;
    if(p <= mid) update(o << 1, l, mid, p, v);
    else update(o << 1|1, mid + 1, r, p, v);
    minv[o] = min(minv[o << 1], minv[o << 1|1]);
}
void run(){
    cin >> (s + 1);
    for(int i = 1; i <= n; i++) {
        int p = query(1, 1, n, s[i] - 'a');
        c[i] = p;
        update(1, 1, n, p, s[i] - 'a');
    }
    int Max = *max_element(c + 1, c + n + 1);
    cout << Max << '\n';
    for(int i = 1; i <= n; i++) cout << c[i] << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    while(cin >> n) run();
    return 0;
}
