/*
 * Author:  heyuhhh
 * Created Time:  2020/2/4 11:56:17
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

int n, k;
bool chk[N];

int query(int c) {
    cout << '?' << ' ' << c << endl;
    char t; cin >> t;
    if(t == 'Y') return 1;
    return 0;
}
void reset() {
    cout << 'R' << endl;   
}

int block, num;
void add(int x) {
    for(int i = (x - 1) * block + 1; i <= min(n, x * block); i++) {
        if(query(i)) chk[i] = true;
    }
}

void run(){
    int ans = 0;
    block = k, num = n / k;
    for(int i = 1; i <= n / k; i++) {
        if(i * k + 1 > n) add(i);
        for(int j = i * k + 1; j <= n; j++) {
            add(i);  
            if(query(j)) chk[j] = true;
            reset();
        } 
    }
    for(int i = 1; i <= n; i++) if(!chk[i]) ++ans;
    cout << '!' << ' ' << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    while(cin >> n >> k) run();
    return 0;
}
