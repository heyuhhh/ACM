/*
 * Author:  heyuhhh
 * Created Time:  2019/12/12 22:01:35
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

int n, k;
char s[N];
bool chk[26];

void run(){
    cin >> (s + 1);
    for(int i = 1; i <= k; i++) {
        char c; cin >> c;
        chk[c - 'a'] = 1;   
    }
    ll ans = 0;
    for(int i = 1, j; i <= n; i = j) {
        j = i;
        if(!chk[s[i] - 'a']) {
            ++j; continue;   
        }
        while(chk[s[j] - 'a']) ++j;
        ans += 1ll * (j - i + 1) * (j - i) / 2; 
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    while(cin >> n >> k) run();
    return 0;
}
