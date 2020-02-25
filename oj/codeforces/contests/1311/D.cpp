/*
 * Author:  heyuhhh
 * Created Time:  2020/2/24 23:39:25
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
const int N = 20000 + 5;

int a, b, c;
vector <int> d[N];

void init() {
    for(int i = 1; i <= 20000; i++) {
        for(int j = 1; 1ll * j * j <= i; j++) {
            if(i % j == 0) {
                d[i].push_back(j);
                int k = i / j;
                if(j != k) d[i].push_back(k);
            }   
        }
        sort(all(d[i]));
    }   
}

void run(){
    cin >> a >> b >> c;
    pair<pii, int> ans;
    int Min = INF;
    for(int i = 1; i <= 20000; i++) {
        int aa, bb, cc;
        int res = abs(b - i);
        bb = i;
        int t = lower_bound(all(d[i]), a) - d[i].begin();
        if(abs(d[i][t] - a) > abs(d[i][max(0, t - 1)] - a)) {
            aa = d[i][max(0, t - 1)];
            res += abs(d[i][max(0, t - 1)] - a);
        } else {
            aa = d[i][t];
            res += abs(d[i][t] - a);
        }
        int v1 = c / i * i, v2 = (c / i + 1) * i;
        if(abs(v1 - c) > abs(v2 - c)) {
            cc = v2;
            res += abs(v2 - c);
        } else {
            cc = v1;
            res += abs(v1 - c);
        }
        if(res < Min) {
            Min = res;   
            ans = MP(MP(aa, bb), cc);
        }
    }
    cout << Min << '\n';
    cout << ans.fi.fi << ' ' << ans.fi.se << ' ' << ans.se << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    init();
    int T; cin >> T;
    while(T--) run();
    return 0;
}
