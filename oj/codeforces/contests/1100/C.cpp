#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
double n,r;
int main(){
    cin>>n>>r;
    double pi;
    double now = (double)360/n;
    now/=2;
    double Sin = sin(now*3.1415926/180);
    double tmp = 1-Sin;
    double ans = r*Sin/tmp;
    printf("%.8f",ans);
    return 0;
}
