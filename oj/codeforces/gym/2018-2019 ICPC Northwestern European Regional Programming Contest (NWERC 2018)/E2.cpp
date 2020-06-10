/*
 * Author:  heyuhhh
 * Created Time:  2020/6/9 17:20:03
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
const int N = 1e6 + 5;

void sayNo() {
    cout << "not equal" << '\n';
    exit(0);
}

char s[N], t[N];
int n, m;
int a[N], b[N];
int na, nb;
int suma[N], sumb[N];

void gao(char* s, int n, int* a, int na, int* sum) {
    int now = 0;
    for (int i = 0, j; i < n; i = j + 1) {
        j = i;
        if (s[i] >= '0' && s[i] <= '9') {
            while (j < n && s[j] >= '0' && s[j] <= '9') {
                ++j;
            }
            ++now;
        }
        if (s[i] == 's' && s[i + 1] == 'o') {
            j += 7;
            int cnt = 1;
            for (; j < n; j++) {
                if (s[j] == ')') --cnt;
                if (s[j] == '(') ++cnt;
                if (cnt == 0) break;
            }
            int d = sum[j] - sum[i];
            sort(a + now, a + now + d);
            now += d;
        }
        if (s[i] == 's' && s[i + 1] == 'h') {
            j += 8;
            int cnt = 1;
            for (; j < n; j++) {
                if (s[j] == ')') --cnt;
                if (s[j] == '(') ++cnt;
                if (cnt == 0) break;
            }
            int d = sum[j - 1] - sum[i];
            for (int k = now + 1; k < now + d; k++) {
                if (a[k] != a[k - 1]) {
                    sayNo();
                }
            }
            now += d;
        }
    }
}

void run() {
    cin >> s >> t;
    n = strlen(s), m = strlen(t);
    int cnt = 0;
    for (int i = 0, j; i < n; i = j + 1) {
        j = i;
        if (s[i] >= '0' && s[i] <= '9') {
            int x = 0;
            while (j < n && s[j] >= '0' && s[j] <= '9') {
                x = x * 10 + (s[j] - '0');
                ++j;
            }
            suma[j - 1] = 1;
            a[na++] = x;
        }
    }
    for (int i = 0, j; i < m; i = j + 1) {
        j = i;
        if (t[i] >= '0' && t[i] <= '9') {
            int x = 0;
            while (j < m && t[j] >= '0' && t[j] <= '9') {
                x = x * 10 + (t[j] - '0');
                ++j;
            }
            sumb[j - 1] = 1;
            b[nb++] = x;
        }
    }
    if (na != nb) {
        sayNo();   
    }
    for (int i = 1; i < n; i++) {
        suma[i] += suma[i - 1];
    }
    for (int i = 1; i < m; i++) {
        sumb[i] += sumb[i - 1];
    }
    gao(s, n, a, na, suma);
    gao(t, m, b, nb, sumb);
    for (int i = 0; i < na; i++) {
        if (a[i] != b[i]) {
            sayNo();
        }
    }
    cout << "equal";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
