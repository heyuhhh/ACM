// Author : heyuhhh
// Created Time : 2021/03/01 14:24:25
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
const int N = 2e5 + 5;
struct SA{                                       //sa:1...n  Rank:0...n-1
    int t1[N], t2[N], sa[N], c[N], height[N], Rank[N];
    int f[N][20], lg[N];
    int n;                                          //length
    void da(char *s, int m){
        s[++n] = 0;
        int* x = t1, *y = t2;
        for(int i = 0; i < m; i++) c[i] = 0;
        for(int i = 0; i < n; i++) c[x[i] = s[i]]++;
        for(int i = 1; i < m; i++) c[i] += c[i - 1] ;
        for(int i = n - 1; i >= 0; i--) sa[--c[x[i]]] = i;
        for(int k = 1; k <= n; k <<= 1) {
            int p = 0 ;
            for(int i = n - k; i < n; i++) y[p++] = i ;
            for(int i = 0; i < n; i++) if(sa[i] >= k) y[p++] =sa[i] - k;
            for(int i = 0; i < m; i++) c[i] = 0;
            for(int i = 0; i < n; i++) c[x[y[i]]]++;
            for(int i = 1; i < m; i++) c[i] += c[i - 1];
            for(int i = n - 1; i >= 0; i--) sa[--c[x[y[i]]]] = y[i] ;
            swap(x , y); p = 1; x[sa[0]] = 0;
            for(int i = 1; i < n; i++)
                x[sa[i]] = y[sa[i - 1]] == y[sa[i]] && y[sa[i-1] + k] == y[sa[i] + k] ? p - 1 : p++;
            if(p >= n) break ;
            m = p;
        }
        n--;
        int k = 0;
        for(int i = 0; i <= n; i++) Rank[sa[i]] = i;
        for(int i = 0; i < n; i++) {
            if(k) k--;
            int j = sa[Rank[i] - 1];
            while(s[i + k] == s[j + k]) k++;
            height[Rank[i]] = k;
        }
    }
}A, B;
char s[N], t[N];
void run() {
    cin >> s >> t;
    int n = strlen(s), m = strlen(t);
    A.n = n;
    A.da(s, 255);
    B.n = m;
    B.da(t, 255);
    
    int p1 = A.sa[n];
    int p2 = B.sa[m];

    string res = "";
    res += s[p1];
    for (int i = p1 + 1; i < n; i++) {
        if (s[i] >= t[p2]) {
            res += s[i];
        } else {
            break;
        }
    }
    for (int i = p2; i < m; i++) {
        res += t[i];
    }
    cout << res << '\n';
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