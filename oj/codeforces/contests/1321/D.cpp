/*
 * Author:  heyuhhh
 * Created Time:  2020/3/1 21:40:33
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

int n, m;
vector <int> G[N], rG[N];
int k;
int p[N];
int d[N];

void run(){
    for(int i = 1; i <= m; i++) {
        int u, v; cin >> u >> v;
        G[u].push_back(v);
        rG[v].push_back(u);
    }
    cin >> k;
    for(int i = 1; i <= k; i++) cin >> p[i];
    memset(d, INF, sizeof(d)); d[p[k]] = 0;
    queue <int> q; q.push(p[k]); 
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(auto v : rG[u]) {
            if(d[v] > d[u] + 1) {
                d[v] = d[u] + 1;
                q.push(v);   
            }
        }
    }
    int Min = 0, Max = 0;
    for(int i = 1; i < k; i++) {
        int can = 0;
        for(auto v : G[p[i]]) {
            if(d[v] + 1 == d[p[i]]) ++can;
        }
        if(d[p[i + 1]] + 1 != d[p[i]]) {
            ++Min, ++Max;
        } else if(can > 1) ++Max;
    }
    cout << Min << ' ' << Max << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    while(cin >> n >> m) run();
    return 0;
}
