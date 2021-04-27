// Author : heyuhhh
// Created Time : 2020/11/11 10:33:54
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

struct node {
    ll i, v;
};

map<ll, ll> mp[51];

void run() {
    int n;
    ll x;
    cin >> n >> x;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    queue<node> que;
    que.push({0, x});
    mp[0][x] = 1;
    ll ans = 0;
    while (!que.empty()) {
        node cur = que.front(); que.pop();
        int i = cur.i;
        ll v = cur.v;
        if (mp[i].find(v) == mp[i].end()) {
            continue;
        }
        ll res = mp[i][v];
        mp[i].erase(v);
        if (i + 1 == n) {
            ans += res;
            continue;
        }
        // a[i + 1] | (v + k * a[i])
        ll nd = a[i + 1];
        ll t1 = v / nd * nd, t2 = (v + nd - 1) / nd * nd;
        
        if ((v - t1) % a[i] == 0) {
            mp[i + 1][t1] += res;
            que.push({i + 1, t1});
        }
        
        if (t1 != t2) {
            if ((t2 - v) % a[i] == 0) {
                mp[i + 1][t2] += res;
                que.push({i + 1, t2});
            }
        }
    }
    cout << ans << '\n';
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