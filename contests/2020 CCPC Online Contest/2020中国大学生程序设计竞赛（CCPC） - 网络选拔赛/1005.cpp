// Author : heyuhhh
// Created Time : 2020/09/20 14:13:27
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
const int N = 4e4 + 5;

int v[N], prime[N];
int num;
void Euler() {
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

void run() {
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        int res = 0;
        if (x % 2 == 0) ++res;
        for (int j = 1; prime[j] * prime[j] <= x; j++) if (x % prime[j] == 0) {
            while (x % prime[j] == 0) {
                if (prime[j] & 1) ++res;
                x /= prime[j];
            }
        }
        if (x > 1 && (x & 1)) ++res;
        ans ^= res;
    }
    if (ans) {
        cout << "W" << '\n';
    } else {
        cout << "L" << '\n';
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