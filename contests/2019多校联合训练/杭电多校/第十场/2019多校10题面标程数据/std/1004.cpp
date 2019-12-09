#include<bits/stdc++.h>
//#include"Data.hpp"
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int maxn = 1e5+10;
char s[maxn];int n;
ll w[maxn];
struct Suffix_Automaton{
    //basic
    int nxt[maxn*2][26],fa[maxn*2],l[maxn*2];
    int last,cnt;
    //extension
    int cntA[maxn*2],A[maxn*2];
    int num[maxn*2];
    int rk[maxn*2];
    int st[maxn*2][20];
    int pos[maxn*2];//每个前缀所在的节点
    struct Linear_Basis{
        ll basis[60];
        ull total;
        int num;
        void clear(){
            memset(basis,0,sizeof basis);
            total = 0;
            num = 0;
        }
        bool ins(ll x){
            ll bk = x;
            for (int i=58;i>=0;i--){
                if (x & (1ll<< i)){
                    if (!basis[i]){basis[i] = x;total += bk;num ++;return true;}
                    x ^= basis[i];
                }
            }
            return false;
        }
    }basis[maxn*2];
    Suffix_Automaton(){ clear(); }
    void clear(){
        last =cnt=1;
        fa[1]=l[1]=0;
        memset(nxt[1],0,sizeof nxt[1]);
    }
    void init(char *s){
        while (*s){
            add(*s-'a');s++;
        }
    }
    void add(int c){
        int p = last;
        int np = ++cnt;
        memset(nxt[cnt],0,sizeof nxt[cnt]);
        l[np] = l[p]+1;last = np;
        while (p&&!nxt[p][c])nxt[p][c] = np,p = fa[p];
        if (!p)fa[np]=1;
        else{
            int q = nxt[p][c];
            if (l[q]==l[p]+1)fa[np] =q;
            else{
                int nq = ++ cnt;
                l[nq] = l[p]+1;
                memcpy(nxt[nq],nxt[q],sizeof (nxt[q]));
                fa[nq] =fa[q];fa[np] = fa[q] =nq;
                while (nxt[p][c]==q)nxt[p][c] =nq,p = fa[p];
            }
        }
    }
    void build(){
        for (int i=1;i<=cnt;i++)cntA[i] = num[i] = 0,basis[i].clear();
        for (int i=1;i<=cnt;i++)cntA[l[i]]++;
        for (int i=1;i<=cnt;i++)cntA[i]+=cntA[i-1];
        for (int i=cnt;i>=1;i--)A[cntA[l[i]]--] =i;
        int temp=1;
        for (int i=1;i<=n;i++){
            num[temp = nxt[temp][s[i]-'a'] ]=1;
            pos[i] = temp;
        }
        for (int i=cnt;i>=1;i--){
            int x = A[i];
            num[fa[x]]+=num[x];
            rk[i] = i;
        }
        for (int i=1;i<=cnt;i++){
            int x = A[i];
            st[x][0] = fa[x];
            for (int j=1;j < 20;j ++){
                st[x][j] = st[st[x][j-1]][j-1];
            }
        }
        sort(rk + 1,rk + cnt + 1,[&](int x,int y){
            return w[num[x]] > w[num[y]];
        });
        for (int i=1;i<=cnt;i++){
            int x = rk[i];
            ll val = w[num[x]];
            while (x != 1 && basis[x].ins(val))x = fa[x];
        }
        int tot_basis = 0;
        for (int i=1;i<=cnt;i++){
            tot_basis += basis[i].num;
        }
      //  cerr<<"total basis = "<<tot_basis<<endl;
      //  cerr<<"complexity reachs " << tot_basis / n <<" / "<< 58<<endl;
    }
    ull query(int L,int R){
        int temp = pos[R];
        int len = R - L + 1;
        for (int i=19;i>=0;i--){
            int nxt = st[temp][i];
            if (nxt && l[nxt] >= len)temp = nxt;
        }
        assert(basis[temp].total >0);
        return basis[temp].total;
    }
    void debug(){
        for (int i=cnt;i>=1;i--){
            printf("num[%d]=%d l[%d]=%d fa[%d]=%d\n",i,num[i],i,l[i],i,fa[i]);
        }
    }
}sam;

int main(){
/*
    ll tot = 0;
    ll tmp = (1ll << 58) - 1;
    unsigned long long tot2 = 0;
    for (int i=0;i<58;i++){
        ll val = tmp ^ (1ll << i);
        assert(val <= (1ll<<58));
        tot += val;
        tot2 += val;
    }
    cout<<tot<<" "<<tot2<<endl;
    data_generate("input");
    freopen("input","r",stdin);
    freopen("output","w",stdout);
   */
    int T;
    scanf("%d",&T);
    clock_t start = clock();
    while (T--){
        scanf("%d",&n);
        scanf("%s",s+1);
        for (int i=1;i<=n;i++){
            scanf("%lld",w+i);
        }
        sam.clear();
        sam.init(s + 1);
        sam.build();
       // sam.debug();
        int m;
        scanf("%d",&m);
        while (m--){
            int l,r;
            scanf("%d%d",&l,&r);
            printf("%llu\n",sam.query(l,r));
        }
    }
    clock_t end = clock();
 //   cerr<<"duration : "<<1.0 * (end - start) / CLOCKS_PER_SEC<<endl;
    return 0;
}
