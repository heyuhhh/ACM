#include <bits/stdc++.h>
#define INF 0x3f3f3f3f;
using namespace std;
typedef long long ll;
const int N = 1e6+5;
int n,Max,cnt,d;
mt19937 rnd(time(NULL));
int query1(int x){
    printf("> %d\n",x);
    fflush(stdout);
    int ans;
    scanf("%d",&ans);
    return ans ;
}
void getMAX(){
    int l=0,r=1e9+1,mid;
    while(l<r){
        mid=l+r>>1;
        cnt++;
        if(query1(mid)) l=mid+1;
        else r=mid;
    }
    Max=l;
}
int query2(int pos){
    printf("? %d\n",pos);fflush(stdout);
    int ans;
    scanf("%d",&ans);
    return ans ;
}
void getD(){
    vector <int> lst;
    while(1){
        ++cnt;
        if(cnt>60)break;
        int now=query2(rnd()%n+1);
        lst.push_back(now);
    }
    sort(lst.begin(),lst.end());
    lst.erase(unique(lst.begin(),lst.end()),lst.end());
    if(lst.back()!=Max) lst.push_back(Max);
    d=lst[1]-lst[0];
    for(int i=1;i<lst.size();i++){
        d=__gcd(lst[i]-lst[i-1],d);
    }
}
int main(){
    scanf("%d",&n);
    getMAX();
    getD();
    int Min = Max-(n-1)*d;
    printf("! %d %d",Min,d);
    return 0;
}

