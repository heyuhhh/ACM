#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
ll L,v,l,r;
int main(){
    scanf("%d",&t);
    while(t--){
        cin>>L>>v>>l>>r;
        int left = l/v+(l%v!=0),right = r/v;
        int tot = L/v;
        if(left>right){
            cout<<tot<<endl;
        }else{
            cout<<tot-(right-left+1)<<endl;
        }
    }
    return 0;
}
