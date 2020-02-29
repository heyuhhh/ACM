/*
 * Author:  heyuhhh
 * Created Time:  2020/2/28 19:46:35
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
int a[N];
vector <int> d[N], d2[N], pos[N];

void init() {
    for(int i = 1; i < N; i++) {
        for(int j = i; j < N; j += i) {
            d[j].push_back(i); 
            for(auto it : pos[j]) {
                d2[i].push_back(it);   
            }
        }  
    } 
    for(int i = 1; i < N; i++) {
        sort(all(d[i]));
        reverse(all(d[i]));   
        sort(all(d2[i]));
    }
}

void run(){
    for(int i = 1; i <= n; i++) {
        cin >> a[i]; 
        pos[a[i]].push_back(i);
    }
    init();
    while(q--) {
        int l, r, x;
        cin >> l >> r >> x;
        for(auto it : d[x]) {
            auto L = lower_bound(all(d2[it]), l) - d2[it].begin();
            if(L < sz(d2[it]) && d2[it][L] >= l && d2[it][L] <= r) {
                cout << it << '\n';
                break;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    while(cin >> n >> q) run();
    return 0;
}
