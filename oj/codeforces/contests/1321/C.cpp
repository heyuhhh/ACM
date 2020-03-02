/*
 * Author:  heyuhhh
 * Created Time:  2020/3/1 21:20:13
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
const int N = 100 + 5;

int n;
char s[N];
bool chk[N];

void run(){
    memset(chk, 0, sizeof(chk));
    cin >> (s + 1);
    int ans = 0;
    for(int i = 25; i >= 1; i--) {
        for(int j = 1; j <= n; j++) {
            if(s[j] - 'a' == i) {
                bool ok = false;
                for(int k = j - 1; k >= 1; k--) {
                    if(!chk[k] && s[k] != s[j]) {
                        if(s[k] - 'a' == i - 1) ok = true;
                        break;   
                    }
                }   
                for(int k = j + 1; k <= n; k++) {
                    if(!chk[k] && s[k] != s[j]) {
                        if(s[k] - 'a' == i - 1) ok = true;
                        break;   
                    }
                }
                if(ok) {
                    ++ans;
                    chk[j] = true;   
                }
            }
        }   
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    while(cin >> n) run();
    return 0;
}
