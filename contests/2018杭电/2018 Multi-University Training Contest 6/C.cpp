/*
 * Author:  heyuhhh
 * Created Time:  2020/5/21 11:20:52
 */
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <iomanip>
#include <assert.h>
#define MP make_pair
#define fi first
#define se second
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
#define INF 0x3f3f3f3f
#define Local
#ifdef Local
  #define dbg(args...) do { cout << #args << " -> "; err(args); } while (0)
  void err() { std::cout << std::endl; }
  template<typename T, typename...Args>
  void err(T a, Args...args) { std::cout << a << ' '; err(args...); }
  template <template<typename...> class T, typename t, typename... A> 
  void err(const T <t> &arg, const A&... args) {
  for (auto &v : arg) std::cout << v << ' '; err(args...); }
#else
  #define dbg(...)
#endif
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
//head
const int N = 1e6 + 5;

namespace IO{ 
    #define BUF_SIZE 100000 
    #define OUT_SIZE 100000 
    bool IOerror=0; 
    inline char nc(){ 
        static char buf[BUF_SIZE],*p1=buf+BUF_SIZE,*pend=buf+BUF_SIZE; 
        if (p1==pend){ 
            p1=buf; pend=buf+fread(buf,1,BUF_SIZE,stdin); 
            if (pend==p1){IOerror=1;return -1;} 
        } 
        return *p1++; 
    } 
    inline bool blank(char ch){return ch==' '||ch=='\n'||ch=='\r'||ch=='\t';} 
    inline void read(int &x){ 
        bool sign=0; char ch=nc(); x=0; 
        for (;blank(ch);ch=nc()); 
        if (IOerror)return; 
        if (ch=='-')sign=1,ch=nc(); 
        for (;ch>='0'&&ch<='9';ch=nc())x=x*10+ch-'0'; 
        if (sign)x=-x; 
    } 
    struct Ostream_fwrite{ 
        char *buf,*p1,*pend; 
        Ostream_fwrite(){buf=new char[BUF_SIZE];p1=buf;pend=buf+BUF_SIZE;} 
        void out(char ch){ 
            if (p1==pend){ 
                fwrite(buf,1,BUF_SIZE,stdout);p1=buf; 
            } 
            *p1++=ch; 
        } 
        void println(ll x){ 
            static char s[25],*s1;s1=s; 
            if (!x)*s1++='0';if (x<0)out('-'),x=-x; 
            while(x)*s1++=x%10+'0',x/=10; 
            while(s1--!=s)out(*s1); out('\n'); 
        } 
        void flush(){if (p1!=buf){fwrite(buf,1,p1-buf,stdout);p1=buf;}} 
        ~Ostream_fwrite(){flush();} 
    }Ostream; 
    inline void println(ll x){Ostream.println(x);} 
    inline void println(){Ostream.out('\n');} 
    inline void flush(){Ostream.flush();}
};

int n, L;
int sum[N];
pii a[N];

struct BIT {
    ll c[N];
    void init() {
        memset(c, 0, sizeof(ll) * (2 * n + 4));
    }
    int lowbit(int x) {
        return x & -x;
    }
    void add(int x, int v) {
        x += n + 1;
        for (; x < 2 * n + 4; x += lowbit(x)) {
            c[x] += v;
        }
    } 
    ll query(int x) {
        x += n + 1;
        ll res = 0;
        for (; x; x -= lowbit(x)) {
            res += c[x];
        }
        return res;
    }
}bit;

void run() {
    IO::read(n), IO::read(L);
    for (int i = 1; i <= 2 * n; i++) {
        IO::read(a[i].fi);
        a[i].se = (i <= n ? 1 : -1);
    }
    sort(a + 1, a + 2 * n + 1);
    ll tot = 0;
    for (int i = 1; i <= 2 * n; i++) {
        sum[i] = sum[i - 1] + a[i].se;
    }
    bit.init();
    for (int i = 1; i <= 2 * n; i++) {
        if (a[i].se == 1) {
            bit.add(sum[i], 2 * a[i].fi), tot -= a[i].fi;
        } else {
            bit.add(sum[i] + 1, -2 * a[i].fi), tot += a[i].fi;
        }
    }
    ll ans = tot + bit.query(0);
    for (int i = 1; i < 2 * n; i++) {
        if (a[i].se == 1) {
            bit.add(sum[i], 2 * L), tot -= L;
        } else {
            bit.add(sum[i] + 1, -2 * L), tot += L;
        }
        ans = min(ans, tot + bit.query(sum[i]));
    }
    printf("%lld\n", ans);
}

int main() {
    int T; scanf("%d", &T); while(T--)
    run();
    return 0;
}
