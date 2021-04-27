// Author : heyuhhh
// Created Time : 2020/11/07 14:50:54
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
const int N = 1e6 + 5;

unsigned long long k1, k2;

unsigned long long xorShift128Plus() {
    unsigned long long k3 = k1, k4 = k2;
    k1 = k4;
    k3 ^= k3 << 23;
    k2 = k3 ^ k4 ^ (k3 >> 17) ^ (k4 >> 26);
    return k2 + k4;
}

int n;
long long a[1000001], b[1000001];

int D;
inline int find(ll x, int op = 0) {
    if (op) {
        return upper_bound(b + 1, b + D + 1, x) - b - 1;
    }
    return lower_bound(b + 1, b + D + 1, x) - b;
}

void gen() {
    // scanf("%d %llu %llu", &n, &k1, &k2);
    cin >> n >> k1 >> k2;
    for (int i = 1; i <= n; i++) {
        a[i] = xorShift128Plus() % 999999999999 + 1;
        b[i] = a[i];
    }
    sort(b + 1, b + n + 1);
    D = unique(b + 1, b + n + 1) - b - 1;
}

struct BIT {
    ll c[N];
    int lowbit (int x) {
        return x & -x;
    }
    void add(int x, ll v) {
        for (; x < N; x += lowbit(x)) {
            c[x] += v;
        }
    }
    ll query(int x) {
        ll res = 0;
        for (; x; x -= lowbit(x)) {
            res += c[x];
        }
        return res;
    }
} bit;

set<ll> S;
priority_queue<ll, vector<ll>, greater<ll>> que;

void run() {
    gen();
    for (int i = 1; i <= n; i++) {
        bit.add(find(a[i]), a[i]);
        S.insert(a[i]);
    }
    int q;
    cin >> q;
    while (q--) {
        string s;
        cin >> s;
        ll x;
        cin >> x;
        if (s[0] == 'F') {
            auto it = S.lower_bound(x);
            if (it == S.end()) {
                cout << 1000000000000 << '\n';
            } else {
                cout << *it << '\n';
            }
        } else if (s[0] == 'D') {
            auto it = S.lower_bound(x);
            if (it != S.end()) {
                que.push(*it);
                bit.add(find(*it), -*it);
                S.erase(it);
            }
        } else if (s[0] == 'C') {
            ll res = bit.query(find(x, 1));
            cout << res << '\n';
        } else {
            while (!que.empty() && que.top() <= x) {
                ll v = que.top(); que.pop();
                // cout << v << endl;
                S.insert(v);
                bit.add(find(v), v);
            }
        }
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