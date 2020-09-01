// Author : heyuhhh
// Created Time : 2020/07/16 14:25:03
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
    int n; cin >> n;
    if (n % 2 == 0) {
        cout << n / 2 << ' ' << n / 2 << '\n';
    } else {
        auto calc = [&] (int t) {
            if (t == n || t == 0) return (ll)1e18;
            return 1ll * t * (n - t) / __gcd(n, t);
        };
        int x;
        ll Max = 1e18;
        for (int i = 1; 1ll * i * i <= n; i++) {    
            if (n % i == 0) {
                ll t = min(calc(i), calc(n / i));
                if (t < Max) {
                    Max = t;
                    x = (calc(i) < calc(n / i) ? i : n / i);
                }
            }
        }
        cout << x << ' ' << n - x << '\n';
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    int T; cin >> T; while(T--)
    run();
    return 0;
}