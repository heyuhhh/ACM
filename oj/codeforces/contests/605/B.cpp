/*
 * Author:  heyuhhh
 * Created Time:  2019/12/12 21:46:47
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

char s[N];
int d[4];

void run(){
    cin >> (s + 1);
    int n = strlen(s + 1);
    for(int i = 0; i < 4; i++) d[i] = 0;
    for(int i = 1; i <= n; i++) {
        if(s[i] == 'U') ++d[0];
        if(s[i] == 'D') ++d[1];
        if(s[i] == 'L') ++d[2];
        if(s[i] == 'R') ++d[3];
    }
    int min1 = min(d[0], d[1]), min2 = min(d[2], d[3]);
    if(min1 == 0 && min2 == 0) {
        cout << 0 << '\n';
        return;
    } else if(min1 == 0) {
        cout << "2\nLR" << '\n';
        return ;
    } else if(min2 == 0) {
        cout << "2\nUD" << '\n'; 
        return;
    }
    int ans = 2 * min1 + 2 * min2;
    cout << ans << '\n';
    for(int i = 1; i <= min1; i++) cout << 'U';
    for(int i = 1; i <= min2; i++) cout << 'L';
    for(int i = 1; i <= min1; i++) cout << 'D';
    for(int i = 1; i <= min2; i++) cout << 'R';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    int T; cin >> T;
    while(T--) run();
    return 0;
}
