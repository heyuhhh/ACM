#include <bits/stdc++.h>
using namespace std;
 
// #define zerol
 
using LL = long long;
#define FOR(i, x, y) for (decay<decltype(y)>::type i = (x), _##i = (y); i < _##i; ++i)
#define FORD(i, x, y) for (decay<decltype(x)>::type i = (x), _##i = (y); i > _##i; --i)
#ifdef zerol
#define dbg(x...) do { cout  << #x << " -> "; err(x); } while (0)
void err() { cout << endl; }
template<template<typename...> class T, typename t, typename... A>
void err(T<t> a, A... x) { for (auto v: a) cout << v << ' '; err(x...); }
template<typename T, typename... A>
void err(T a, A... x) { cout << a << ' '; err(x...); }
#else
#define dbg(...)
#endif
 
 
LL a, b, x, y;
 
LL solve1(LL x) {
    if (x <= 0) return 0;
    LL ans = min(a, b) * x;
    return ans;
}
 
LL case1(LL x, LL y) {
    LL ans = solve1(x-1);
    dbg("case1", x, y, ans);
    return ans;
}
LL case2(LL x, LL y) { 
    LL ans = solve1(y);
    return ans;
}
LL case3(LL x, LL y) {  
    LL ans = a + solve1(1-x);
    dbg(ans);
    ans = min(ans, solve1(-x));
    return ans;
}
LL case4(LL x, LL y) { return solve1(-1-y);}
 
LL c1(LL x, LL y) {
    if (y == 0) return case1(x, y);
    else if (x == 0) return case2(x, y);
    LL ans = 1e18;
    if (y <= x) {
        ans = y * a + case1(x-y, 0);
         dbg(ans, x, y);
        ans = min(ans, b + (y-1) * a + case1(x-y+1, 0));
         dbg(ans, x, y);
    } else {
        ans = b + (x-1) * a + case3(x-y, 0);
        dbg(ans, x, y);
        ans = min(ans, (x - 1) * a + case3(x-y-1, 0));
        dbg(ans, x, y);
    }
     dbg(ans, x, y);
    ans = min(ans, (y) * b + case1(x, 0));
    dbg(ans, x, y);
    ans = min(ans, (x-1) * b + case3(-y, 0));
 
    return ans;
}
 
LL c2(LL x, LL y) {
    if (y == 0) return case3(x, y);
    else if (x == 0) return case2(x, y);
    LL ans = c1(y, 1-x) + a;
    dbg(ans);
    ans = min(ans, c1(y+1, -x));
    return ans;
}
 
LL c4(LL x, LL y) {
    LL ans = c1(-y, x-1);
    ans = min(ans, a * 3 + c1(1-y, x));
    return ans;
}
 
LL c3(LL x, LL y) {
    LL ans = a + c2(y, -1-x);
    // dbg(ans);
    ans = min(ans, c1(-x+1, -y-1));
    return ans;
}
 
int main(int argc, char const *argv[])
{
    // freopen("out.txt", "w", stdout);
    int t;
    scanf("%d", &t);
    for (int kk=0; kk<t; ++kk)
    {
        scanf("%lld%lld%lld%lld", &a, &b, &x, &y);
        LL ans = 0;
        if (x > 0 && y == 0) ans = case1(x, y);
        else if (x < 0 && y == 0) ans = case3(x, y);
        else if (x == 0 && y > 0) {  ans = case2(x, y); }
        else if (x == 0 && y < 0) ans = case4(x, y);
        else if (x > 0 && y > 0) ans = c1(x, y);
        else if (x < 0 && y > 0) ans = c2(x, y);
        else if (x < 0 && y < 0) ans = c3(x, y);
        else ans = c4(x, y);
        printf("%lld\n", ans);
    }
    return 0;
}