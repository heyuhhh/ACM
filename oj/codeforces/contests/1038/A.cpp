#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;
int n,k;
char s[N];
int cnt[30];
int main(){
    cin>>n>>k;
    scanf("%s",s);
    for(int i=0;i<n;i++) cnt[s[i]-'A']++;
    int ans = 0x3f3f3f3f;
    for(int i=0;i<k;i++){
        ans=min(ans,cnt[i]);
    }
    cout<<ans*k;
    return 0;
}
