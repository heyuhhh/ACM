#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N =2e5+5;
int n;
int a[N];

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        a[i]&=1;
    }
    vector <int> s;
    for(int i=1;i<=n;i++){
        if(!s.empty()&&a[i]==s.back()){
            s.pop_back();
        }else s.push_back(a[i]);
    }
    if(s.size()<=1) cout<<"YES";
    else cout<<"NO";
    return 0;
}

