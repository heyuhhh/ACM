// Author : heyuhhh
// Created Time : 2020/07/13 14:01:34
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
const int N = 1e6 + 5, MOD = 998244353;

int n, k;
bool vis[N];
int p[N];

vector<int> v;

void dfs(int u) {
    v.push_back(u);
    vis[u] = true;
    int son = p[u];
    if (!vis[son]) {
        dfs(son);
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
ll calc(ll a, ll b, ll c) {
    ll x, y;
    ll g = __gcd(a, b);
    if(c % g != 0) return -1;
    a /= g, b /= g, c /= g;
    exgcd(a, b, x, y);
    x *= c;
    x = (x % b + b) % b;
    return x;
}

void gao(vector<int>& v) {
    int len = sz(v);
    int r = k % len;
    int c = calc(r, len, 1);
    // c: steps need to go
    if (c == -1) {
        cout << -1 << '\n';
        exit(0);
    }
    vector<int> res(len);
    for (int i = 0; i < len; i++) {
        res[i] = v[(i + c) % len];
    }
    swap(res, v);
}

int in[N], out[N];

void run() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        assert(p[i] >= 1 && p[i] <= n);
        ++out[i], ++in[p[i]];
    }
    for (int i = 1; i <= n; i++) {
        if (in[i] != 1 || out[i] != 1) {
            cout << -1 << '\n';
            return;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            v.clear();
            dfs(i);
            vector<int> w = v;
            gao(v);
            for (int j = 0; j < sz(w); j++) {
                p[w[j]] = v[j];
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << p[i] << " \n"[i == n];
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}