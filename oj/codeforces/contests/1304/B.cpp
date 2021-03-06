/*
 * Author:  heyuhhh
 * Created Time:  2020/2/15 21:09:39
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

string rev(string s) {
    reverse(all(s));   
    return s;
}

int n, m;
string s[N];
map <string, int> mp;

void run(){
    for(int i = 1; i <= n; i++) {
        cin >> s[i];
        mp[s[i]]++;
    }
    string ans = "", res = "";
    for(int i = 1; i <= n; i++) {
        if(mp[s[i]] && mp[rev(s[i])]) {
            string rs = rev(s[i]);
            if(s[i] == rs) {
                res = s[i];   
            } else {
                mp[s[i]]--;
                mp[rs]--;
                ans += s[i];
            }
        }   
    }
    string ans2 = rev(ans);
    ans += res;
    ans += ans2;
    cout << sz(ans) << '\n';
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    while(cin >> n >> m) run();
    return 0;
}
