/*
 * Author:  heyuhhh
 * Created Time:  2020/2/3 11:14:11
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

char s[N];
int pre[N][26];

void run(){
    int n, q;
    cin >> (s + 1);
    n = strlen(s + 1);
    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < 26; j++) {
            pre[i][j] = pre[i - 1][j];
        }   
        ++pre[i][s[i] - 'a'];
    }
    cin >> q;
    while(q--) {
        int l, r; cin >> l >> r;
        if(l == r || s[l] != s[r]) {
            cout << "YES" << '\n';
            continue;
        }   
        vector <int> cnt(26, 0);
        int t = 0;
        for(int i = 0; i < 26; i++) {
            cnt[i] = pre[r][i] - pre[l - 1][i];
            if(cnt[i]) ++t;
        }
        if(t > 2) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
