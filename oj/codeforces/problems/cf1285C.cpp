/*
 * Author:  heyuhhh
 * Created Time:  2020/1/25 12:37:09
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
#define INF 0x3f3f3f3f3f3f3f3f
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

ll n, x;
ll Max = INF;
ll A, B;

void dfs(int cnt, vector <ll>& d, ll a) {
    if(cnt == sz(d)) {
        ll b = x / a;
        if(max(a, b) < Max) {
            Max = max(a, b); 
            A = a, B = b;  
        }
        return;   
    }
    dfs(cnt + 1, d, a);
    dfs(cnt + 1, d, a * d[cnt]);
}

void run(){
    x = n;
    vector <ll> d;
    for(int i = 2; 1ll * i * i <= n; i++) {
        if(n % i == 0) {
            ll t = 1;
            while(n % i == 0) {
                t *= i;
                n /= i;
            } 
            d.push_back(t);  
        }
    }
    if(n > 1) d.push_back(n);
    dfs(0, d, 1);
    cout << A << ' ' << B << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    while(cin >> n) run();
    return 0;
}
