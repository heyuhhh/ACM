/*
 * Author:  heyuhhh
 * Created Time:  2020/1/29 23:04:19
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
const int N = 1e5 + 5;

int n, m;
char s[N], t[N];
int nxt[N][26];

void run(){
    cin >> (s + 1) >> (t + 1);
    n = strlen(s + 1), m = strlen(t + 1);
    for(int i = 0; i < 26; i++) nxt[n][i] = 0;
    for(int i = n - 1; i >= 0; i--) {
        for(int j = 0; j < 26; j++) {
            if(s[i + 1] != 'a' + j) nxt[i][j] = nxt[i + 1][j];
            else nxt[i][j] = i + 1;
        }  
    }
    int ans = 1, now = 0;
    for(int i = 1; i <= m; i++) {
        while(1) {
            int to = nxt[now][t[i] - 'a'];
            if(now == 0 && to == 0) {
                cout << -1 << '\n';
                return;   
            }
            now = to;
            if(now != 0) break;
            else ++ans;
        }
    }
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
