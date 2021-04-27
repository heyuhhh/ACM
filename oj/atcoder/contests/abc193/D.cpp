// Author : heyuhhh
// Created Time : 2021/02/27 20:10:54
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
int qpow(ll a, ll b) {
    ll res = 1;
    while(b) {
        if (b & 1) res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}
void run() {
    ll k;
    cin >> k;
    string s, t;
    cin >> s >> t;
    vector<ll> cnt1(10), cnt2(10);
    for (int i = 0; i < 4; i++) {
        ++cnt1[s[i] - '0'];
    }
    for (int i = 0; i < 4; i++) {
        ++cnt2[t[i] - '0'];
    }
    ll d = 0;
    for (int i = 1; i < 10; i++) {
        d += i * qpow(10, cnt1[i]) - i * qpow(10, cnt2[i]);
    }
    auto calc1 = [&] (int i) {
        return -i * qpow(10, cnt1[i]) + i * qpow(10, cnt1[i] + 1);
    };
    auto calc2 = [&] (int i) {
        return i * qpow(10, cnt2[i]) - i * qpow(10, cnt2[i] + 1);
    };
    double ans = 0;
    for (int i = 1; i < 10; i++) {
        for (int j = 1; j < 10; j++) {
            if (i == j) {
                if (cnt1[i] + cnt2[i] + 2 <= k) {
                    if (d + calc1(i) + calc2(i) > 0) {
                        ans += 1.0 * (k - cnt1[i] - cnt2[i]) * (k - cnt1[i] - cnt2[i] - 1) 
                                / ((9 * k - 8) * (9 * k - 8 - 1));
                    }
                }
            } else {
                if (cnt1[i] + cnt2[i] + 1 <= k && cnt1[j] + cnt2[j] + 1 <= k) {
                    if (d + calc1(i) + calc2(j) > 0) {
                        ans += 1.0 * (k - cnt1[i] - cnt2[i]) * (k - cnt1[j] - cnt2[j]) 
                                / ((9 * k - 8) * (9 * k - 8 - 1));
                    }
                }
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