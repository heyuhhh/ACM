/*
 * Author:  heyuhhh
 * Created Time:  2020/6/4 13:43:21
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
#include <functional>
#include <numeric>
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
const int N = 1e4 + 5;

string query(int i, int j) {
    cout << "?" << ' ' << i << ' ' << j << endl;
    string s; cin >> s;
    return s;
}

bool chk(int i, int j) {
    return query(i, j) == "<";
}

int n;
vector <int> P[N];
vector <int> Less, More;

bool solve(int i, int x) {
    Less.clear(), More.clear();
    for (auto it : P[x]) {
        if (chk(i, it)) More.push_back(it);
        else Less.push_back(it);
    }
    return sz(Less) && sz(More);
}

int ans0[N], ans1[N];

void run() {
    cin >> n;
    int m0 = n / 2, m1 = n - n / 2;
    for (int i = 1; i <= m1; i++) {
        P[1].push_back(i);
    }
    int tot = 1;
    for (int i = 1; i <= m0; i++) {
        int l = 1, r = tot + 1, mid;
        while (l < r) {
            mid = (l + r) >> 1;
            if (chk(i, P[mid][0])) r = mid;
            else l = mid + 1;
        }
        int t = 0;
        for (int j = l; j >= max(1, l - 1); j--) {
            if (solve(i, j)) {
                for (int k = ++tot; k > j + 1; k--) {
                    P[k] = P[k - 1];
                }
                t = j;
                P[j] = Less;
                P[j + 1] = More;
                break;
            }
        }
        if (t == 0) {
        	ans0[i] = m0;
        	continue;
		}
        for (int j = 1; j <= t; j++) {
            ans0[i] += sz(P[j]);
        }
    }
    for (int i = 1; i <= m1; i++) {
        ans1[P[i][0]] = 2 * i - 1;
    }
    cout << "!";
    for (int i = 1; i <= m0; i++) {
        ans0[i] *= 2;
        cout << ' ' << ans0[i];
    }
    for (int i = 1; i <= m1; i++) {
        cout << ' ' << ans1[i];
    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
