// Author : heyuhhh
// Created Time : 2020/09/06 09:45:23
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
    int n;
    cin >> n;
    int x = n / 4;
    if (n % 4) ++x;
    for (int i = 0; i < n - x; i++)
        cout << 9;
    for (int i = 0; i < x; i++)
        cout << 8;
    cout << endl;
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