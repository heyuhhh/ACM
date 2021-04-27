// Author : heyuhhh
// Created Time : 2021/03/28 20:02:13
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
    int cnt = 0;
    ll t = n;
    while (t % 2 == 0) {
        ++cnt;
        t /= 2;
    }
    if (cnt == 0) {
        cout << "Odd" << '\n';
    } else if (cnt == 1) {
        cout << "Same" << '\n';
    } else {
        cout << "Even" << '\n';
    }   
}
int main() {
#ifdef Local
    freopen("input.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    int T; cin >> T; while(T--)
    run();
    return 0;
}