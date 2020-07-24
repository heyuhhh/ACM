// Author : heyuhhh
// Created Time : 2020/07/18 15:52:18
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
//head
const int N = 2e6 + 5;
const ll MAX = 4e18;
   
int v[N], prime[N];
int num;
void Euler() {
    v[1] = 1;
    for(int i = 2; i < N; i++) {
        if(v[i] == 0) {
            v[i] = i;
            prime[++num] = i;
        }
        for(int j = 1; j <= num && prime[j] * i < N; j++) {
            v[prime[j] * i] = prime[j] ;
        }
    }
}
   
void exgcd(ll a, ll b, ll &x, ll &y) {
    if(b == 0) {
        x = 1, y = 0;
        return ;
    }
    exgcd(b,a%b,x,y);
    ll z = x ;
    x = y;
    y = z - y * (a / b);
}
//ax + by = c
ll calc(ll a, ll b, ll c) {
    ll x, y;
    ll g = __gcd(a, b);
    assert(g == 1);
    // g = 1
    a /= g, b /= g, c /= g;
    exgcd(a, b, x, y);
    assert(x <= MAX / c);
    // x *= c;
    x = (x % b + b) % b;
    if (x == 0) x += b;
    x *= c;
    return x;
}
   
void run() {
    int a, b;
    cin >> a >> b;
    int g = __gcd(a, b);
    if (g == 1) {
        // c / d - e / f = a / b
        // cf - ed = a
        if (v[b] == b) {
            cout << -1 << ' ' << -1 << ' ' << -1 << ' ' << -1 << '\n';
        } else {
            int f = 1;
            int x = b;
            while (x % v[b] == 0) {
                x /= v[b];
                f *= v[b];
            }
  
            if (x == 1) {
                cout << -1 << ' ' << -1 << ' ' << -1 << ' ' << -1 << '\n';
                return;
            }
              
            int d = b / f;
            ll c = calc(f, d, a);
            ll e = (c * f - a) / d;

            if (e < 0) {
                e = -e;
            }
  
            assert(e > 0 && c > 0 && c <= 4000000000000 && e <= 4000000000000);
            cout << c << ' ' << d << ' ' << e << ' ' << f << '\n';         
        }
    } else {
        a /= g, b /= g;
        int t = a / b;
        int c = t + 1, d = 1;
        ll e = b - a % b, f = b;
        cout << c << ' ' << d << ' ' << e << ' ' << f << '\n';
    }
}
int main() {
#ifdef Local
    freopen("input.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    Euler();
    int T; cin >> T; while(T--)
    run();
    return 0;
}