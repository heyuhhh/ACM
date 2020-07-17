// Author : heyuhhh
// Created Time : 2020/07/14 14:38:56
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

void FWT_xor(int *a, int n, int op) {
    for(int i = 1; i < n; i <<= 1)
        for(int p = i << 1, j = 0; j < n; j += p)
            for(int k = 0; k < i; k++) {
                int X = a[j + k], Y = a[i + j + k];
                a[j + k] = (X + Y); a[i + j + k] = (X - Y);
                if(op == -1) a[j + k] = a[j + k] / 2, a[i + j + k] = a[i + j + k] / 2;
            }
}

int n;
int a[N], b[N];
int ans[N];

void run() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        a[x] = b[x] = 1;
        ans[1] = max(ans[1], x);
    }

    int L = (1 << 18);  
    FWT_xor(b, L, 1);  
    for (int k = 2; k <= 19; k++) {
        FWT_xor(a, L, 1);
        for (int i = 0; i < L; i++) {
            a[i] *= b[i];
        }
        FWT_xor(a, L, -1);
        for (int i = 0; i < L; i++) {
            if (a[i] > 0) {
                ans[k] = i;
                a[i] = 1;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (i > 19) ans[i] = ans[i - 2];
        cout << ans[i] << " \n"[i == n];
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);
    run();
    return 0;
}