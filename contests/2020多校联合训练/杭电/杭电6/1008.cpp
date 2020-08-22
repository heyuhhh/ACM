// Author : heyuhhh
// Created Time : 2020/08/07 16:50:26
#include<bits/stdc++.h>
#define MP make_pair
#define fi first
#define se second
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
void err(int x) {cerr << x;}
void err(long long x) {cerr << x;}
void err(double x) {cerr << x;}
void err(char x) {cerr << '"' << x << '"';}
void err(const string &x) {cerr << '"' << x << '"';}
void _print() {cerr << "]\n";}
template<typename T, typename V>
  void err(const pair<T, V> &x) {cerr << '{'; err(x.first); cerr << ','; err(x.second); cerr << '}';}
template<typename T>
  void err(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), err(i); cerr << "}";}
template <typename T, typename... V>
  void _print(T t, V... v) {err(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifdef Local
#define dbg(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define dbg(x...)
#endif
//head
const int N = 1e5 + 5;

ll n, k;
ll sum1[N], sum2[N], prime[N];
ll w[N], ind1[N], ind2[N];
ll g1[N], g2[N];
bool chk[N];
int tot, cnt;
void pre(int n) { //  \sqrt
    chk[1] = 1;
    for(int i = 1; i <= n; i++) {
        if(!chk[i]) {
            prime[++tot] = i;
            sum1[tot] = sum1[tot - 1] + 1;
        }
        for(int j = 1; j <= tot && prime[j] * i <= n; j++) {
            chk[i * prime[j]] = 1;
            if(i % prime[j] == 0) break;
        }
    }
}

int f(int x, int y) {
    return x <= k;
}

void calc_g(ll n) {
    int z = sqrt(n + 0.5);
    for(ll i = 1, j; i <= n; i = j + 1) {
        j = n / (n / i);
        w[++cnt] = n / i;
        
        g1[cnt] = w[cnt] - 1;

        if(n / i <= z) ind1[n / i] = cnt;
        else ind2[n / (n / i)] = cnt;
    }
    for(int i = 1; i <= tot; i++) {
        for(int j = 1; j <= cnt && prime[i] * prime[i] <= w[j]; j++) {
            ll tmp = w[j] / prime[i], k;
            if(tmp <= z) k = ind1[tmp]; else k = ind2[n / tmp];
            g1[j] -= (g1[k] - sum1[i - 1]); 
        }
    }
}

ll num;

ll S(ll x, int y) { // 2~x >= P_y
    if(x <= 1 || prime[y] > x) return 0;
    int z = sqrt(n + 0.5);
    ll ans;
    if (k <= x) {
        ans = num - sum1[y - 1];
    } else {
        ll t = (x <= z ? ind1[x] : ind2[n / x]);
        ans = g1[t] - sum1[y - 1];
    }        
    ans = max(ans, 0ll);
    ll tmp = ans;
    for(int i = y; i <= tot && prime[i] * prime[i] <= x ; i++) {
        ll pe = prime[i];
        for(int e = 1; pe * prime[i] <= x; ++e, pe = pe * prime[i]) {
            ans += f(prime[i], e) * S(x / pe, i + 1) + f(prime[i], e + 1);
        }
    }
    return ans;
} 

void run() {
    tot = cnt = 0;
    memset(chk, 0, sizeof(chk));
    cin >> n >> k;
    int z = sqrt(k + 0.5);
    pre(z);
    calc_g(k);
    num = g1[ind2[1]];

    tot = cnt = 0;
    memset(chk, 0, sizeof(chk));
    z = sqrt(n + 0.5);
    pre(z);
    calc_g(n);
    cout << S(n, 1) + 1 << '\n';
}
int main() {
#ifdef Local
    freopen("input.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    int T; cin >> T; while(T--)
    run();
    return 0;
}