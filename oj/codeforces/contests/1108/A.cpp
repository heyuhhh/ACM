#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int q;
int l1,r1,l2,r2;
int main(){
    cin>>q;
    for(int i=1;i<=q;i++){
        cin>>l1>>r1>>l2>>r2;
        if(l1==l2) l2++;
        cout<<l1<<" "<<l2<<endl;
    }
    return 0;
}
