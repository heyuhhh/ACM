/*
 * Author:  heyuhhh
 * Created Time:  2019/12/21 10:03:44
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
const int N = 100 + 5;

char s[N], t[N];

int pre[26];
int sum[N][26];

void run(){
    memset(pre, 0, sizeof(pre));
    cin >> (s + 1) >> (t + 1);
    int n = strlen(s + 1);
    for(int i = 1; i <= n; i++) ++pre[s[i] - 'a'];
    int m = strlen(t + 1);
    for(int i = 1; i <= m; i++) {
        for(int j = 0; j < 26; j++) sum[i][j] = sum[i - 1][j];
        ++sum[i][t[i] - 'a'];   
    }
    for(int i = 1; i <= m; i++) {
        for(int j = i; j <= m; j++) {
            static int cnt[26];
            for(int k = 0; k < 26; k++) cnt[k] = sum[j][k] - sum[i - 1][k];
            bool flag = false;
            for(int k = 0; k < 26; k++) {
                if(cnt[k] != pre[k]) flag = true;
            }       
            if(flag == false) {
                cout << "YES" << '\n';
                return;   
            }
        }
    }
    cout << "NO" << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    int T; cin >> T;
    while(T--) run();
    return 0;
}
