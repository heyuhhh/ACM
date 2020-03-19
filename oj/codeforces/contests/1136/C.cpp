#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 505;
int n,m;
int a[N][N];
int b[N][N];
vector <int> vec1,vec2;
int main(){
    ios::sync_with_stdio(false);cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>a[i][j];
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>b[i][j];
    int last=0;
    for(int k=2;k<=n+m;k++){
        vec1.clear();vec2.clear();
        int i,j;
        if(k<=1+m) i=1;
        else i=k-m;
        j = k-i;
        //cout<<endl<<endl;
        while(i<k && i<=n && j>=1){
            //cout<<i<<" "<<j<<endl;
            vec1.push_back(a[i][j]);
            vec2.push_back(b[i][j]);
            i++;j--;
        }
        sort(vec1.begin(),vec1.end());
        sort(vec2.begin(),vec2.end());
        int s=vec1.size();
        for(i=0;i<s;i++){
            if(vec1[i]!=vec2[i]){
                cout<<"NO";
                return 0;
            }
        }
    }
    cout<<"YES";
    return 0;
}
