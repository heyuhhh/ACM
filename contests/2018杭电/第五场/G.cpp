/*
 * Author:  heyuhhh
 * Created Time:  2020/5/8 11:15:33
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
const int N = 1e5 + 5, M = 5e6 + 5;

unsigned int X, Y, Z;
unsigned int rng61() {
	X ^= X << 11;
	X ^= X >> 4;
	X ^= X << 5;
	X ^= X >> 14;
	unsigned int tmp = X ^ Y ^ Z;
	X = Y;
	Y = Z;
	Z = tmp;
	return Z;
}

int lg[N];
void init() {
    lg[2] = 1;
    for (int i = 3; i < N; i++) lg[i] = lg[i >> 1] + 1;
}

int n, m;
int f[N][20];

void upd(int &x, int y) {
    if (x < y) x = y;
}

void run() {
    cin >> n >> m >> X >> Y >> Z;
    for (int i = 1; i <= n; i++) 
        for (int j = 0; j < 20; j++) 
            f[i][j] = 0;
    while (m--) {
		int L = rng61() % n + 1, R = rng61() % n + 1, v = rng61() & ((1 << 30) - 1);
        if (L > R) swap(L, R);
        int d = lg[R - L + 1];
        upd(f[L][d], v), upd(f[R - (1 << d) + 1][d], v);
    }
    for (int j = 19; j >= 1; j--) {
        for (int i = 1; i + (1 << (j - 1)) <= n; i++) {
            upd(f[i][j - 1], f[i][j]);
            upd(f[i + (1 << (j - 1))][j - 1], f[i][j]);
        }
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans ^= 1ll * i * f[i][0];
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    init();
    int T; cin >> T; while(T--)
    run();
    return 0;
}
