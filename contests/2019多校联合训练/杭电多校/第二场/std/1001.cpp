#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define rep(i, a, b) for(int i = (a); i < (b); ++i)
#define per(i, a, b) for(int i = (b) - 1; i >= (a); --i)
#define endl "\n"
#define pw(x) (1ll << (x))
#define all(a) a.begin(), a.end()
#define sz(a) (int)a.size()
#define dd(x) cout << #x << " = " << x << " "
#define de(x) cout << #x << " = " << x << endl
typedef long long ll;
typedef double db;
typedef pair<ll, ll> pii;
typedef vector<int> vi;
const int P = 998244353;
int add(int a, int b) { if((a += b) >= P) a -= P;return a < 0 ? a + P : a;}
int mul(int a, int b) { return 1ll * a * b % P;}
int kpow(int a, int b) { int r=1; for(; b; b>>=1,a=mul(a,a)) {if(b&1)r=mul(r,a);} return r;}
//----

const int N = 2e5 + 7;
ll a, b, c, d, x, y, w[2], v[2], num, ans1, ans2, tt, sum, jc[N], inv[N], n;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

pair<pii, int> p1, p2;
pii inf = mp(-pw(30), -pw(30)), t;

pii check(ll a, ll b) {
    ll i = a * 2 + b;
    ll j = a - 2 * b;
    if (i % 5 || j % 5) return inf;
    return mp(i / 5, - j / 5);
}


pair<pii, int> solve(ll a, ll b) {
    rep(i, 0, 4) {
        x = a + dx[i];
        y = b + dy[i];
        t = check(x, y);
        if (t != inf) {
            if (i == 2) return mp(t, 3);
            if (i == 1) return mp(mp(t.fi - 1, t.se), 2);
            if (i == 0) return mp(mp(t.fi - 1, t.se - 1), 1);
            if (i == 3) return mp(mp(t.fi, t.se - 1), 0);
        }
    }
}

void print(pair<pii, int> p) {
    dd(p.fi.fi), dd(p.fi.se), de(p.se);
}

int get(int x, int y) {
    int t = abs(x - y);
    return min(t, 4 - t);
}

int C(int n, int m) {
    if (m < 0 || m > n) return 0;
    return mul(jc[n], mul(inv[m], inv[n - m]));
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int m = 200000;
	jc[0] = 1; rep(i, 1, m+1) jc[i] = mul(jc[i-1], i);
    inv[m] = kpow(jc[m], P - 2);
    per(i, 0, m) inv[i] = mul(inv[i+1], i+1);
    cin >> n;
    rep(cas, 0, n) {
        cin >> a >> b >> c >> d;
        p1 = solve(a, b); p2 = solve(c, d); ans1 = pw(60);
        // print(p1); print(p2);
        if (p1.fi == p2.fi) ans1 = get(p1.se, p2.se), ans2 = ans1 == 2 ? 2 : 1;
        else {
            x = p2.fi.fi - p1.fi.fi;
            y = p2.fi.se - p1.fi.se;
            w[0] = abs(x); w[1] = abs(y);
            rep(o1, 0, 2) rep(o2, 0, 2) {
                if (w[o1] < 1 || w[o2] < 1) continue;
                if (o1 == o2 && w[o1] < 2 && w[0] + w[1] > 1) continue;
                num = (w[0] + w[1]) * 2 - 1;
                if (w[0] + w[1] > 1) {
                    v[0] = w[0]; v[1] = w[1];
                    v[o1]--; v[o2]--;
                    if (o1 == o2) {
                        tt = abs(v[o1] + 1 - v[o1 ^ 1]);
                        num += tt; sum = kpow(2, tt);
                        if (v[o1 ^ 1] <= v[o1] + 1) sum = mul(sum, C(v[o1] + 1, v[o1 ^ 1]));
                        else sum = mul(sum, C(v[o1 ^ 1] - 1, v[o1]));
                    } else {
                        tt = abs(v[o1] - v[o2]);
                        num += tt; sum = kpow(2, tt);
                        if (v[o1] <= v[o2]) sum = mul(sum, C(v[o2], v[o1]));
                        else sum = mul(sum, C(v[o1], v[o2]));
                    }
                } else sum = 1;
                int t1 = get(p1.se, o1 == 0 ? (x > 0 ? 1 : 3) : (y > 0 ? 0 : 2));
                int t2 = get(p2.se, o2 == 0 ? (x > 0 ? 3 : 1) : (y > 0 ? 2 : 0));
                if (t1 == 2) sum = mul(sum, 2);
                if (t2 == 2) sum = mul(sum, 2);
                if (ans1 > t1 + t2 + num) {
                    ans1 = t1 + t2 + num;
                    ans2 = sum;
                } else if (ans1 == t1 + t2 + num) {
                    ans2 = add(ans2, sum);
                }
            }
        }
        cout << ans1 << " " << ans2 << endl;
    }
    return 0;
}
