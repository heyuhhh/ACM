#include <bits/stdc++.h>
using namespace std;

const int N = 505;
int a[N];
int n,sum;

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]),sum+=a[i];
    if(sum<2*(n-1)){
        cout<<"NO";return 0;
    }
    vector <int> ones;
    for(int i=1;i<=n;i++){
        if(a[i]==1) a[i]=0 , ones.push_back(i);
    }
    int t=ones.size();
    printf("YES %d\n%d\n",n-t-1+min(t,2),n-1);
    int st=0;
    if(!ones.empty()){
        st=ones.back();
        ones.pop_back();
    }
    for(int i=1;i<=n;i++){
        if(a[i]>1){
            if(st){
                a[st]--;a[i]--;
                printf("%d %d\n",st,i);
            }
            st=i;
        }
    }
    for(int i=n;i>=1;i--){ // 从尾开始添加（链） 
        while(a[i]>0 && !ones.empty()){
            a[i]--;
            int now1 = ones.back();ones.pop_back();
            printf("%d %d\n",i,now1);
        }
    }
    return 0;
}

