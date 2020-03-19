#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 300+5;
int n;
char s[N];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        scanf("%d",&x);
        scanf("%s",s+1);
        if(x>=3){
            puts("YES");
            cout<<2<<endl;
            cout<<s[1];
            cout<<" ";
            for(int i=2;i<=x;i++) cout<<s[i];
            cout<<endl;
        }else{
            if(s[2]>s[1]){
                puts("YES");
                cout<<2<<endl;
                cout<<s[1]<<" "<<s[2]<<endl;
            }else puts("NO");

        }
    }
    return 0;
}
