#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define dd(a) cout << #a << " = " << a << " " 
#define de(a) cout << #a << " = " << a << endl
#define sz(a) (int)a.size()
#define all(a) a.begin(), a.end()
#define pw(a) (1ll << (a))
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef double db;

const int N = 3030, P = 998244353;

inline int add(int a, int b) {
    if((a += b) >= P) a -= P;
    return a;
}
inline int mul(int a, int b) {
    return 1ll * a * b % P;
}
inline int kpow(int a, int b) {
    int r = 1;
    while(b) {
        if(b & 1) r = r * 1ll * a % P;
        a = a * 1ll * a % P;
        b >>= 1;
    }
    return r;
}

int n, f[N], C[N][N], pw[N];

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    rep(i, 0, N) C[i][0] = C[i][i] = 1;
    rep(i, 1, N) rep(j, 1, i) C[i][j] = add(C[i - 1][j - 1], C[i - 1][j]);
    pw[0] = 1;
    rep(i, 1, N) pw[i] = pw[i - 1] * 2ll % P;
    rep(i, 2, N) {
        f[i] = mul(mul(i, i - 1), pw[i - 2]);
        rep(j, 0, i) f[i] = add(f[i], mul(C[i][j], f[j]));
        f[i] = mul(f[i], kpow(pw[i] - 1, P - 2));
    }
    while(cin >> n) {
        int ans = 0;
        rep(i, 1, n + 1) ans = add(ans, f[i]);
        ans = mul(ans, kpow(n, P - 2));
        cout << ans << endl;
    }
    return 0;
}
