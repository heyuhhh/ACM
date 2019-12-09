//Trie树（数组模拟链表，左儿子右兄弟）
struct Trie{
    char node;
    int son,left;
}tre[N];
void init(){
    tre[0].son=tre[0].left=-1;;tot=1;
}
void insert(){
    int j,u=0;
    int l = strlen(s);
    for(int i=0;i<l;i++){
        bool flag=false;
        for(j=tre[u].son;j!=-1;j=tre[j].left){
            if(tre[j].node==s[i]){
                flag=true;
                break ;
            }
        }
        if(!flag){
            j=tot++;
            tre[j].left=tre[u].son;tre[u].son=j;tre[j].node=s[i];tre[j].son=-1;
        }
        u=j;
    }
} 
int query(){
    int ans = 0;
    int u=0,j;
    for(int i=0;i<cnt;i++){
        bool flag=false;
        for(j=tre[u].son;j!=-1;j=tre[j].left){
            if(tre[j].node==s[i]){
                flag=true;
                break ;
            }
        }
        /*need to do*/ 
        u=j;
    }
    return ans ;
}
