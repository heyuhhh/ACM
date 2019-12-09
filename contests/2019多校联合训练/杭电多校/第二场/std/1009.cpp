#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i=(a); i<(b); i++)
#define per(i, a, b) for(int i=(b)-1; i>=(a); i--)
#define sz(a) (int)a.size()
#define de(a) cout << #a << " = " << a << endl
#define dd(a) cout << #a << " = " << a << " "
#define all(a) a.begin(), a.end()
#define pw(x) (1ll<<(x))
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef double db;
#define mem(a,x) memset(a,x,sizeof(a))

const int N=3e5+5;
char s[N]; int pa[N<<1],n,ret[N];

void Manacher(char *s,int n,int *pa){
    pa[0] = 1;
    for(int i=1,j=0;i<(n<<1)-1;++i){
        int p = i >> 1 , q = i - p , r = ((j + 1)>>1) + pa[j] - 1;
        pa[i] = r < q ? 0 : min(r - q + 1 , pa[(j<<1) - i]);
        while(0 <= p - pa[i] && q + pa[i] < n && s[p - pa[i]] == s[q + pa[i]])
            pa[i]++;
        if(q + pa[i] - 1 > r) j = i;
    }
}

inline bool check(int L,int R) {
    int mid=L+R>>1;
    if ((L&1)==(R&1)) return pa[mid<<1]>=R-L+2>>1;
    return pa[mid<<1|1]>=R-L+1>>1;
}

inline void Put(string &s,vi &V) {
    V.clear();
    rep(i,0,sz(s)) V.pb(s[i]-'a');
}

inline bool Check(int L,int R) {
    int mid=L+R>>1;
    if (!check(L,mid) || !check(mid+((L&1)!=(R&1)),R)) return false;
    return true;
}

const int M=26;
struct PAM{
    int s[N],len[N],next[N][M],fail[N],cnt[N],dep[N],id[N],no[N],last,n,p,cur,now,f[N][20]; ll ans;
    inline int new_node(int _l) { mem(next[p],0); cnt[p]=dep[p]=0,len[p]=_l; return p++; }
    inline void Init() { new_node(p=0),new_node(s[0]=-1),fail[last=n=0]=1; }
    inline int get_fail(int x) { for (; s[n-len[x]-1]!=s[n]; x=fail[x]); return x; }
    inline void I(int c) { 
        c-='a',s[++n]=c,cur=get_fail(last);
        if (!next[cur][c]) {
            now=new_node(len[cur]+2);
            fail[now]=next[get_fail(fail[cur])][c];
            next[cur][c]=now;
            dep[now]=dep[fail[now]]+1; 
        }
        last=next[cur][c]; cnt[last]++; id[n]=last,no[last]=n; 
    }
    inline void Insert(char s[],int op=0,int _n=0) { 
        if (!_n) _n=strlen(s);  if (!op) rep(i,0,_n) I(s[i]); else per(i,0,_n) I(s[i]); 
    }
    inline void count() { per(i,0,p) cnt[fail[i]]+=cnt[i]; }
    inline int Find(int x,int L) {
        if (len[x]<=L) return x;
        per(i,0,20) if (len[f[x][i]]>L) x=f[x][i];
        return fail[x];
    }
    inline void init() {
        mem(f,0);
        rep(i,0,p) f[i][0]=fail[i];
        rep(i,0,p) rep(j,1,20) f[i][j]=f[f[i][j-1]][j-1];
    }
    inline void Q() {
        count();
        rep(i,2,p) no[i]--;
        rep(i,0,p) if (len[i]>0)
            ret[len[i]]+=Check(no[i]-len[i]+1,no[i])*cnt[i];
    }
} TT;

int main() {
    
    while (scanf("%s",s)!=EOF) {
        n=strlen(s); Manacher(s,n,pa);
        mem(ret,0);
        TT.Init(),TT.Insert(s),TT.Q();
        rep(i,1,n+1) printf("%d%c",ret[i]," \n"[i==n]);
    }
    
    return 0;
}
