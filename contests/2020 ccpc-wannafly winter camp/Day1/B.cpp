/*
 * Author:  heyuhhh
 * Created Time:  2020/1/12 13:44:51
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
const int N = 1005, M = 105;

int n, m;

char s[N][M];
int x[N], y[N];

char trans(char a, char b) {
    int x, y;
    if(a <= 'Z') x = a - 'A' + 26;
    else x = a - 'a';
    if(b <= 'Z') y = b - 'A' + 26;
    else y = b - 'a';
    int z = (y - x + 52) % 52;
    if(z <= 25) return z + 'a';
    else return z - 26 + 'A';
}

void run(){
    for(int i = 1; i <= m; i++) cin >> x[i] >> y[i];
    for(int i = 1; i <= n; i++) cin >> (s[i] + 1);
    for(int i = m; i >= 1; i--) {
        int len = strlen(s[x[i]] + 1);
        int len2 = strlen(s[y[i]] + 1);
        for(int j = 1; j <= len2; j++) {
            s[y[i]][j] = trans(s[x[i]][(j - 1) % len + 1], s[y[i]][j]);   
        }
    }
    for(int i = 1; i <= n; i++) {
        cout << (s[i] + 1) << '\n';   
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    while(cin >> n >> m) run();
    return 0;
}
