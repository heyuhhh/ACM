/*
 * Author:  heyuhhh
 * Created Time:  2020/3/1 19:47:54
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
int a[N], add[N];
ll cnt[N], ans;

void run() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        cnt[i] = a[i];
        ans += cnt[i];   
    }
    map <pii, int> mp;
    int q; cin >> q;
    while(q--) {
        int s, t, u; cin >> s >> t >> u;
        if(mp.find(MP(s, t)) != mp.end()) {
            int nu = mp[MP(s, t)];
            mp.erase(mp.find(MP(s, t)));
            if(cnt[s] + add[s] >= t) {
                if(add[nu]) --add[nu];
                if(cnt[nu] + add[nu] < a[nu]) ++cnt[nu], ++ans;
            }
        } 
        mp[MP(s, t)] = u;
        if(cnt[s] + add[s] >= t) {
            ++add[u];
            if(cnt[u] > 0) --ans, --cnt[u];                      
        }
        cout << ans << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
