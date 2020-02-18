/*
 * Author:  heyuhhh
 * Created Time:  2020/2/15 10:49:29
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
const int N = 500 + 5, M = 3e5 + 5;

int n, m, q;
ll sum[4][N][N], cnt[N][N];
char s[N][N];
int r1[M], r2[M], c1[M], c2[M];
int ans[M];
string ss = "RGYB";

void run(){
    for(int i = 1; i <= n; i++) {
        cin >> (s[i] + 1);
        for(int j = 1; j <= m; j++) {
            for(int k = 0; k < 4; k++) if(ss[k] == s[i][j]) {
                sum[k][i][j] = 1;
            }
        }
    }
    for(int k = 0; k < 4; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                sum[k][i][j] += sum[k][i - 1][j];
            }
        }
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                sum[k][i][j] += sum[k][i][j - 1];
            }
        }
    }
    auto query = [&](int k, int r1, int c1, int r2, int c2) {
        return sum[k][r2][c2] - sum[k][r2][c1 - 1] - sum[k][r1 - 1][c2] + sum[k][r1 - 1][c1 - 1];
    };
    auto query2 = [&](int r1, int c1, int r2, int c2) {
        if(r2 < r1 || c2 < c1) return false;
        return cnt[r2][c2] - cnt[r2][c1 - 1] - cnt[r1 - 1][c2] + cnt[r1 - 1][c1 - 1] > 0;   
    };
    for(int i = 1; i <= q; i++) {
        cin >> r1[i] >> c1[i] >> r2[i] >> c2[i];
    }
    for(int l = 1; l <= 250; l++) {
        if(2 * l > n || 2 * l > m) break;
        memset(cnt, 0, sizeof(cnt));
        for(int i = 1; i <= n - 2 * l + 1; i++) {
            for(int j = 1; j <= m - 2 * l + 1; j++) {
                if(query(0, i, j, i + l - 1, j + l - 1) == l * l &&
                    query(1, i, j + l, i + l - 1, j + 2 * l - 1) == l * l && 
                    query(2, i + l, j, i + 2 * l - 1, j + l - 1) == l * l &&
                    query(3, i + l, j + l, i + 2 * l - 1, j + 2 * l - 1) == l * l
                ) cnt[i][j] = 1;
            }
        }
        for(int i = 1; i <= n - 2 * l + 1; i++) {
            for(int j = 1; j <= m - 2 * l + 1; j++) {
                cnt[i][j] += cnt[i - 1][j];
            }
        }
        for(int i = 1; i <= n - 2 * l + 1; i++) {
            for(int j = 1; j <= m - 2 * l + 1; j++) {
                cnt[i][j] += cnt[i][j - 1];
            }
        }
        for(int i = 1; i <= q; i++) {
            if(query2(r1[i], c1[i], r2[i] - 2 * l + 1, c2[i] - 2 * l + 1)) ans[i] = l;
        }
    }
    for(int i = 1; i <= q; i++) cout << 4 * ans[i] * ans[i] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    while(cin >> n >> m >> q) run();
    return 0;
}
