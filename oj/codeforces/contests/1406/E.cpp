// Author : heyuhhh
// Created Time : 2020/09/13 10:20:40
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

int primes[N], tot;
bool vis[N];
void init(int n) {
    for (int i = 2; i <= n; i++) {
        if (!vis[i]) {
            primes[++tot] = i;
        }
        for (int j = 1; j <= tot && primes[j] * i <= n; j++) {
            vis[primes[j] * i] = true;
            if (i % primes[j] == 0) {
                break;
            }
        }
    }
}

void run() {
    int n;
    cin >> n;
    init(n);
    int t = 1;
    while (t * t <= n) ++t;

    auto query = [&] (ll x, int op = 1) {
        if (x > n) return 0;
        if (op == 1)
            cout << "B " << x << endl;
        else 
        	cout << "A " << x << endl;
        cout << endl;
        int y; cin >> y;
        return y;
    };

    int p = 1;
    int ans = 1;
    for (; p <= tot && primes[p] < t; p++) {
    	query(primes[p]);
        int x = query(primes[p]);
        if (x) {
            int now = primes[p] * primes[p];
            for (int i = 2; now / primes[p] <= n; now *= primes[p]) {
                if (!query(now)) {
                    ans *= now / primes[p];
                    break;
                }
            }
        }
    }
    if (ans != 1) {
        for (; p <= tot; p++) {
            int x = query((ll)ans * primes[p]);
            if (x > 0) {
                ans *= primes[p];
                break;
            }
        }
    } else {
        int B = 95;
        int last = query(1, 2);
        for (int cnt = 0; p <= tot; ++p) {
            query(primes[p]);
            if (++cnt == B || p == tot) {
                int now = query(1, 2);
                if (last - now != cnt) {
                    for (int i = p - cnt + 1; i <= p; i++) {
                        int x = query(primes[i]);
                        if (x) {
                            cout << "C " << ans * primes[i] << endl;
                            return;
                        }
                    }
                }
                last = now;
                cnt = 0;
            }
        }
    }

    cout << "C " << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}