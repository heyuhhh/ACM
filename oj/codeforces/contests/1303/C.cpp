/*
 * Author:  heyuhhh
 * Created Time:  2020/2/12 22:54:42
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
const int N = 200 + 5;

int n, tot;
char s[N], ans[26];
bool mp[26][26], chk[26];

bool dfs(int u) {
    chk[u] = true;
    ans[++tot] = 'a' + u;
    for(int i = 0; i < 26; i++) if(mp[u][i]) {
        if(chk[i]) return false;
        mp[u][i] = mp[i][u] = 0;
        if(!dfs(i)) return false;   
        mp[u][i] = mp[i][i] = 1;
    }
    return true;
}

void run(){
    memset(chk, 0, sizeof(chk));
    memset(mp, 0, sizeof(mp));
    tot = 0;
    cin >> (s + 1);
    n = strlen(s + 1);
    for(int i = 2; i <= n; i++) {
        mp[s[i] - 'a'][s[i - 1] - 'a'] = mp[s[i - 1] - 'a'][s[i] - 'a'] = 1;
    }
    for(int i = 0; i < 26; i++) {
        int t = 0;
        for(int j = 0; j < 26; j++) {
            if(mp[i][j]) ++t;
        }   
        if(t == 1) {
            if(!chk[i] && !dfs(i)) {
                cout << "NO" << '\n';
                return;
            }   
        }
        if(t > 2) {
            cout << "NO" << '\n';
            return;   
        }
    }
    for(int i = 0; i < 26; i++) {
        if(!chk[i] && !dfs(i)) {
            cout << "NO" << '\n';
            return;
        }
    }
    cout << "YES" << '\n';
    for(int i = 1; i <= tot; i++) cout << ans[i];
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
