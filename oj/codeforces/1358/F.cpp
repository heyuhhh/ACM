/*
 * Author:  heyuhhh
 * Created Time:  2020/5/27 15:17:12
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
const int N = 1e5 + 5;
 
bool operator == (vector <ll>& A, vector <ll>& B) {
    for (int i = 0; i < sz(A); i++) {
        if (A[i] != B[i]) return false;
    }
    return true;   
}
 
vector <ll> rev(vector <ll>& A) {
    vector <ll> B = A;
    reverse(all(B));
    return B; 
}
 
void D(vector <ll>& A) {
    int n = sz(A);
    for (int i = n - 1; i > 0; i--) {
        A[i] -= A[i - 1];
    }
}
 
void out(ll cntp, ll cntr, vector <char>& ans) {
    reverse(all(ans));
    if (cntp > 2e5) {
        cout << "BIG" << '\n';
        cout << cntp << '\n';
    } else {
        cout << "SMALL" << '\n';
        cout << sz(ans) << '\n';
        for (auto it : ans) cout << it;
        cout << '\n';
    }
}    
        
void run() {
    int n; cin >> n;
    vector <ll> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    if (n == 1) {
        if (a[0] == b[0]) {
            cout << "SMALL" << '\n';
            cout << 0 << '\n' << '\n';
        } else {
            cout << "IMPOSSIBLE" << '\n';
        }
        return;
    }
    ll cntr = 0, cntp = 0;
    vector <char> ans;
    bool BIG = false, f = false;
    if (n > 2) {
        while (!(a == b || a == rev(b))) {
            for (int i = 1; i < n; i++) {
                if (b[i] <= b[i - 1]) {
                    b = rev(b), ++cntr;
                    ans.push_back('R'); 
                    break;
                }
            }
            D(b), ++cntp;
            if (cntp > 2e5) BIG = true;
            if (!BIG) ans.push_back('P');
            for (int i = 0; i < n; i++) {
                if (b[i] < 0) {
                    cout << "IMPOSSIBLE" << '\n';
                    return;
                }
            }
        }
        if (a == rev(b)) f = true;
    } else {
        while (1) {
            if (b[0] == a[1]) {
                swap(a[0], a[1]);
                f = true;
            }
            if (b[0] == a[0]) {
                if (b[1] < a[1]) {
                    cout << "IMPOSSIBLE" << '\n';
                    return;
                }
                ll r = (b[1] - a[1]) % b[0];
                if (r == 0) {
                    ll now = ((b[1] - a[1]) / b[0]);
                    cntp += now;
                    if (cntp > 2e5) BIG = true;
                    if (!BIG) for (int i = 0; i < now; i++) {
                        ans.push_back('P');
                    }
                } else {
                    cout << "IMPOSSIBLE" << '\n';   
                    return;
                }
                break;
            }
            if (b[0] < a[0]) {
                cout << "IMPOSSIBLE" << '\n';   
                return; 
            }
            ll& x = b[0], &y = b[1];
            ll now = (y - y % x) / x;
            y %= x;
            cntp += now;
            if (cntp > 2e5) BIG = true;
            if (!BIG) for (int i = 0; i < now; i++) {
                ans.push_back('P');
            }
            swap(x, y), ++cntr;
            ans.push_back('R');
        }
    }
    if (f) {
        ++cntr;
        ans.push_back('R');
    }
    out(cntp, cntr, ans);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}
