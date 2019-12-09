#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define rep(i, a, b) for(int i=(a); i<(b); i++)
#define per(i, a, b) for(int i=(b)-1; i>=(a); i--)
#define sz(a) (int)a.size()
#define de(a) cout << #a << " = " << a << endl
#define dd(a) cout << #a << " = " << a << " "
#define all(a) a.begin(), a.end()
#define pw(x) (1ll<<(x))
#define endl "\n"
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef double db;


int p=1e6+3,n,ret=1;

int main() {
    
    while (scanf("%d",&n)!=EOF) {
        if (n>=p)  {printf("%d\n",0); continue;} 
        ret=1; rep(i,1,n+1) ret=(ll)ret*i%p;
        printf("%d\n",ret);
    }
    
    return 0;
}

