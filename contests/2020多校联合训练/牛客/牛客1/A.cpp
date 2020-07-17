// Author : heyuhhh
// Created Time : 2020/07/15 14:46:06
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
 
struct SA{                                       //sa:1...n  Rank:0...n-1
    int sa[N], c[N], Rank[N], t1[N], t2[N];
    int n;                                          //length
    void da(int* s, int m){
        s[++n] = 0;    //!!  s[n]=0
        int* x = t1, *y = t2;
        for(int i = 0; i < m; ++i) c[i] = 0;
        for(int i = 0; i < n; ++i) c[x[i] = s[i]]++;
        for(int i = 1; i < m; ++i) c[i] += c[i - 1] ;
        for(int i = n - 1; i >= 0; i--) sa[--c[x[i]]] = i;
        for(int k = 1; k <= n; k <<= 1) {
            int p = 0 ;
            for(int i = n - k; i < n; ++i) y[p++] = i ;
            for(int i = 0; i < n; ++i) if(sa[i] >= k) y[p++] =sa[i] - k;
            for(int i = 0; i < m; ++i) c[i] = 0;
            for(int i = 0; i < n; ++i) c[x[y[i]]]++;
            for(int i = 1; i < m; ++i) c[i] += c[i - 1];
            for(int i = n - 1; i >= 0; i--) sa[--c[x[y[i]]]] = y[i] ;
            swap(x , y); p = 1; x[sa[0]] = 0;
            for(int i = 1; i < n; ++i)
                x[sa[i]] = y[sa[i - 1]] == y[sa[i]] && y[sa[i-1] + k] == y[sa[i] + k] ? p - 1 : p++;
            if(p >= n) break ;
            m = p;
        }
        n--;
        for(int i = 0; i <= n; ++i) Rank[sa[i]] = i;
    }
}suf;
 
int n;
char s[N];
int R[N], a[N];
 
void run() {
    suf.n = n;
    for (int i = 0, j; i < n; i = j + 1) {
        j = i;
        while (j + 1 < n && s[j + 1] == s[j]) ++j;
        for (int k = i; k <= j; k++) {
            R[k] = j + 1;
        }
    }
    int pre[2] = {-1, -1};
    for (int i = 0; i < n; ++i) {
        if (pre[s[i] - 'a'] == -1) {
            a[i] = 0;
        } else {
            a[i] = i - pre[s[i] - 'a'];
        }
        pre[s[i] - 'a'] = i;
    }
 
    suf.da(a, n + 2);

    vector<int> ord(n);
    iota(all(ord), 0);
    auto get = [&] (int i) {
        return i >= n ? -1 : suf.Rank[i];
    };
     
    sort(all(ord), [&] (int i, int j) {
        int len1 = R[i] - i, len2 = R[j] - j;
        if (len1 != len2) {
            return len1 < len2;
        }
        if (R[i] >= n || R[j] >= n) {
            return R[i] >= n;
        }
        return get(R[i] + 1) < get(R[j] + 1);
    });
 
    for (int i = 0; i < n; ++i) {
        printf("%d", ord[i] + 1);
        if (i < n - 1) printf(" ");
        else printf("\n");
    }
}
int main() {
    while (scanf("%d%s", &n, s) == 2) run();
    return 0;
}