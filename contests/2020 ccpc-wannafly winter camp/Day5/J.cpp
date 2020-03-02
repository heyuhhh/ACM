/*
 * Author:  heyuhhh
 * Created Time:  2020/2/12 11:01:42
 */
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <bitset>
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
const int N = 1024 + 5, M = 35, MOD = 1e9 + 7;

int qpow(ll a, ll b) {
    ll res = 1;
    while(b) {
        if(b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;   
    }
    return res;   
}

int k;
bool chk[N];
bitset <N> a[N], p[N];

char f[M][M];

int id(int x, int y) {
    return (x - 1) * (1 << k) + y;
}

void run(){
    for(int i = 1; i <= 1 << k; i++) {
        cin >> (f[i] + 1);
    }
    int t = 1 << k;
    for(int x = 1; x <= t; x++) {
        for(int y = 1; y <= t; y++) {
            int now = id(x, y);
            for(int i = 1; i <= t; i++) {
                for(int j = 1; j <= t; j++) {
                    if(f[i][j] == '1') {
                        a[now][id((x + i - 1) % t + 1, (y + j - 1) % t + 1)] = 1;
                    }
                }
            }
        }
    }
    int s = 0;
    for(int i = 1; i <= t * t; i++) {
        for(int j = t * t; j >= 1; j--) if(a[i][j]){
            if(!chk[j]) {
                chk[j] = true;
                p[j] = a[i];
                ++s;
                break;   
            }
            a[i] = a[i] ^ p[j];
        }   
    }
    int ans = qpow(2, s);
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    while(cin >> k) run();
    return 0;
}
