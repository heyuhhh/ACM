#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<set>
#include<assert.h>
using namespace std;
const int MAX_N = 50000;
int n, b[MAX_N+1];
int stk_upper[MAX_N], stk_lower[MAX_N];
int sn_upper,sn_lower;
vector<pair<int, int>> d[MAX_N * 2 + 1];
int used[MAX_N * 2 + 1];
bool check(vector<int>&an) {
    set<int>H;
    for(int i = 0; i < n; i++) {
        H.insert(an[i]);
    }
    for(int i = 1; i <= n; i++) {
        if(b[i] > 0) {
            if(*H.rbegin() != b[i]) return 0;
            H.erase(b[i]);
        }
        else {
            if(*H.begin() != abs(b[i])) return 0;
            H.erase(abs(b[i]));
        }
        H.insert(an[i+n-1]);
    }
    return 1;
}
int get_left_bound(int v) {
    int ll = -1, rr = sn_upper - 1;
    int l_id = 1;
    while(ll < rr) {
        int mm = (ll + rr + 1) / 2;
        if(abs(b[stk_upper[mm]]) <= v) ll = mm;
        else rr = mm - 1;
    }
    if(ll != -1) l_id = n + stk_upper[ll];
    ll = -1, rr = sn_lower - 1;
    while(ll < rr) {
        int mm = (ll + rr + 1) / 2;
        if(abs(b[stk_lower[mm]]) >= v) ll = mm;
        else rr = mm - 1;
    }
    if(ll != -1) l_id = max(l_id, n + stk_lower[ll]);
    return l_id;
}
bool invalid() {
    multiset<int> H;
    for(int i = 1; i <= 2 * n; i++) {
        for(auto pp: d[i]) {
            H.insert(pp.first);
        }
        if(H.empty() || *H.begin() < i) return true;
        H.erase(H.begin());
    }
    return false;
}
void solve(){
    sn_upper = sn_lower = 0;
    for(int i = 1; i <= 2 * n; i++) used[i] = 0, d[i].clear();
    for(int i = 1; i <= n; i++) {
        used[abs(b[i])] = 1;
        d[get_left_bound(abs(b[i]))].push_back({n+i-1,abs(b[i])});
        if(b[i] > 0) {
            while(sn_upper && abs(b[stk_upper[sn_upper - 1]]) > abs(b[i])) {
                sn_upper--;
            }
            stk_upper[sn_upper++] = i;
        }
        else {
            while(sn_lower && abs(b[stk_lower[sn_lower - 1]]) < abs(b[i])) {
                sn_lower--;
            }
            stk_lower[sn_lower++] = i;
        }
    }
    for(int i = 1; i <= 2 * n; i++) {
        if(!used[i]) {
            d[get_left_bound(i)].push_back({n * 2, i});
        }
    }
    /*
    for(int i = 1; i<=2*n;i++){
        printf("%d:",i);
        for(int j=0;j<(int)d[i].size();j++)printf("(%d,%d)",d[i][j].first,d[i][j].second);
        puts("");
    }
    */
    if(invalid()) {
        puts("-1");
        return;
    }
    else {
        set<int>ids;
        for(int i = 0; i < (int)d[1].size(); i++) {
            ids.insert(d[1][i].second);
        }
        vector<int> an;
        for(int i = 1; i < n; i++){
            an.push_back(*ids.begin());
            ids.erase(ids.begin());
        }
        for(int i = n; i < 2 *n; i++) {
            for(int j = 0; j < (int)d[i].size(); j++) {
                ids.insert(d[i][j].second);
            }
            int me = abs(b[i - n + 1]);
            if(ids.count(me)) {
                an.push_back(me);
                ids.erase(me);
            }
            else {
                an.push_back(*ids.begin());
                ids.erase(ids.begin());
            }
        }
        for(int i = 0; i < (int)d[2 * n].size(); i++) {
            ids.insert(d[2 * n][i].second);
        }
        an.push_back(*ids.begin());
        for(int i = 0; i < 2 * n; i++) printf("%d%c", an[i], " \n"[i == 2 * n - 1]);
        //assert(check(an));
    }
}
void test() {
    n = 4;
    int bb[21];
    for(int i = 1; i <= 2*n; i++)bb[i]=i;
    random_shuffle(bb+1,bb+2*n+1);
    sort(bb+1,bb+n+1);
    for(int i=1;i<=2*n;i++) {
        printf("%d%c",bb[i]," \n"[i==2*n]);
    }
    set<int>AA;
    for(int i=1;i<=n;i++)AA.insert(bb[i]);
    for(int i=1;i<=n;i++){
        if(rand()%2){
            b[i]=*AA.rbegin();
            AA.erase(b[i]);
        }
        else{
            b[i]=-*AA.begin();
            AA.erase(abs(b[i]));
        }
        AA.insert(bb[i+n]);
    }
    for(int i=1;i<=n;i++)printf("%d%c",b[i]," \n"[i==n]);
    solve();
}
int main(){
    //test();
    int T;
    scanf("%d", &T);
    while(T--){
        scanf("%d", &n);
        for(int i=1;i<=n;i++) scanf("%d",&b[i]);
        solve();
    }
    return 0;
}
