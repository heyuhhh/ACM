#include<bits/stdc++.h>
  
using namespace std;
  
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define LC k<<1
#define RC k<<1|1
  
typedef long long LL;
const int N=510;
const LL mod[2] = {1000000009, 998244353};
  
const int M = 500 + 5;
const int INF = 2E8;
  
int w[M][M], kx[M], ky[M], py[M], vy[M], slk[M], pre[M];
  
int KM(int n) {
    for (int i=0;i<=n;i++)
        kx[i]=ky[i]=py[i]=0;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            kx[i] = max(kx[i], w[i][j]);
    for (int i=1;i<=n;i++)
    {
        fill(vy, vy + n + 1, 0);
        fill(slk, slk + n + 1, INF);
        fill(pre, pre + n + 1, 0);
        int k = 0, p = -1;
        for (py[k = 0] = i; py[k]; k = p) {
            int d = INF;
            vy[k] = 1;
            int x = py[k];
            for (int j=1;j<=n;j++)
                if (!vy[j]) {
                    int t = kx[x] + ky[j] - w[x][j];
                    if (t < slk[j]) { slk[j] = t; pre[j] = k; }
                    if (slk[j] < d) { d = slk[j]; p = j; }
                }
            for (int j=0;j<=n;j++)
                if (vy[j]) { kx[py[j]] -= d; ky[j] += d; }
                else slk[j] -= d;
        }
        for (; k; k = pre[k]) py[k] = py[pre[k]];
    }
    int ans = 0;
    for (int i=1;i<=n;i++) ans += kx[i] + ky[i];
    return ans;
}
int n;
vector<int> g1[N],g2[N];
int root1,root2;
int cost[N][N];
LL v1[N][2],v2[N][2];
vector<LL> tmp[2];
void dfs1(int x)
{
    v1[x][0]=929, v1[x][1] = 29;
    for (int i=0;i<g1[x].size();i++)
        dfs1(g1[x][i]);
    tmp[0].clear(), tmp[1].clear();
    for (int i=0;i<g1[x].size();i++) {
        for (int j = 0; j < 2; j++) {
            tmp[j].push_back(v1[g1[x][i]][j]);
        }
    }
        
    sort(tmp[0].begin(),tmp[0].end());
    sort(tmp[1].begin(),tmp[1].end());
    for (int j = 0; j < 2; j++) {
        static LL ppp[2] = {131LL, 929LL};
        for (int i=0;i<tmp[j].size();i++)
            v1[x][j]=(v1[x][j]*ppp[j]+tmp[j][i])%mod[j];
    }
    
}
void dfs2(int x)
{
    v2[x][0]=929, v2[x][1] = 29;
    for (int i=0;i<g2[x].size();i++)
        dfs2(g2[x][i]);
    tmp[0].clear(), tmp[1].clear();
    for (int i=0;i<g2[x].size();i++) {
        for (int j = 0; j < 2; j++) {
            tmp[j].push_back(v1[g2[x][i]][j]);
        }
    }
        
    sort(tmp[0].begin(),tmp[0].end());
    sort(tmp[1].begin(),tmp[1].end());
    for (int j = 0; j < 2; j++) {
        static LL ppp[2] = {131LL, 929LL};
        for (int i=0;i<tmp[j].size();i++)
            v2[x][j]=(v2[x][j]*ppp[j]+tmp[j][i])%mod[j];
    }
    
}
vector<int> idx1,idx2;
int cal(int x,int y)
{
    cout << x << ' ' << y << endl;
    if (cost[x][y]!=-1) return cost[x][y];
    for (int i=0;i<g1[x].size();i++)
        for (int j=0;j<g2[y].size();j++) {
            int xx = g1[x][i], yy = g2[y][j];
            bool flag=true;
            for(int k=0;k<2;k++) {
                if (v1[xx][k] != v2[yy][k]) flag=false;
            }
            if(flag){
                cost[g1[x][i]][g2[y][j]]=cal(g1[x][i],g2[y][j]);
            }
        }
            
    int res=(x!=y);
    vector<pair<LL, LL>> vv;
    for (int i=0;i<g1[x].size();i++) {
        vv.pb(mp(v1[g1[x][i]][0], v1[g1[x][y]][1]));
    }
        
    sort(vv.begin(), vv.end());
    vv.erase(unique(vv.begin(), vv.end()), vv.end());

    for (int i=0;i<vv.size();i++)
    {
        idx1.clear(),idx2.clear();
        for (int j=0;j<g1[x].size();j++)
            if (v1[g1[x][j]][0]==vv[i].fi && v1[g1[x][j]][1]==vv[i].se) idx1.pb(g1[x][j]);
        for (int j=0;j<g2[y].size();j++)
            if (v2[g2[x][j]][0]==vv[i].fi && v2[g2[x][j]][1]==vv[i].se) idx2.pb(g2[y][j]);
        for (int j=0;j<idx1.size();j++)
            for (int k=0;k<idx2.size();k++)
            {
                // assert(cost[idx1[j]][idx2[k]]!=-1);
                w[j+1][k+1]=1000-cost[idx1[j]][idx2[k]];
                // assert(w[j+1][k+1]>0);
            }
        // assert((int)idx1.size()==(int)idx2.size());
        res+=1000*idx1.size()-KM(idx1.size());
    }
    return cost[x][y]=res;
}
  
int main()
{
#ifdef Local
    freopen("input.in", "r", stdin);
#endif
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        if (x==0) root1=i;
        else g1[x].pb(i);
    }
    for (int i=1;i<=n;i++)
    {
        int x;
        scanf("%d",&x);
        if (x==0) root2=i;
        else g2[x].pb(i);
    }
    dfs1(root1);
    dfs2(root2);
    cout << 11<<endl;
    memset(cost,-1,sizeof(cost));
    printf("%d\n",cal(root1,root2));
    return 0;
}