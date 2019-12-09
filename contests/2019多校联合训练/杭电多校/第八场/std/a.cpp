#include<bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef pair<int,int> pi;
pi cov[6][4]={
{(pi){1,0},(pi){2,0},(pi){3,0},(pi){4,0}},
{(pi){5,0},(pi){2,1},(pi){0,2},(pi){4,3}},
{(pi){5,3},(pi){3,1},(pi){0,3},(pi){1,3}},
{(pi){5,2},(pi){4,1},(pi){0,0},(pi){2,3}},
{(pi){5,1},(pi){1,1},(pi){0,1},(pi){3,3}},
{(pi){3,2},(pi){2,2},(pi){1,2},(pi){4,2}}
};
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
char s[105][105];
bool v[6][105][105],vis[105][105],flag;
int n,m,_,k,cnt,px,py;
void init(int k){
    for (int p=0;p<6;p++)
        for (int i=1;i<=k;i++)
            for (int j=1;j<=k;j++)
                v[p][i][j]=0;
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
            vis[i][j]=0;
}
void _turn(int &x,int &y,int o){
    if (o==1){
        swap(x,y);
        x=k+1-x;
    } else if (o==2){
        x=k+1-x; y=k+1-y;
    } else if (o==3){
        swap(x,y);
        y=k+1-y;
    }
}
bool valid(int x,int y){
    if (x<0||x>=n||y<0||y>=m) return 0;
    if (vis[x][y]||s[x][y]!='#') return 0;
    return 1;
}
void dfs(int x,int y,int p,int t,int i,int j){
    //cout<<x<<' '<<y<<' '<<p<<' '<<t<<' '<<i<<' '<<j<<endl;
    if (v[p][i][j]) flag=0;
    v[p][i][j]=1; vis[x][y]=1;
    for (int o=0;o<4;o++){
        if (!valid(x+dx[o],y+dy[o])) continue;
        int ii=i+dx[(o+t)%4],jj=j+dy[(o+t)%4];
        if (ii>k) {
            int rt=cov[p][0].S;
            ii-=k; _turn(ii,jj,rt);
            dfs(x+dx[o],y+dy[o],cov[p][0].F,(t+rt)%4,ii,jj);
        } else if (jj>k){
            int rt=(cov[p][1].S+3)%4;
            jj-=k; _turn(ii,jj,rt);
            dfs(x+dx[o],y+dy[o],cov[p][1].F,(t+rt)%4,ii,jj);
        } else if (ii<1){
            int rt=(cov[p][2].S+2)%4;
            ii+=k; _turn(ii,jj,rt);
            dfs(x+dx[o],y+dy[o],cov[p][2].F,(t+rt)%4,ii,jj);
        } else if (jj<1){
            int rt=(cov[p][3].S+1)%4;
            jj+=k; _turn(ii,jj,rt);
            dfs(x+dx[o],y+dy[o],cov[p][3].F,(t+rt)%4,ii,jj);
        } else {
            dfs(x+dx[o],y+dy[o],p,t,ii,jj);
        }
    }
}
bool check(){
    for (int i=1;i<=k;i++)
    for (int j=1;j<=k;j++){
        init(k); flag=1;
        dfs(px,py,0,0,i,j);
        if (flag) return 1;
    }
    return 0;
}
char t[15][15];
int main(){
    //freopen("a.in","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> _;
    while (_--){
        scanf("%d%d",&n,&m); cnt=0;
        for (int i=0;i<n;i++) {
            scanf("%s",s[i]);
            //for (int j=0;j<m;j++) s[i][j]=t[i/2][j/2];
            for (int j=0;j<m;j++) {
                if (s[i][j]=='#') px=i,py=j,cnt++;
            }
        }
        k=(int)sqrt(cnt/6+0.5);
        if (k*k*6!=cnt){puts("no");continue;}
        if (check()) puts("yes"); else puts("no");
    }
    return 0;
}

