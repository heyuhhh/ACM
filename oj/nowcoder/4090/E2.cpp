/*
 * Author:  heyuhhh
 * Created Time:  2020/2/29 9:25:53
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

int n, q;
vector <int> p[N];

struct node {
    int l, r, id;
    bool operator < (const node &A) const {
        return l < A.l;
    }   
};

vector <node> v[N];
int ans[N];

void run(){
    for(int i = 1; i <= n; i++) {
        int x; cin >> x;
        for(int j = 1; 1ll * j * j <= x; j++) {
            if(x % j == 0) {
                p[j].push_back(i);
                if(x / j != j) {
                    p[x / j].push_back(i);   
                }
            }
        }   
    }
    for(int i = 1; i <= q; i++) {
        int l, r, x; cin >> l >> r >> x;
        for(int j = 1; 1ll * j * j <= x; j++) {
            if(x % j == 0) {
                v[j].push_back(node{l, r, i});  
                if(x / j != j) {
                    v[x / j].push_back(node{l, r, i});  
                } 
            }
        }   
    }
    for(int i = 1; i < N; i++) if(sz(p[i])) {
        sort(all(v[i]));
        int k = 0;
        for(int j = 0; j < sz(p[i]); j++) {
            while(k < sz(v[i]) && v[i][k].l <= p[i][j]) {
                if(v[i][k].r >= p[i][j]) ans[v[i][k].id] = i;
                ++k;
            }
        }
    }
    for(int i = 1; i <= q; i++) cout << ans[i] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    while(cin >> n >> q) run();
    return 0;
}
