#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
ll k,x;

int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>k>>x;
        cout<<9*(k-1)+x<<endl;
    }

    return 0;
}
