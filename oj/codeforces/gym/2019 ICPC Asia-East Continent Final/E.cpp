#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<queue>
typedef long long LL;
using namespace std;
const int MAXN = int(1e5)+7;
const int MAXM = int(2e5)+7;
int hd[MAXN], to[MAXM*2], nxt[MAXM*2], le[MAXM*2], en;
vector<pair<LL,int> > vt[MAXM]; int vtn;
int indic[MAXM];
LL ans=0;
typedef pair<int,int> pii;
priority_queue<pii, vector<pii>, greater<pii> > pq;
void adde(int a, int b, int c) {
    nxt[en]=hd[a]; to[en]=b; le[en]=c; hd[a]=en; en++;
}
void input() {
    int n,m; cin >> n >> m;
    memset(hd,-1,sizeof(hd)); en=0;
    for(int i=0; i<m; i++) {
        int x,y,z; cin >> x >> y >> z;
        adde(x,y,z); adde(y,x,z);
        ans+=z;
    }
    vtn=0;
    for(int i=hd[1]; ~i; i=nxt[i]) {
        int j=i, lst=1;
        while(1) {
            vt[vtn].emplace_back(le[j],1);
            if(to[j]==n) break;
            int k=hd[to[j]];
            if(to[k]==lst) k=nxt[k];
            lst=to[j];
            j=k;
        }
        indic[vtn]=0;
        vtn++;
    }
    ans/=vt[0].size();
    for(int i=0; i<vtn; i++) sort(vt[i].begin(), vt[i].end());
    for(int z=0; z<vtn; z++) {
        int j=0;
        for(int i=1; i<vt[z].size(); i++) {
            if(vt[z][i].first!=vt[z][j].first) {
                j++;
                vt[z][j]=vt[z][i];
            } else {
                vt[z][j].second++;
            }
        }
        vt[z].resize(j+1);
        pq.push(pii(vt[z][0].second,z));
    }
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    input();
    LL cnt=0, nowans=0;
    for(int i=0; i<vtn; i++) nowans+=vt[i][0].first;
    while(1) {
        pii now = pq.top(); pq.pop();
        int &ind = indic[now.second];
        LL tnowans = nowans + vt[now.second][ind+1].first-vt[now.second][ind].first;
        LL tcnt = cnt + now.first * (vt[now.second][ind+1].first-vt[now.second][ind].first);
        //cerr << tcnt << '\t' << tnowans << '\n';
        if(tnowans==ans) {cnt=tcnt; break;}
        else if(tnowans>ans) {
            cnt = cnt + (ans-nowans)*now.first;
            break;
        }
        nowans = tnowans;
        cnt=tcnt;
        ind++;
        if(ind+1<vt[now.second].size()) {
            pq.push(pii(vt[now.second][ind].second+now.first, now.second));
        }
    }

    cout << cnt << '\n';
}