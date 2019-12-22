/*
 * Author:  heyuhhh
 * Created Time:  2019/12/21 10:16:12
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
int a[N];
int x[N], y[N];
int q[N], top;
int q2[N], top2;

int find(int A, int B) {
    if(A == B) return n + 1;
    if(A > B) return q2[A - B];
    return q[B - A];
}

void run(){
    cin >> n;
    top = top2 = 0; 
    for(int i = 1; i <= 2 * n; i++) q[i] = q2[i] = 0;
    for(int i = 1; i <= 2 * n; i++) cin >> a[i];
    int r = 0, b = 0;
    for(int i = 1; i <= 2 * n; i++) {
        if(a[i] == 1) ++r; else ++b;
    }
    x[n + 1] = y[n + 1] = 0;
    for(int i = n; i >= 1; i--) {
        x[i] = x[i + 1]; y[i] = y[i + 1];   
        if(a[i] == 1) ++x[i]; else ++y[i];
        if(x[i] - y[i] > x[q2[top2]] - y[q2[top2]]) q2[++top2] = i;
        if(y[i] - x[i] > y[q[top]] - x[q[top]]) q[++top] = i;
    }
    int ans = 2 * n;
    int curr = 0, curb = 0;
    for(int i = n + 1; i <= 2 * n; i++) {
        if(a[i] == 1) ++curr;
        else ++curb;
        int nr = r - curr, nb = b - curb;
        int p = find(nr, nb);
        if(p) ans = min(ans, i - p + 1);
    }
    curr = curb = 0;
    for(int i = n; i >= 1; i--) {
        if(a[i] == 1) ++curr;
        else ++curb;
        if(r - curr == b - curb) {
            ans = min(ans, n - i + 1);   
        }
    }
    if(r == b) ans = 0;
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    int T; cin >> T;
    while(T--) run();
    return 0;
}
