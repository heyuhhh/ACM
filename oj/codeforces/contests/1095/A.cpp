#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 105;
int n;
char s[N];
int main(){
    scanf("%d",&n);
    scanf("%s",s);
    int now = 1;
    int last = 0;
    for(int i=0;i<n;i++){
        if(i-last+1==now){
            now++;
            last = i;
            cout<<s[i];
        }
    }
    return 0;
}
