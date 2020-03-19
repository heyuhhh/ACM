#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;
int q;
int l,cnt;
int a[N],b[N];
int main(){
    scanf("%d",&q);
    int mn = 0x3f3f3f3f;
    getchar();
    while(q--){
        char c;
        int id;
        scanf("%c %d",&c,&id);
        if(c=='L'){
            l++;
            a[id]=l;
        }else if(c=='R'){
            cnt++;
            b[id]=cnt;
        }else{
            int tot=l+cnt;
            if(a[id]){
                cout<<min(l-a[id],tot-l+a[id]-1)<<endl;
            }else{
                cout<<min(l-1+b[id],tot-l-b[id])<<endl;
            }
        }
        getchar();
    }

    return 0;
}
