#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN=100005;
const int Mod=1000000007;
const int INF=0x3f3f3f3f;

struct Result
{
    int v;
    ll c;
    Result():v(0),c(1) {}
    Result(int _v,ll _c):v(_v),c(_c) {}
    Result operator + (const Result &t)const
    {
        if(v>t.v)return (*this);
        if(v<t.v)return t;
        return Result(v,c+t.c);
    }
    Result& operator += (const Result &t)
    {
        return (*this)=(*this)+t;
    }
    Result operator * (const Result &t)
    {
        if(this==&t)return Result(2*v,c*(c-1)/2);
        return Result(v+t.v,c*t.c);
    }
    Result operator + (const int &t)const
    {
        return Result(v+t,c);
    }
} EMPTY(-INF,0);

typedef vector<vector<pair<int,int>>> Graph;

Graph G;
int deg[MAXN<<2];
Result sur[MAXN][3];

void solve_1(int n,Result &res)
{
    for(int i=1; i<=n; i++)
        res+=Result(deg[i],1);
}
void solve_2(int n,Result &res)
{
    for(int u=1; u<=n; u++)
        for(auto &t:G[u])
        {
            int v=t.first;
            if(u<v)continue;
            res+=Result(deg[u]+deg[v]-2,1);
        }
}
void solve_3(int n,Result &res)
{
    for(int i=1; i<=n; i++)if(deg[i]>=2)
        res+=sur[i][0]*sur[i][sur[i][0].c==1]+(2*deg[i]-6);
}
void solve_4(int n,Result &res)
{
    for(int u=1; u<=n; u++)
        for(auto &t:G[u])
        {
            int v=t.first;
            if(u<v)continue;
            Result ru[2]= {EMPTY,EMPTY};
            Result rv[2]= {EMPTY,EMPTY};
            for(int i=0,k=0; i<3 && k<2; i++)
                if(sur[u][i].c>(sur[u][i].v==deg[v]))
                {
                    ru[k]=sur[u][i];
                    ru[k++].c-=(sur[u][i].v==deg[v]);
                }
            for(int i=0,k=0; i<3 && k<2; i++)
                if(sur[v][i].c>(sur[v][i].v==deg[u]))
                {
                    rv[k]=sur[v][i];
                    rv[k++].c-=(sur[v][i].v==deg[u]);
                }
            if(deg[u]>=3)
                res+=ru[0]*ru[ru[0].c==1]+(4*deg[u]+2*deg[v]-14);
            if(deg[v]>=3)
                res+=rv[0]*rv[rv[0].c==1]+(4*deg[v]+2*deg[u]-14);
            if(deg[u]>=2 && deg[v]>=2)
                res+=ru[0]*rv[0]+(3*deg[v]+3*deg[u]-14);
        }
}
#define solve_star(n,k,res) \
case k: \
    solve_##k(n,res); \
    break

Graph line_graph(Graph G)
{
    int n=G.size()-1,m=0;
    for(int i=1; i<=n; i++)
        m+=G[i].size();
    m/=2;
    Graph L(m+1);
    for(int u=1,k=0; u<=n; u++)
        for(size_t i=0; i<G[u].size(); i++)
            for(size_t j=0; j<i; j++)
            {
                int p=G[u][i].second;
                int q=G[u][j].second;
                L[p].push_back({q,++k});
                L[q].push_back({p,k});
            }
    return L;
}
int vis[MAXN<<2];
void solve_tri(int k,Result &res)
{
    for(int i=0; i+2<k; i++)
        G=line_graph(G);
    int n=G.size()-1;
    for(int i=1; i<=n; i++)
        deg[i]=G[i].size();
    if(k>1)for(int i=1; i<=n; i++)
        if(deg[i]>=3)res+=Result(3,deg[i]*(deg[i]-1)*(deg[i]-2)/6);
    for(int u=1; u<=n; u++)
    {
        for(auto &t:G[u])
        {
            int v=t.first;
            if(u<v)vis[v]=1;
        }
        for(auto &t:G[u])
        {
            int v=t.first;
            if(u<v)for(auto &s:G[v])
            {
                int w=s.first;
                if(v<w && vis[w])
                    res+=Result(3,1);
            }
        }
        for(auto &t:G[u])
        {
            int v=t.first;
            if(u<v)vis[v]=0;
        }
    }
}

void solve()
{
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    G.resize(n+1);
    for(int i=1; i<=m; i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back({v,i});
        G[v].push_back({u,i});
    }
    for(int i=1; i<=n; i++)
    {
        deg[i]=G[i].size();
        for(int j=0; j<3; j++)
            sur[i][j]=EMPTY;
    }
    for(int u=1; u<=n; u++)
        for(auto &t:G[u])
        {
            int v=t.first;
            Result tmp(deg[v],1);
            for(int i=0; i<3; i++)
            {
                if(tmp.v==sur[u][i].v)
                {
                    sur[u][i]+=tmp;
                    break;
                }
                else if(tmp.v>sur[u][i].v)
                    swap(tmp,sur[u][i]);
            }
        }
    Result res;
    switch(k)
    {
        solve_star(n,1,res);
        solve_star(n,2,res);
        solve_star(n,3,res);
        solve_star(n,4,res);
    }
    if(res.v<=3)solve_tri(k,res);
    if(res.v==0)printf("0 1\n");
    else if(res.v==1)printf("%d %lld\n",res.v,res.c/2%Mod);
    else printf("%d %lld\n",res.v,res.c%Mod);
    G.clear();
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)solve();
    return 0;
}
