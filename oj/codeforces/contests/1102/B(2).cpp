#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5005;
int n,k;
int a[N],cnt[N],ans[N];
int main(){
    cin>>n>>k;
    vector <int> vec[N];
    int ok = 0;
    if(n<k) ok=1;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++){
        cnt[a[i]]++;
        if(cnt[a[i]]>k) ok =1;
        vec[a[i]].push_back(i);
    }
    if(ok) cout<<"NO";
    else{
        puts("YES");
        int col = 1;
        for(int i=1;i<=5000;i++){
            if(vec[i].size()<=0) continue ;
            for(auto pos : vec[i]){
                ans[pos]=col++;
                if(col>k) col=1;
            }
        }
        for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
    }
    return 0;
}

