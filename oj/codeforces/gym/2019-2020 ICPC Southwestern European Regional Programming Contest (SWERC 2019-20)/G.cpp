/*
 * Author:  heyuhhh
 * Created Time:  2020/5/22 10:52:27
 */
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
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
  void err() { std::cout << std::endl; }
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
const int N = 1e5 + 5;

void run() {
    int s, l, n;
    cin >> s >> l >> n;
    vector <string> str(s);
    for (int i = 0; i < s; i++) {
        cin >> str[i];
    }
    sort(all(str));
    map <string, int> mp;
    for (int i = 0; i < s; i++) {
        mp[str[i]] = i;
    }
    map <int, string> mp2;
    for (int i = 0; i < s; i++) {
        mp2[i] = str[i];
    }
    vector <vector <int>> w(s, vector <int> (s));
    for (int i = 0; i < l; i++) {
        string ss, tt; cin >> ss >> tt;
        w[mp[ss]][mp[tt]] = w[mp[tt]][mp[ss]] = 1;
    }
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        string ss; cin >> ss;
        a[i] = mp[ss]; 
    }
    vector <int> cnt(s);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < s; j++) {
            while (cnt[j] < n && (a[cnt[j]] == -1 || w[a[cnt[j]]][j])) {
                ++cnt[j];
            }
            if (cnt[j] < n && a[cnt[j]] == j) {
                a[cnt[j]] = -1;
                cout << mp2[j] << ' ';
                break;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
