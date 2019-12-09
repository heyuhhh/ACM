// #include {{{
#include <iostream>
#include <cassert>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <cmath>
#include <ctime>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#include <bitset>
#include <vector>
#include <complex>
#include <algorithm>
using namespace std;
// }}}
// #define {{{
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> vi;
#define de(x) cout << #x << "=" << x << endl
#define rep(i,a,b) for(int i=a;i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define fi first
#define se second
// }}}

const int N = 9 * 9 * 9 * 9 * 3;

struct S {
  int x , y;
  S(){}
  S(int x,int y):x(x),y(y){}
  bool operator == (const S &b) const {
    return x == b.x && y == b.y;
  }
  bool operator < (const S &b) const {
    return x * b.y < y * b.x;
  }
  bool operator <= (const S &b) const {
    return *this < b || *this == b;
  }
  void output() {cout << x << "/" << y << endl;}
};
S inf(0,-1);
int board[9],nboard[9];
S f[N];

void Prepare() {
  rep(i,0,N) {
    int t = i;
    rep(j,0,9) board[j]=t%3,t/=3;
    S left=inf,right=inf;
    auto getmask = [&]() {
      int r=0;per(j,0,9)r=r*3+nboard[j];
      return r;
    };
    auto UpdateLeft = [&]() {
      S s=f[getmask()];
      if(left==inf||left<s)
        left=s;
    };
    auto UpdateRight = [&]() {
      S s=f[getmask()];
      if(right==inf||s<right)
        right=s;
    };
    auto half = [&](S& a,S& b) {
      ll down=max(a.y,b.y);
      ll up=a.x*(down/a.y)+b.x*(down/b.y);
      down<<=1;
      while(up%2==0) up/=2,down/=2;
      return S(up,down);
    };
    rep(j,0,9) if(board[j]==1) {
      int x=j/3,y=j%3;
      rep(i,0,9) nboard[i]=board[i];
      nboard[j]=0;
      if(x) nboard[j-3]=0;
      if(x!=2) nboard[j+3]=0;
      UpdateLeft();
      if(y) nboard[j-1]=0;
      if(y!=2) nboard[j+1]=0;
      UpdateLeft();
      rep(i,0,9) nboard[i]=board[i];
      nboard[j]=0;
      if(y) nboard[j-1]=0;
      if(y!=2) nboard[j+1]=0;
      UpdateLeft();
    }
    rep(j,0,9) if(board[j]==2) {
      rep(i,0,9) nboard[i]=board[i];
      nboard[j]=0;
      UpdateRight();
    }
    if(left==inf&&right==inf) {
      f[i]=S(0,1);
    } else if(left==inf) {
      f[i]=S(right.x-1,1);
    } else if(right==inf) {
      f[i]=S(left.x+1,1);
    } else {
      assert(left < right);
      S l=inf,r=inf,x(0,1);
      while(right<=x||x<=left) {
        if(right<=x) {
          r=x;
          if(l==inf) x.x--;
          else x=half(l,r);
        } else {
          l=x;
          if(r==inf) x.x++;
          else x=half(l,r);
        }
      }
      f[i]=x;
    }
  }
}

int main() {
  Prepare();
  int T;
  scanf("%d",&T);
  rep(i,0,T) {
    int n;
    scanf("%d",&n);
    int sum=0;
    rep(i,0,n) {
      char s[10];
      string b;
      rep(i,0,3) {
        scanf("%s",s);
        rep(j,0,3) b+=s[j<<1];
      }
      int mask=0;
      per(i,0,9) mask=mask*3+(b[i]=='#'||b[i]=='.'?0:(b[i]=='O'?1:2));
      sum+=f[mask].x*(64/f[mask].y);
    }
    if(sum==0) puts("Second");
    else if(sum>0) puts("Alice");
    else if(sum<0) puts("Bob");
  }
  return 0;
}

