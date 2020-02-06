/*
 * Author:  heyuhhh
 * Created Time:  2020/2/4 22:48:22
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

void run(){
    cin >> n >> (s + 1);
    map <int, map<int, int>> mp;
    int x = 0, y = 0;
    mp[x][y] = 0;
    int ans = INF, l, r;
    for(int i = 1; i <= n; i++) {
        if(s[i] == 'L') --x;
        if(s[i] == 'R') ++x;
        if(s[i] == 'U') ++y;
        if(s[i] == 'D') --y;
        if(mp[x].find(y) == mp[x].end()) {
            mp[x][y] = i;   
        } else {
            if(i - mp[x][y] < ans) {
                ans = i - mp[x][y];
                l = mp[x][y] + 1, r = i;   
            }
            mp[x][y] = i;
        }
    }
    if(ans == INF) cout << -1 << '\n';
    else cout << l << ' ' << r << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    int T; cin >> T;
    while(T--) run();
    return 0;
}
