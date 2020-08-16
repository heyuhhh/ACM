#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, a, b) for (register int i = a; i <= b; i++)
 
int n;
int st1[100010][100], st2[100010][100];
 
int search1(int l, int r) {
    int k = log((double)(r - l + 1) / log(2.0));
    return max(st1[l][k], st1[r - (1 << k) + 1][k]);
}
int search2(int l, int r) {
    int k = log((double)(r - l + 1) / log(2.0));
    return min(st2[l][k], st2[r - (1 << k) + 1][k]);
}
 
inline void solve(int T)
{
    cin >> n;
    if(n == 0) {
        cout << "0" << endl;
        return ;
    }
    int x, y;
    rep(i, 1, n) { cin >> x >> y; st1[i][0] = x + 1; st2[i][0] = y + 1;}
    for(int j = 1; (1 << j) <= n; j++)
        for(int i = 1; i + (1 << j) - 1 <= n; i++)
            st1[i][j] = max(st1[i][j - 1], st1[i + (1 << (j - 1))][j - 1]), st2[i][j] = min(st2[i][j - 1], st2[i + (1 << (j - 1))][j - 1]);
    int l = 1, r = n, mid, flag;
    while (l < r) {
        flag = 0;
        mid = (l + r) / 2;
        for(int i = 1; i + mid - 1 <= n; i++) if(search2(i, i + mid - 1) - search1(i, i + mid - 1) >= mid) {
            flag = 1;
            break;
        }
        if(flag) l = mid + 1;
        else r = mid;
    }
    cout << l << endl;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    int T = 1;
    // cin >> T;
    rep(i, 1, T) solve(i);
 
}