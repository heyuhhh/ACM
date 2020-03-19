#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;
const int N = 25;
int n;
int a[N];
int main(){
    while(scanf("%d",&n)!=EOF){
        int x = 0;
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            x^=a[i];
        }
        int f = 0;
        for(int i=1;i<=n;i++){
            if((a[i]^x)<a[i]) f=1;
        }
        if(f) cout<<"Yes"<< '\n';
        else cout<<"No"<<'\n';
    }

    return 0;
}
