/*
 * Author:  heyuhhh
 * Created Time:  2020/3/31 22:01:11
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
  void err() { std::cout << '\n'; }
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
const int N = 1000 + 5;

int n;
int a[N], col[N];
int primes[N], tot;
bool vis[N];

void init() {
    for(int i = 2; i < N; i++) {
        if(!vis[i]) primes[++tot] = i;
        for(int j = i * i; j < N; j += i) vis[j] = true;   
    }
}

void run() {
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];
    vector <vector <int>> c, p;
    c.resize(12); p.resize(n + 1);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= 11; j++) {
            if(a[i] % primes[j] == 0) {
                c[j].push_back(i);
                p[i].push_back(j);
            }
        }
    }
    memset(col, -1, sizeof(col));
    for(int i = 1; i <= 11; i++) {
        for(auto it : c[i]) {
            if(col[it] == -1) {
                col[it] = i;
                break;
            }   
        }
    }
    for(int i = 1; i <= n; i++) if(col[i] == -1) col[i] = p[i][0];
    map <int, int> mp; int num = 0;
    for(int i = 1; i <= n; i++) {
        if(!mp[col[i]]) mp[col[i]] = ++num;
        col[i] = mp[col[i]];
    }
    cout << num << '\n';
    for(int i = 1; i <= n; i++) cout << col[i] << " \n"[i == n];
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
