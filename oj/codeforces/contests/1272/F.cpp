/*
 * Author:  heyuhhh
 * Created Time:  2019/12/13 11:40:50
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

struct node {
    int i, j, k;   
};

node pre[N][N][N << 1];
int dp[N][N][N << 1];
int n, m;
char s[N], t[N];

void run(){
    cin >> (s + 1) >> (t + 1);
    n = strlen(s + 1);
    m = strlen(t + 1);
    memset(dp, INF, sizeof(dp));
    dp[0][0][0] = 0;
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            if(i == n && j == m) break;
            for(int k = 0; k < N; k++) if(dp[i][j][k] != INF) {
                if(s[i + 1] == t[j + 1]) {
                    if(s[i + 1] == ')') {
                        if(k == 0) {
                            if(dp[i][j][k + 1] > dp[i][j][k] + 1) {
                                dp[i][j][k + 1] = dp[i][j][k] + 1;
                                pre[i][j][k + 1] = node {i, j, k};   
                            }
                        } 
                        if(dp[i + 1][j + 1][k - 1] > dp[i][j][k] + 1) {
                            dp[i + 1][j + 1][k - 1] = dp[i][j][k] + 1;
                            pre[i + 1][j + 1][k - 1] = node {i, j, k};   
                        }
                    } else if(s[i + 1] == '(') {
                        if(dp[i + 1][j + 1][k + 1] > dp[i][j][k] + 1) {
                            dp[i + 1][j + 1][k + 1] = dp[i][j][k] + 1;
                            pre[i + 1][j + 1][k + 1] = node {i, j, k};
                        }   
                    }
                } else {
                    if(s[i + 1] == ')') {
                        if(k == 0) {
                            if(dp[i][j][k + 1] > dp[i][j][k] + 1) {
                                dp[i][j][k + 1] = dp[i][j][k] + 1;
                                pre[i][j][k + 1] = node {i, j, k};
                            }   
                        }
                        if(dp[i + 1][j][k - 1] > dp[i][j][k] + 1) {
                            dp[i + 1][j][k - 1] = dp[i][j][k] + 1;
                            pre[i + 1][j][k - 1] = node {i, j, k};   
                        }
                    } else if(s[i + 1] == '(') {
                        if(dp[i + 1][j][k + 1] > dp[i][j][k] + 1) {
                            dp[i + 1][j][k + 1] = dp[i][j][k] + 1;
                            pre[i + 1][j][k + 1] = node {i, j, k};
                        }   
                    }  
                    if(t[j + 1] == ')') {
                        if(k == 0) {
                            if(dp[i][j][k + 1] > dp[i][j][k] + 1) {
                                dp[i][j][k + 1] = dp[i][j][k] + 1;
                                pre[i][j][k + 1] = node {i, j, k};
                            }  
                        }
                        if(dp[i][j + 1][k - 1] > dp[i][j][k] + 1) {
                            dp[i][j + 1][k - 1] = dp[i][j][k] + 1;
                            pre[i][j + 1][k - 1] = node {i, j, k};   
                        }
                    } else if(t[j + 1] == '(') {
                        if(dp[i][j + 1][k + 1] > dp[i][j][k] + 1) {
                            dp[i][j + 1][k + 1] = dp[i][j][k] + 1;
                            pre[i][j + 1][k + 1] = node {i, j, k};
                        }   
                    }
                }
            }
        }   
    }
    int Min = INF;
    node ans;
    for(int i = 0; i < N; i++) {
        if(dp[n][m][i] + i < Min) {
            Min = dp[n][m][i] + i;
            ans = node {n, m, i};   
        }
    }
    //for(int i = 400; i < 410; i++) {
        //cout << dp[1][3][i] << '\n';   
    //}
    string res = "";
    node now = ans, last;
    while(1) {
         last = pre[now.i][now.j][now.k];
         //dbg(now.i, now.j, now.k, dp[now.i][now.j][now.k]);
         if(last.k > now.k) res += ")";
         else res += "(";
         now = last;
         if(now.i == 0 && now.j == 0 && now.k == 0) break;
    }
    reverse(res.begin(), res.end());
    for(int i = 0; i < ans.k; i++) res += ")";
    cout << res << '\n';;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
