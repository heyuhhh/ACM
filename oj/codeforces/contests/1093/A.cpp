#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    int n;
    while(t--){
        cin>>n;
        for(int i=2;i<=7;i++){
            if(n%i!=1){
                cout<<n/i+(n%i!=0)<<endl;
                break ;
            }
        }
    }
    return 0;
}
