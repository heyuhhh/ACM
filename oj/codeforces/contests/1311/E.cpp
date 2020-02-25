/*
 * Author:  heyuhhh
 * Created Time:  2020/2/25 11:20:11
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
const int N = 5000 + 5;

int n, d, son;
int f[N];

pii get(int n, int s = 0) {
    pii res(0, 0);
    int t = n, p = 1, now = s;
    while(t >= p) {
        t -= p;
        res.fi += now * p;
        ++now;
        p <<= 1;
    }
    res.fi += now * t;
    res.se = (2 * s + n - 1) * n / 2;
    return res;
}

bool chk(int n, int d) {
    pii res = get(n);
    return res.fi <= d && d <= res.se;   
}

void gao(int u, int now, int r) {
    --now;
    r -= now;
    for(int i = 0; i < now; i++) {
        pii t1 = get(i), t2 = get(now - i);
        if(t1.fi + t2.fi <= r && r <= t1.se + t2.se) {
            int lt = t1.fi, rt = t2.se;
            if(lt + rt > r) {
                rt -= lt + rt - r;
            } else if(lt + rt < r) {
                lt += r - (lt + rt);
            }
            if(i) {
                f[++son] = u;
                gao(son, i, lt);
            }
            if(now - i) {
                f[++son] = u;
                gao(son, now - i, rt);
            }
            return;
        }
    }
}

void run(){
    son = 1;
    cin >> n >> d;
    if(!chk(n, d)) {
        cout << "NO" << '\n';
        return;   
    }
    cout << "YES" << '\n';
    gao(1, n, d);
    for(int i = 2; i <= n; i++) {
        cout << f[i] << " \n"[i == n];   
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    int T; cin >> T;
    while(T--) run();
    return 0;
}
