#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5+5;
ll dp[N][5]; //dp(i,j):ǰi�����У�ɾ��ĳЩ�ַ���
//ɾ�����ַ�Ϊ��1-j�е�hard�ַ���ʹ����Ϊi�Ĵ�����hard�����е���С���ۡ�
//UPD:dp(i,j):ǰi��λ�ã�����j��ɾ�����С���ۡ�
char s[N];
ll a[N];
int n;
int main(){
    scanf("%d",&n);
    scanf("%s",s+1);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++){
        dp[i][0]=dp[i-1][0]+(s[i]=='h')*a[i];
        dp[i][1]=min(dp[i-1][0],dp[i-1][1]+(s[i]=='a')*a[i]);
        dp[i][2]=min(dp[i-1][1],dp[i-1][2]+(s[i]=='r')*a[i]);
        dp[i][3]=min(dp[i-1][2],dp[i-1][3]+(s[i]=='d')*a[i]);
    }
    cout<<min({dp[n][3],dp[n][2],dp[n][1],dp[n][0]});
    return 0;
}

