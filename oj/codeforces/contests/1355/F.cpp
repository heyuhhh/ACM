/*
 * Author:  heyuhhh
 * Created Time:  2020/5/17 11:13:54
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
const int N = 1e3 + 5;
const int B = 630;
const ll MAX = 1e18;
int primes[N], tot;
bool vis[N];
void init() {
    for (int i = 2; i < N; i++) {
        if (!vis[i]) {
            primes[++tot] = i;
            vis[i] = true;
            for (ll j = 1ll * i * i; j < N; j += i) {
                vis[j] = true;
            }
        }
    }
}

ll query(ll x) {
    cout << "? " << x << endl;
    ll t; cin >> t;
    return t;   
}
void answer(int x) {
    cout << "! " << x << endl;
}

void run() {
    int cnt = 0;
    vector <int> d;
    for (int i = 0, j = 1; i < 17; i++) {
        ll x = 1;
        while (x <= MAX / primes[j]) {
            x *= primes[j];
            ++j;
        }
        int t = query(x);
        for (int k = 1; k <= j; k++) {
            if (t % primes[k] == 0) {
                d.push_back(primes[k]);
            }
        }       
    }
    
    auto gao = [&](int x) {
        int res = 1;
        while (1ll * res * x <= 1e9) {
            res *= x;
        }
        return res;
    };
    
	auto calc = [&](int& t, int x) {
		int cnt = 0;
		while (t % x == 0) {
			t /= x;
			++cnt;
		}
		return cnt;
	};
	
    int x1 = 1, c = 1;
    for (int i = 0; i < sz(d); i += 2) {
        ll now = 1;
    	now *= gao(d[i]);
        int j = i + 1;
        if (j < sz(d)) now *= gao(d[j]);
        int t = query(now);
        x1 *= t;
        c *= (calc(t, d[i]) + 1);
        if (j < sz(d)) {
            c *= (calc(t, d[j]) + 1);   
        }
	}
    if (x1 >= 4) answer(c << 1);
    if (x1 == 1) answer(8);
    if (x1 == 2 || x1 == 3) answer(9);
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
