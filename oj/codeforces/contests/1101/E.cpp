#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5+5;
int n;
int main(){
    cin>>n;
    int l = 0,r = 0;
    getchar();
    while(n--){
        char c;
        int x,y;
        scanf("%c %d %d",&c,&x,&y);
        if(x>y) swap(x,y);
        if(c=='+'){
            l=max(l,x);
            r=max(r,y);
        }else{
            if(x<l || y<r) puts("NO");
            else puts("YES");
        }
        getchar();
    }

    return 0;
}
