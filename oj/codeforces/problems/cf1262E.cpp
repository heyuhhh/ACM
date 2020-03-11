/*
 * Author:  heyuhhh
 * Created Time:  2020/3/3 15:02:46
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
#include <assert.h>
#define MP make_pair
#define fi first
#define se second
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define INF 0x3f3f3f3f
#define Local
#ifdef Local
  #define dbg(args...) do { cout << #args << " -> "; err(args); } while (0)
  void err() { std::cout << '\n'; }
  template<typename T, typename...Args>
  void err(T a, Args...args) { std::cout << a << ' '; err(args...); }
  template <template<typename...> class T, typename t, typename... A> 
  void err(const T <t> &arg, const A&... args) {
  for (auto &v : arg) std::cout << v << ' '; err(args...); }
#else
  #define dbg(...)
#endif
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
//head
const int N = 1e6 + 5;

int n, m;
char s[N];

bool chk(vector<vector<int>>& res, vector<vector<int>>& mp, vector<vector<ll>>& a, ll T) {
    T = 2 * T + 1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            res[i][j] = 0;
        }   
    }
    vector <vector <ll>> c(n, vector <ll> (m, 0));
    auto ask = [&] (int r1, int c1, int r2, int c2) {
        ll ans = a[r2][c2];
        if(r1) ans -= a[r1 - 1][c2];
        if(c1) ans -= a[r2][c1 - 1];
        if(r1 && c1) ans += a[r1 - 1][c1 - 1];
        return ans == T * T;
    };
    
    for(int i = 0; i + T - 1 < n; i++) {
        for(int j = 0; j + T - 1 < m; j++) {
            if(ask(i, j, i + T - 1, j + T - 1)) {
                ++c[i][j];
                if(i + T < n) --c[i + T][j];
                if(j + T < m) --c[i][j + T];
                if(i + T < n && j + T < m) ++c[i + T][j + T];
                res[i + T / 2][j + T / 2] = 1;
            }
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 1; j < m; j++) {
            c[i][j] += c[i][j - 1];
        }   
    }
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < m; j++) {
            c[i][j] += c[i - 1][j];
        }   
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(mp[i][j] > 0 && c[i][j] <= 0) return false;
        }   
    }
    return true;
}

void run() {
    cin >> n >> m;
    vector <vector<int>> a(n, vector<int> (m)), b(n, vector <int> (m)), c(n, vector <int> (m));
    vector <vector <ll>> sum(n, vector <ll> (m));
    for(int i = 0; i < n; i++) {
        cin >> s;
        for(int j = 0; j < m; j++) {
            a[i][j] = (s[j] == 'X' ? 1 : 0);
        }   
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            sum[i][j] = a[i][j];
            if(i) sum[i][j] += sum[i - 1][j];
            if(j) sum[i][j] += sum[i][j - 1];
            if(i && j) sum[i][j] -= sum[i - 1][j - 1];
        }   
    }
    int l = 0, r = n * m + 1, mid;
    while(l < r) {
        mid = (l + r) >> 1;
        if(chk(b, a, sum, mid)) {
            l = mid + 1;
            c = b;
        }
        else r = mid;
    }
    cout << l - 1 << '\n';
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(c[i][j]) cout << 'X';
            else cout << '.';
        }
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
