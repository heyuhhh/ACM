// Author : heyuhhh
// Created Time : 2021/02/21 20:06:45
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
const int N = 1e5 + 5;
int qpow(ll a, ll b, int MOD) {
    ll res = 1;
    while(b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}
void run() {
    int A, B, C;
    cin >> A >> B >> C;
    int k = A % 10;
    int t = k;
    vector<int> a;
    vector<int> vis(10, -1);
    a.emplace_back(k);
    vis[k] = sz(a);
    while (vis[k * t % 10] == -1) {
        k = k * t % 10;
        a.emplace_back(k);
        vis[k] = sz(a);
    }
    k = k * t % 10;
    int st = vis[k] - 1;
    int len = sz(a) - vis[k] + 1;
    int now;
    if (B <= 10 && C <= 3) {
        now = qpow(B, C, 1000000000);
        if (now <= st) {
            cout << a[now - 1] << '\n';
        } else {
            now -= st;
            now = (now - 1) % len + 1;
            cout << a[st + now - 1] << '\n';
        }    
    } else {
        now = qpow(B, C, sz(a));
        while (now <= 100) now += len;
        now -= st;
        now = (now - 1) % len + 1;
        cout << a[st + now - 1] << '\n';
    }
}
int main() {
#ifdef Local
    freopen("input.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}