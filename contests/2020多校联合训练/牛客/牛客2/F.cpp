#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5005, M = 5000, T = 1000;
int a, b, n;
int mp[N][N], tmp[N][2];
int q1[N][N], l1[N], r1[N], q2[N][N], l2[N], r2[N];
int Q1[N], Q2[N];
int G[N][N];

int Gcd[N][N], Lcm[N][N];

int main() {
    ios::sync_with_stdio(false); cin.tie(0) ;
    cin >> a >> b >> n;
    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; j++) {
            if (!Gcd[i][j]) {
                for (int k = 1; k * i <= a && k * j <= b; k++)
                    Gcd[k * i][k * j] = k, Lcm[k * i][k * j] = i * j * k;
            }
        }
    }
    
    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; j++) {
            mp[i][j] = Lcm[i][j];
        }
    }
    for(int i = 1; i <= b; i++) l1[i] = l2[i] = 1;
    ll ans = 0;
    for(register int i = 1; i <= a; i++) {
        for(register int j = 1; j <= b; j++) {
            while(l1[j] <= r1[j] && mp[q1[j][r1[j]]][j] <= mp[i][j]) r1[j]--;
            q1[j][++r1[j]] = i ;
            while(l1[j] <= r1[j] && i + 1 - q1[j][l1[j]] > n) l1[j]++;
        }
        for(register int j = 1; j <= b; j++) tmp[j][0] = mp[q1[j][l1[j]]][j];
        int cc1, cc2;
        int L1 = 1, R1 = 0, L2 = 1, R2 = 0;
        for(register int j = 1; j <= b; j++) {
            while(L1 <= R1 && tmp[Q1[R1]][0] <= tmp[j][0]) R1--;
            Q1[++R1] = j ;
            while(L1 <= R1 && j + 1 - Q1[L1] > n) L1++;
            if(i >= n && j >= n) {
                ans += tmp[Q1[L1]][0];
            }
        }
    }
    cout << ans;
    return 0;
}