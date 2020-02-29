/*
 * Author:  heyuhhh
 * Created Time:  2020/2/28 16:15:41
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
const int N = 100000 + 5;

int n;
int Max[N];

void run(){
    vector <vector<int>> a(n), pre(n), suf(n);
    int ok = 0;
    vector <int> Max;
    for(int i = 0; i < n; i++) {
        int k; cin >> k;
        a[i].resize(k);
        pre[i].resize(k);
        suf[i].resize(k);
        for(int j = 0; j < k; j++) {
            cin >> a[i][j];
        }
        for(int j = 0; j < k; j++) {
            if(j == 0) pre[i][j] = a[i][j];
            else pre[i][j] = min(pre[i][j - 1], a[i][j]);
        }
        for(int j = k - 1; j >= 0; j--) {
            if(j == k - 1) suf[i][j] = a[i][j];
            else suf[i][j] = max(suf[i][j + 1], a[i][j]);
        }
        bool f = false;
        for(int j = 0; j < sz(a[i]); j++) {
            if(pre[i][j] < suf[i][j]) f = true;   
        }
        if(f) ++ok;
        else Max.push_back(suf[i][0]);   
    }
    sort(all(Max));
    ll ans = 1ll * ok * n;
    for(int i = 0; i < n; i++) {
        bool f = false;
        for(int j = 0; j < sz(a[i]); j++) {
            if(pre[i][j] < suf[i][j]) f = true;   
        }          
        if(f == false) {
            ans += ok;
            int t = upper_bound(all(Max), pre[i][sz(a[i]) - 1]) - Max.begin();   
            ans += sz(Max) - t;
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    while(cin >> n) run();
    return 0;
}
