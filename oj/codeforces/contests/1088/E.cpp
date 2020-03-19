#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
using namespace std;

int query(int a,int b){
    printf("? %d %d\n",a,b);
    fflush(stdout);
    int tmp;
    scanf("%d",&tmp);
    return tmp;
}

int main(){
    int a=0,b=0;
    int big = query(a,b);
    for(int i=29;i>=0;i--){
        int x=query(a^(1<<i),b),y=query(a,b^(1<<i));
        if(x==y){
            if(big>0) a^=(1<<i);
            else b^=(1<<i);
            big=(x==1);
        }else{
            if(x==-1) a^=(1<<i),b^=(1<<i);
        }
    }
    printf("! %d %d",a,b);
    return 0;
}

