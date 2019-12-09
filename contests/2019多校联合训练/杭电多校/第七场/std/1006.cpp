#include<bits/stdc++.h>
#define LL long long
using namespace std;
 
int T;
LL n,m,k;
 
int main()
{
    cin>>T;
    while(T--)
    {
        cin>>n>>m>>k;
        cout<<(m/(n-k+1)+1)*(k-1)+m+1<<endl;
    }
    return 0;
}