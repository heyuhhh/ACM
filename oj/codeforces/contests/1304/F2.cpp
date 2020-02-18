/*
 * Author:  heyuhhh
 * Created Time:  2020/2/17 10:08:57
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
const int N = 50 + 5, M = 2e4 + 5;

int n, m, k;
int a[N][M];
int lmax[M], rmax[M];

int calc(vector<int>& v, int l, int r) {
    return v[r] - v[l - 1];   
}

int calc(vector<vector<int>>& v, int i, int l, int r) {
    return calc(v[i], l, r) + calc(v[i + 1], l, r);   
}

void solve(int i, vector<int> res, vector<int> &arr, vector<int> p, int op) {
    if(op) {
        vector <int> t(m + 3);
        for(int j = 1; j <= m; j++) {
            t[j] = p[m - j + 1];
        }
        p.swap(t);
    }
    deque <pii> q;
    for(int j = 1; j <= m - k + 1; j++) {
        int now = (op ? res[m - j - k + 2] : res[j]) - calc(p, j, j + k - 1);
        if(sz(q) && q.front().se <= j - k) q.pop_front();
        while(sz(q) && q.back().fi + calc(p, q.back().se, j - 1) <= now) q.pop_back();
        q.push_back(MP(now, j));
        arr[j] = q.front().fi + calc(p, q.front().se, j - 1);
    }
}

void run(){
    vector <vector <int>> pre(n + 2, vector<int>(m + 3, 0)), suf(n + 2, vector<int>(m + 3, 0));
    vector <vector <int>> dp(n + 2, vector<int>(m + 3, 0));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> a[i][j];
            pre[i][j] = pre[i][j - 1] + a[i][j];
        }
        for(int j = m; j >= 1; j--) {
            suf[i][j] = suf[i][j + 1] + a[i][j];   
        }
    }
    auto init = [&](int i) {
        for(int j = 1; j <= m; j++) {
            lmax[j] = max(lmax[j - 1], dp[i][j]);
        }   
        for(int j = m; j >= 1; j--) {
            rmax[j] = max(rmax[j + 1], dp[i][j]);   
        }
    };
    for(int i = 1; i <= m - k + 1; i++) {
        dp[1][i] = calc(pre, 1, i, i + k - 1);
    }
    init(1);
    for(int i = 2; i <= n; i++) {
        vector <int> dpl(m + 1), dpr(m + 1);
        solve(i, dp[i - 1], dpl, pre[i], 0);
        solve(i, dp[i - 1], dpr, suf[i], 1);
        for(int j = 1; j <= m - k + 1; j++) {
            dp[i][j] = max(lmax[max(0, j - k)], rmax[j + k]) + calc(pre, i, j, j + k - 1);
        }
        for(int j = 1; j <= m - k + 1; j++) {
            dp[i][j] = max(dp[i][j], max(dpl[j], dpr[m - j - k + 2]) + calc(pre, i, j, j + k - 1));
        }
        init(i);
    }
    int ans = lmax[m];
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    while(cin >> n >> m >> k) run();
    return 0;
}
