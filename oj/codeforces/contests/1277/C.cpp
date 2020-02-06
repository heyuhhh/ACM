/*
 * Author:  heyuhhh
 * Created Time:  2019/12/14 19:26:17
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

char s[N];
int del[N];

bool chk1(int p) {
    return s[p] == 'o' && s[p + 1] == 'n' && s[p + 2] == 'e';  
}

bool chk2(int p) {
    return s[p] == 't' && s[p + 1] == 'w' && s[p + 2] == 'o';   
}

void run(){
    cin >> (s + 1);
    int n = strlen(s + 1);
    for(int i = 1; i <= n; i++) del[i] = 0;
    for(int i = 1; i <= n - 2; i++) {
        if(chk2(i)) {
            if(i + 3 <= n && s[i + 3] == 'o') del[i + 1] = 1;
            else del[i + 2] = 1;
        }   
        if(chk1(i)) {
            if(i - 1 >= 1 && s[i - 1] == 'o') del[i + 1] = 1;
            else del[i] = 1;   
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) ans += del[i];
    cout << ans << '\n';
    for(int i = 1; i <= n; i++) if(del[i]) cout << i << ' ';
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
