/*
 * Author:  heyuhhh
 * Created Time:  2020/1/29 22:45:58
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

int n, x;
char s[N];
int pre[N];

void run(){
    cin >> n >> x;
    cin >> (s + 1);
    map <int, int> mp;
    int Max = -INF, Min = INF;
    for(int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1];
        if(s[i] == '0') ++pre[i];
        else --pre[i];  
        mp[pre[i]]++; 
        Max = max(Max, pre[i]);
        Min = min(Min, pre[i]);
    }
    if(pre[n] == 0) {
        int ans;
        if(x >= Min && x <= Max) ans = -1;
        else if(x == 0) ans = 1;
        else ans = 0;
        cout << ans << '\n';
        return;   
    }
    int ans = 0;
    for(int i = Min; i <= Max; i++) {
        int t = x - i;
        if(t % pre[n] == 0 && t / pre[n] >= 0) {
            ans += mp[i];
        }
    }
    if(x == 0) ++ans;
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
