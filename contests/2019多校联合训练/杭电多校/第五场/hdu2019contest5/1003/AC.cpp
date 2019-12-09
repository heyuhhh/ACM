#include<stdio.h>
#include<math.h>
#include<vector>
#include<algorithm>
#include<string.h>
#define pb push_back
using namespace std;
struct Point{
    double x,y;
    Point(double _x=0,double _y=0){x=_x;y=_y;}
    Point operator-(const Point& b)const{return Point(x-b.x,y-b.y);}
    double operator*(const Point& b)const{return x*b.y-y*b.x;}
    void scan(){scanf("%lf%lf",&x,&y);}
}p[6],line[2][2];
const double eps=1e-9;
bool check(double v[]){
    Point X(v[0],v[1]),Y(v[2],v[3]);
    if((p[3]-p[1])*(X-p[1])<-eps)return 0;
    if((p[2]-p[3])*(X-p[3])<-eps)return 0;
    if((p[0]-p[2])*(X-p[2])<-eps)return 0;
    if((p[1]-p[0])*(X-p[0])<-eps)return 0;

    if((p[5]-p[3])*(Y-p[3])<-eps)return 0;
    if((p[4]-p[5])*(Y-p[5])<-eps)return 0;
    if((p[2]-p[4])*(Y-p[4])<-eps)return 0;
    if((p[3]-p[2])*(Y-p[2])<-eps)return 0;
    return 1;
}
void print(double res[]){
    for(int i=0;i<4;i++){
        if(i)printf(" ");
        printf("%.12lf",res[i]+eps);
    }
    puts("");
}
void fresh(double x[],double y[]){
    for(int i=0;i<4;i++){
        if(fabs(x[i]-y[i])>eps){
            if(x[i]<y[i])return;
            for(i=0;i<4;i++)x[i]=y[i];
            return;
        }
    }
}
int gauss(int n,double r1[][4],double r2[]){
    int now=0,i,j,k;
    for(i=0;i<4;i++){
        for(j=now;j<n&&fabs(r1[j][i])<eps;j++);
        if(j==n)continue;
        if(j!=now){
            for(k=0;k<4;k++)swap(r1[now][k],r1[j][k]);
            swap(r2[now],r2[j]);
        }
        for(j=3;j>i;j--)r1[now][j]/=r1[now][i];
        r2[now]/=r1[now][i];
        r1[now][i]=1;
        for(j=0;j<n;j++){
            if(j==now)continue;
            if(fabs(r1[j][i])>eps){
                for(k=3;k>i;k--)r1[j][k]-=r1[now][k]*r1[j][i];
                r2[j]-=r2[now]*r1[j][i];
                r1[j][i]=0;
            }
        }
        now++;
    }
    return now;
}
int main(){
    int T,i,j,k;
    double a[4][4],v[4],aa[6][4],vv[6];
    scanf("%d",&T);
    while(T--){
        for(i=0;i<6;i++)p[i].scan();
        for(i=0;i<2;i++)
            for(j=0;j<2;j++)line[i][j].scan();
        memset(a,0,sizeof(a));
        a[0][0]=line[0][1].y-line[0][0].y;
        a[0][1]=line[0][0].x-line[0][1].x;
        v[0]=a[0][0]*line[0][0].x+a[0][1]*line[0][0].y;

        a[1][2]=line[1][1].y-line[1][0].y;
        a[1][3]=line[1][0].x-line[1][1].x;
        v[1]=a[1][2]*line[1][0].x+a[1][3]*line[1][0].y;

        a[2][0]=p[0].y-p[1].y;
        a[2][1]=p[1].x-p[0].x;
        a[2][2]=p[4].y-p[5].y;
        a[2][3]=p[5].x-p[4].x;
        v[2]=p[5].x*p[4].y-p[4].x*p[5].y-p[0].x*p[1].y+p[1].x*p[0].y;

        a[3][0]=p[3].y-p[2].y-p[0].y+p[1].y;
        a[3][1]=p[2].x-p[3].x-p[1].x+p[0].x;
        a[3][2]=p[2].y-p[3].y;
        a[3][3]=p[3].x-p[2].x;
        v[3]=p[0].x*p[1].y-p[1].x*p[0].y;
        
        int now=gauss(4,a,v);
        if(now==4){
            if(check(v))print(v);
            else{ puts("-1");}
        }
        else{
            for(i=now;i<4;i++)
                if(fabs(v[i])>eps)break;
            if(i<4)puts("-1");
            else{
                double an[4];
                for(i=0;i<4;i++)an[i]=1e9;
                vector<Point>pp[2];
                pp[0].pb(p[0]);
                pp[0].pb(p[1]);
                pp[0].pb(p[3]);
                pp[0].pb(p[2]);
                pp[0].pb(p[0]);

                pp[1].pb(p[2]);
                pp[1].pb(p[3]);
                pp[1].pb(p[5]);
                pp[1].pb(p[4]);
                pp[1].pb(p[2]);
                for(i=0;i<4;i++){
                    memset(vv,0,sizeof(vv));
                    memset(aa,0,sizeof(aa));
                    for(j=0;j<4;j++){
                        vv[j]=v[j];
                        for(k=0;k<4;k++)aa[k][j]=a[k][j];
                    }
                    aa[4][0]=pp[0][i+1].y-pp[0][i].y;
                    aa[4][1]=pp[0][i].x-pp[0][i+1].x;
                    vv[4]=aa[4][0]*pp[0][i].x+aa[4][1]*pp[0][i].y;
                    now=gauss(5,aa,vv);
                    if(now==4){
                        for(j=now;j<5;j++)
                            if(fabs(vv[j])>eps)break;
                        if(j<5)continue;
                        if(check(vv))fresh(an,vv);
                    }
                }
                for(i=0;i<4;i++){
                    memset(vv,0,sizeof(vv));
                    memset(aa,0,sizeof(aa));
                    for(j=0;j<4;j++){
                        vv[j]=v[j];
                        for(k=0;k<4;k++)aa[k][j]=a[k][j];
                    }
                    aa[4][2]=pp[1][i+1].y-pp[1][i].y;
                    aa[4][3]=pp[1][i].x-pp[1][i+1].x;
                    vv[4]=aa[4][2]*pp[1][i].x+aa[4][3]*pp[1][i].y;
                    now=gauss(5,aa,vv);
                    if(now==4){
                        for(j=now;j<5;j++)
                            if(fabs(vv[j])>eps)break;
                        if(j<5)continue;
                        if(check(vv))fresh(an,vv);
                    }
                }
                for(i=0;i<4;i++)
                    for(j=0;j<4;j++){
                        memset(vv,0,sizeof(vv));
                        memset(aa,0,sizeof(aa));
                        for(k=0;k<4;k++){
                            vv[k]=v[k];
                            for(int kk=0;kk<4;kk++)aa[kk][k]=a[kk][k];
                        }
                        aa[4][0]=pp[0][i+1].y-pp[0][i].y;
                        aa[4][1]=pp[0][i].x-pp[0][i+1].x;
                        vv[4]=aa[4][0]*pp[0][i].x+aa[4][1]*pp[0][i].y;
                        aa[5][2]=pp[1][i+1].y-pp[1][i].y;
                        aa[5][3]=pp[1][i].x-pp[1][i+1].x;
                        vv[5]=aa[5][2]*pp[1][i].x+aa[5][3]*pp[1][i].y;
                        now=gauss(6,aa,vv);
                        if(now==4){
                            for(k=now;k<6;k++)
                                if(fabs(vv[k])>eps)break;
                            if(k<6)continue;
                            if(check(vv))fresh(an,vv);
                        }
                    }
                if(an[0]>1e5)puts("-1");
                else print(an);
            }
        }
    }
    return 0;
}
