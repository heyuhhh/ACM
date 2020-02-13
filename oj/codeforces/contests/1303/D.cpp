/*
 * Author:  heyuhhh
 * Created Time:  2020/2/12 23:21:06
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

int a[N];
int cnt[64];

void run(){ 
    for(int i = 0; i < 64; i++) cnt[i] = 0;
    ll n; int m;
    cin >> n >> m;
    ll sum = 0;
    for(int i = 1; i <= m; i++) {
        cin >> a[i]; sum += a[i];
        int x = a[i] / 2, t = 0;
        while(x) t++, x /= 2; 
        ++cnt[t];
    }
    if(sum < n) {
        cout << -1 << '\n';
        return;   
    }
    int ans = 0;
    for(int i = 0; i < 64; i++) {
        bool need = false;
        if(n >> i & 1) need = true;
        if(cnt[i] == 0 && need) {
            for(int j = i + 1; j < 64; j++) {
                if(cnt[j] >= 1) {
                    ans += j - i;
                    for(int k = i; k < j; k++) ++cnt[k];
                    ++cnt[i], --cnt[j];
                    break;
                } 
            }
        }
        if(need) --cnt[i];
        cnt[i + 1] += cnt[i] / 2;
    }
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
