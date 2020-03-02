/*
 * Author:  heyuhhh
 * Created Time:  2020/1/16 14:58:26
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
const int N = 300 + 5;

int n;
int a[N];
int b[5], c[5];

int suf[N][N];
ll ans;

void gao(int pos, int cnt) {
    if(pos >= n) return;
    if(cnt == 3) {
        int op = 0;
        for(int i = 1; i <= 3; i++) {
            if(b[4] == b[i]) op = i;
        }   
        if(op == 0) {
            ans += n - pos - suf[pos + 1][c[1]] - suf[pos + 1][c[2]] - suf[pos + 1][c[3]];
            if(c[1] == c[2]) ans += suf[pos + 1][c[1]];
            if(c[2] == c[3]) ans += suf[pos + 1][c[2]];
            if(c[1] == c[3]) ans += suf[pos + 1][c[3]];
            if(c[1] == c[2] && c[2] == c[3]) ans -= suf[pos + 1][c[1]];
        } else {
            ans += suf[pos + 1][c[op]];   
        }
        return;
    }
    gao(pos + 1, cnt);
    int x = a[pos + 1];
    int ok = 1;
    for(int i = 1; i <= cnt; i++) {
        if((b[cnt + 1] == b[i]) != (x == c[i])) {
            ok = 0;
        }
    }
    if(ok) {
        c[cnt + 1] = x;
        gao(pos + 1, cnt + 1);   
    }
}

void run(){
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 1; i <= 4; i++) cin >> b[i];
    for(int i = n; i >= 1; i--) {
        for(int j = 0; j < N; j++) suf[i][j] = suf[i + 1][j];
        ++suf[i][a[i]];   
    }
    gao(0, 0);
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    while(cin >> n) run();
    return 0;
}
