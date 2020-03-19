#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5005;
vector <int> g[5];
int n;
char s1[N],s2[N];
int main(){
    scanf("%d",&n);
    scanf("%s%s",s1+1,s2+1);
    int all=0,fir=0,sec=0,no=0;
    for(int i=1;i<=n;i++){
        if(s1[i]=='1'&&s2[i]=='1'){
            g[0].push_back(i);
            all++;
        }else if(s1[i]=='1'){
            g[1].push_back(i);
            fir++;
        }else if(s2[i]=='1'){
            g[2].push_back(i);
            sec++;
        }else{
            g[3].push_back(i);
            no++;
        }
    }
    for(int i=0;i<=all;i++){
        for(int j=0;j<=fir;j++){
            int need = i+j;
            if(need<=n/2&&all-i+sec>=need){
                for(int k=0;k<=sec;k++){
                    if(need==sec-k+all-i&&n/2-need-k>=0){
                        int non=n/2-need-k;
                        if(non>no) continue ;
                        i--;j--;k--;non--;
                         //cout<<i<<" "<<j<<" "<<k<<" "<<non<<endl;
                        while(i>=0) printf("%d ",g[0][i]),i--;
                        while(j>=0) printf("%d ",g[1][j]),j--;
                        while(k>=0) printf("%d ",g[2][k]),k--;
                        while(non>=0) printf("%d ",g[3][non]),non--;
                        return 0;
                    }
                }
            }
        }
    }
    printf("-1");
    return 0;
}¡¢ 
