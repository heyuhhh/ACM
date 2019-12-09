#include<stdio.h>
#define SIZE 1024
int n,ii;
struct Point{
    int x,y;
    Point(int _x=0,int _y=0){x=_x,y=_y;}
    void scan(){
        scanf("%d%d",&x,&y);
        x<<=1;
        y<<=1;
    }
    Point operator-=(Point X){
        Point &res=*this;
        res.x-=X.x;
        res.y-=X.y;
        return res;
    }
    Point operator-(Point X)const{
        Point res=*this;
        res-=X;
        return res;
    }
    Point operator+=(Point X){
        Point &res=*this;
        res.x+=X.x;
        res.y+=X.y;
        return res;
    }
    Point operator+(Point X)const{
        Point res=*this;
        res+=X;
        return res;
    }
    long long operator^(Point X)const{return x*X.x+y*X.y;}
    Point half(){
        Point res=*this;
        res.x>>=1;
        res.y>>=1;
        return res;
    }
    long long operator*(Point X){return x*X.y-y*X.x;}
}a[SIZE+SIZE];
int pn(int x){
    if(x>0)return 1;
    if(x<0)return -1;
    return 0;
}
bool Add(Point X[2],Point V[2],int num[2],int pos[2],int &now,Point p1,Point p2,int i){
    if(now==0){
        X[now]=(p1+p2).half();
        V[now++]=Point(p2.y-p1.y,p1.x-p2.x);
        num[0]=1;
        pos[0]=i;
    }
    else{
        if(((p1+p2).half()-X[0])*V[0]!=0||((p1-p2)^V[0])||(Point(p2.y-p1.y,p1.x-p2.x)^V[0])<0){
            if(now==1){
                X[now]=(p1+p2).half();
                V[now++]=Point(p2.y-p1.y,p1.x-p2.x);
                num[1]=1;
                pos[1]=i;
            }
            else{
                if(((p2+p1).half()-X[1])*V[1]||((p1-p2)^V[1])||(Point(p2.y-p1.y,p1.x-p2.x)^V[1])<0)return 0;
                num[1]++;
            }
        }
        else num[0]++;
    }
    return 1;
}
bool f1(Point p[]){
    Point X[2],V[2];
    int num[2]={},now=0,pos[2]={},i;
    for(i=1;i<n-i;i++)
        if(!Add(X,V,num,pos,now,p[i],p[n-i],i))return 0;
    if(now==1){
        int cnt=0;
        if((p[0]-X[0])*V[0])cnt++;
        if(i==n-i){
            if((p[i]-X[0])*V[0])cnt++;
        }
        return cnt<2;
    }
    else{
        int cnt=0;
        if(num[0]==1){
            cnt=0;
            if((p[0]-X[1])*V[1])cnt++;
            if(i==n-i){
                if((p[i]-X[1])*V[1])cnt++;
            }
            if(cnt==0){
                int next=(pos[0]==1)?2:1;
                if(pn((p[next]-X[1])*V[1])==pn((p[pos[0]]-X[1])*V[1])
                 ||pn((p[n-next]-X[1])*V[1])==pn((p[n-pos[0]]-X[1])*V[1]))return 1;
            }
        }
        if(num[1]==1){
            cnt=0;
            if((p[0]-X[0])*V[0])cnt++;
            if(i==n-i){
                if((p[i]-X[0])*V[0])cnt++;
            }
            if(cnt==0){
                int next=(pos[1]==1)?2:1;
                if(pn((p[next]-X[0])*V[0])==pn((p[pos[1]]-X[0])*V[0])
                 ||pn((p[n-next]-X[0])*V[0])==pn((p[n-pos[1]]-X[0])*V[0]))return 1;
            }
        }
        return 0;
    }
}
bool f2(Point p[]){
    Point X[2],V[2];
    int num[2]={},now=0,pos[2]={},i;
    for(i=0;i<n-1-i;i++)
        if(!Add(X,V,num,pos,now,p[i],p[n-1-i],i))return 0;
    if(now==1)return 1;
    if(num[0]==1){
        int next=(pos[0]==0)?1:0;
        if(pn((p[next]-X[1])*V[1])==pn((p[pos[0]]-X[1])*V[1])
             ||pn((p[n-1-next]-X[1])*V[1])==pn((p[n-1-pos[0]]-X[1])*V[1]))return 1;
    }
    if(num[1]==1){
        int next=(pos[1]==0)?1:0;
        if(pn((p[next]-X[0])*V[0])==pn((p[pos[1]]-X[0])*V[0])
             ||pn((p[n-1-next]-X[0])*V[0])==pn((p[n-1-pos[1]]-X[0])*V[0]))return 1;
    }
    return 0;
}
int main(){
    int T,i;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(i=0;i<n;i++)a[i].scan();
        if(n<5){
            puts("Y");
            continue;
        }
        for(i=n;i<n+n;i++)a[i]=a[i-n];
        for(i=0;i<n;i++)
            if(f1(a+i))break;
        if(i<n)puts("Y");
        else{
            if(n%2==0){
                for(i=0;i<n;i++){
                    ii=i;
                    if(f2(a+i))break;
                }
                if(i<n)puts("Y");
                else puts("N");
            }
            else puts("N");
        }
    }
    return 0;
}
