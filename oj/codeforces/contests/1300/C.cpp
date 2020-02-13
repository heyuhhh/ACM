/*
 * Author:  heyuhhh
 * Created Time:  2020/2/9 22:24:07
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

int n;
int a[N];
bool chk[N];

void run(){
    for(int i = 1; i <= n; i++) cin >> a[i];
    vector <int> v[31];
    for(int i = 30; i >= 0; i--) {
        for(int j = 1; j <= n; j++) {
            if(a[j] >> i & 1) {
                v[i].push_back(j);
            }  
        }
        if(sz(v[i]) == 1) {
            chk[v[i][0]] = true;
            break;   
        }
    }
    for(int i = 1; i <= n; i++) if(chk[i]) cout << a[i] << ' ';
    for(int i = 1; i <= n; i++) if(!chk[i]) cout << a[i] << ' ';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    while(cin >> n) run();
    return 0;
}
