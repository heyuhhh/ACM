/*
 * Author:  heyuhhh
 * Created Time:  2020/2/25 16:39:28
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
const int N = 200 + 5;

int n;
int a[N], b[N];
bool chk[N];

void run(){
    memset(a, 0, sizeof(a));
    memset(chk, false, sizeof(chk));
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> b[i];
        chk[b[i]] = true;
    }
    for(int i = 1; i <= n; i++) {
        a[2 * i - 1] = b[i];
        for(int j = b[i] + 1; j <= 2 * n; j++) if(!chk[j]) {
            chk[j] = true;   
            a[2 * i] = j;
            break;
        }
    }
    for(int i = 1; i <= 2 * n; i++) if(a[i] == 0) {
        cout << -1 << '\n';
        return;
    }
    for(int i = 1; i <= 2 * n; i++) {
        cout << a[i] << " \n"[i == 2 * n];   
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    int T; cin >> T;
    while(T--) run();
    return 0;
}
