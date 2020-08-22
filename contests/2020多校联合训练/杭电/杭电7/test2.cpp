// Author : heyuhhh
// Created Time : 2020/08/11 16:21:26
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
// 0.235936
void run() {
    for (int i = 1; i <= 20; i++) {
        for (int j = 1; j <= i; j++) {
            cout << i << ' ' << j << ' ' << 1.0 * j / i << endl;
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