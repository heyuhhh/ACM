#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int T;
int ang;
int main(){
    cin>>T;
    while(T--){
        scanf("%d",&ang);
        double ans ;
        int flag;
        for(int i=3;i<=360;i++){
            ans = (double)180/i;
            flag=0;
            if(180%i!=0) for(int j=1;;j++){
                if(j*ans>ang){
                    flag=1;
                    break ;
                }else if((double)j*ans==(double)ang){
                    cout<<i<<endl;
                    flag=2;
                    break ;
                }
            }
            if(flag==1) continue ;
            else if(flag==2) break ;
            if(ang%(int)ans==0&&ans*(i-2)>=ang){
                cout<<i<<endl;
                break ;
            }
        }
    }
    return 0;
}
