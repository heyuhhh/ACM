/*
 * Author:  heyuhhh
 * Created Time:  2020/1/29 16:36:55
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
const int N = 3e5 + 5, M = 10;

int n, m;
int a[N][M];
int A, B;

int f[1 << M];

int ok(int x) {
    for(int i = 0; i < 1 << m; i++) {
        if((i & x) == x) {
            if(f[i] > 0) return f[i];   
        }
    }
    return 0;
}

bool chk(int x) {
    for(int i = 0; i < 1 << m; i++) f[i] = 0;
    for(int i = 1; i <= n; i++) {
        int t = 0;
        for(int j = 1; j <= m; j++) {
            if(a[i][j] >= x) {
                t |= (1 << (j - 1));   
            }
        }   
        f[t] = i;
    }
    for(int i = 1; i <= n; i++) {
        int t = 0;
        for(int j = 1; j <= m; j++) {
            if(a[i][j] < x) t |= (1 << (j - 1));
        }   
        int q = ok(t);
        if(q) {
            A = i, B = q;
            return true;
        }
    }
    return false;
}

void run(){
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    int l = 0, r = 1e9 + 1, mid;
    while(l < r) {
        mid = (l + r) >> 1;
        if(chk(mid)) l = mid + 1;
        else r = mid;   
    }
    cout << A << ' ' << B << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    while(cin >> n >> m) run();
    return 0;
}
