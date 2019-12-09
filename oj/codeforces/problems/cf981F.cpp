/*
 * Author:  heyuhhh
 * Created Time:  2019/11/5 19:43:44
 */
#include <bits/stdc++.h>
#define MP make_pair
#define fi first
#define se second
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for(int i = a; i <= b; i++)
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
int n, L;
ll a[N << 2], b[N << 2];

bool chk(int x) {
    int p1 = 1, p2 = 1;
    int mn = INF;
    for(int i = 1; i <= 2 * n; i++) {
        while(p1 <= 4 * n && b[p1] < a[i] - x) ++p1;   
        while(p2 <= 4 * n && b[p2] <= a[i] + x) ++p2;
        mn = min(mn, i - p1);
        int now = i - p2 + 1;
        if(mn < now) return false;
    }
    return true;
}

void run(){
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= n; i++) cin >> b[i];
    sort(a + 1, a + n + 1); sort(b + 1, b + n + 1);
    for(int i = 1; i <= n; i++) a[i] += L, a[i + n] = a[i] + L;
    for(int i = 1; i <= 3 * n; i++) b[i + n] = b[i] + L;
    int l = 0, r = INF, mid;
    while(l < r) {
        mid = (l + r) >> 1;
        if(chk(mid)) r = mid;
        else l = mid + 1;
    }
    cout << l << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    while(cin >> n >> L) run();
	return 0;
}
