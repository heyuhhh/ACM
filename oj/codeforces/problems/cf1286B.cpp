/*
 * Author:  heyuhhh
 * Created Time:  2020/1/28 10:59:22
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
const int N = 2000 + 5;

int n;
bool chk[N];
vector <int> G[N];
int a[N], c[N];

void dfs(int u) {
    int T = 0;
    for(int i = 1; i < N; i++) {
        if(!chk[i]) ++T;
        if(T == c[u] + 1) {
            a[u] = i;
            chk[i] = true;
            break;
        }
    }
    for(auto v : G[u]) dfs(v);
}

int dfs2(int u, int x) {
    int res = (a[u] < x);
    for(auto v : G[u]) res += dfs2(v, x);
    return res;
}

void run(){
    int rt;
    for(int i = 1; i <= n; i++) {
        int p; cin >> p >> c[i];
        if(p == 0) rt = i;
        else G[p].push_back(i);
    }
    dfs(rt);
    for(int i = 1; i <= n; i++) {
        int x = dfs2(i, a[i]);   
        if(x != c[i]) {
            cout << "NO" << '\n';
            return;    
        }
    }
    cout << "YES" << '\n';
    for(int i = 1; i <= n; i++) cout << a[i] << ' ';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    while(cin >> n) run();
    return 0;
}
