/*
 * Author:  heyuhhh
 * Created Time:  2020/5/2 17:34:18
 */
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <iomanip>
#include <assert.h>
#define MP make_pair
#define fi first
#define se second
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define INF 0x3f3f3f3f
#define Local
#ifdef Local
  #define dbg(args...) do { cout << #args << " -> "; err(args); } while (0)
  void err() { std::cout << std::endl; }
  template<typename T, typename...Args>
  void err(T a, Args...args) { std::cout << a << ' '; err(args...); }
  template <template<typename...> class T, typename t, typename... A> 
  void err(const T <t> &arg, const A&... args) {
  for (auto &v : arg) std::cout << v << ' '; err(args...); }
#else
  #define dbg(...)
#endif
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
//head
const int N = 1e4;

int _;
int u;
pair <string, string> datas[N];
vector <char> all;
int ans[10];
bool chk[10], chk2[10];
map <char, int> mp;

bool dfs(int i) {
    if (i == N) {
        for (int i = 0; i < 10; i++) {
            if (ans[i] >= 10 || !chk[i]) return false;  
        }
        return true;
    }
    string s = datas[i].fi, t = datas[i].se;
    int len = s.length(), L = t.length();
    int x = 0;
    for (int i = 0; i < len; i++) {
        x = x * 10 + s[i] - '0';   
    }
    if (len == 1 || L == 1) {
        int up = (len > 1 ? 9 : x);
        for (int k = 1; k <= up; k++) if (!chk[k]) {
            int tmp = ans[mp[t[0]]];
            if (ans[mp[t[0]]] - 10 >= k || ans[mp[t[0]]] == k) {
                ans[mp[t[0]]] = k;
                chk[k] = true;
                if (dfs(i + 1)) return true;
                ans[mp[t[0]]] = tmp;
                chk[k] = false;
            }
        }   
    } else {
        vector <int> tmp;
        for (int cur = 0; cur < len; cur++) {
            tmp.push_back(ans[mp[t[cur]]]);
            for (int j = (cur == 0); j < s[cur] - '0'; j++) if (!chk[j]) {
                if (tmp[cur] - 10 >= j || tmp[cur] == j) {
                    ans[mp[t[cur]]] = j;
                    chk[j] = true;
                    if (dfs(i + 1)) return true;   
                    ans[mp[t[cur]]] = tmp[cur];
                    chk[j] = false;
                }
            }
            int up = s[cur] - '0';
            if (!chk[up] && (tmp[cur] - 10 >= up || tmp[cur] == up)) {
                ans[mp[t[cur]]] = up;
                chk[up] = true;   
            } else {
                break;   
            }
            if (cur == len - 1 && dfs(i + 1)) return true;
        }       
    }
    for (int cur = 0; cur < sz(tmp); cur++) {
        chk[ans[mp[t[cur]]]] = false;
        ans[mp[t[cur]]] = tmp[cur];
    }
    return false;
}

void run() {
    ++_; cin >> u;
    all.clear();
    for (int i = 0; i < N; i++) {
        string s, t; cin >> s >> t;
        datas[i] = MP(s, t);
        int len = t.length();
        for (int j = 0; j < len; j++) {
            bool ok = true;
            for (auto it : all) {
                if (it == t[j]) {
                    ok = false;
                }   
            }
            if (ok) {
                all.push_back(t[j]);   
            }
        }
    }
    for (int i = 0; i < sz(all); i++) mp[all[i]] = i;
    for (int i = 0; i < 10; i++) {
        ans[i] = 10 + 9; // <= i
        chk[i] = chk2[i] = false;
    }
    dfs(0);
    for (int i = 0; i < 10; i++) {
        cout << ans[i] << ' ';   
    } cout << '\n';
    for (int i = 0; i < 10; i++) {
        cout << all[ans[i]];   
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    int T; cin >> T; while(T--)
    run();
    return 0;
}
