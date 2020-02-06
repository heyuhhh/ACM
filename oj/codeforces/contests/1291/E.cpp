/*
 * Author:  heyuhhh
 * Created Time:  2020/2/3 18:28:54
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
const int N = 3e5 + 5;

int n, k;
char s[N];
int bel[N][2];
int f[N + N], cnt[N + N];
int find(int x) {
    return f[x] == x ? f[x] : f[x] = find(f[x]);   
}
int calc(int x) {
    int y = x + k;
    int fx = find(x), fy = find(y);
    if(fx == 0 || fy == 0) return cnt[fx + fy];
    return min(cnt[fx], cnt[fy]);
}
void merge(int x, int y) {
    int fx = find(x), fy = find(y);
    if(fx == 0) swap(fx, fy);
    f[fx] = fy;
    if(fy != 0) cnt[fy] += cnt[fx];
}
void run(){
    cin >> (s + 1);
    for(int i = 1; i <= k; i++) {
        int x; cin >> x;
        for(int j = 1; j <= x; j++) {
            int t; cin >> t;
            if(bel[t][0] == 0) bel[t][0] = i;
            else bel[t][1] = i;
        }
    }
    for(int i = 1; i <= k + k; i++) f[i] = i;
    for(int i = 1; i <= k; i++) cnt[i] = 1;
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        if(bel[i][1] == 0) {
            int x = bel[i][0];
            if(x) {
                ans -= calc(x);
                if(s[i] == '0') {
                    f[find(x + k)] = 0;
                } else {
                    f[find(x)] = 0;
                }
                ans += calc(x);
            }
        } else {
            int x = bel[i][0], y = bel[i][1];
            if(s[i] == '0') {
                if(find(x + k) != find(y)) {
                    ans -= calc(x) + calc(y);
                    merge(x + k, y);
                    merge(x, y + k);
                    ans += calc(x);
                }
            } else {
                if(find(x) != find(y)) {
                    ans -= calc(x) + calc(y);
                    merge(x, y);
                    merge(x + k, y + k);   
                    ans += calc(x);
                }
            }
        }
        cout << ans << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    while(cin >> n >> k) run();
    return 0;
}
