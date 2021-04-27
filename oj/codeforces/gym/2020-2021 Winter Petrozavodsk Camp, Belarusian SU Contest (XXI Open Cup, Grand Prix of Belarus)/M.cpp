// Author : heyuhhh
// Created Time : 2021/02/19 15:12:42
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
void run() {
    ll n;
    cin >> n;
    vector<ll> a;
    a.emplace_back(1);
    int A = 1, B = 2;
    int last = 1;
    for (int i = 2; i <= 1000000; i++) {
        while (__gcd(last, B) != 1) ++B;
        if (1ll * A * B > n) break;
        a.emplace_back(1ll * A * B);
        last = A;
        A = B;
        B = A + 1;
    }
    while(a.back() > n) a.pop_back();
    cout << sz(a) << '\n';
    for (int i = 0; i < sz(a); i++) {
        if (i) cout << ' ';
        cout << a[i];
    }
    cout << '\n';
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