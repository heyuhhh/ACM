#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6+6;
int n;
char s[N];
int x[N],y[N],sa[N],c[N];
void Get_sa(int m){
    n=strlen(s);
    for(int i=0;i<m;i++) c[i]=0;
    for(int i=0;i<n;i++) c[x[i]=s[i]]++;//�����������˼�룬c�����൱��һ��Ͱ 
    for(int i=1;i<m;i++) c[i]+=c[i-1]; 
    for(int i=n-1;i>=0;i--) sa[--c[x[i]]]=i;//���sa���飬����--c[x[i]]]���������sa������±�ģ�ע��Ū��sa����ĺ��壡�� 
    for(int k=1;k<=n;k++){
        int p=0;
        for(int i=n-k;i<n;i++) y[p++]=i;
        for(int i=0;i<n;i++) if(sa[i]>=k) y[p++]=sa[i]-k;//�ڶ��ؼ���,y[i]��ʾ���iС�ĵڶ��ؼ�����Եĵ�һ�ؼ���λ�� 
        for(int i=0;i<m;i++) c[i]=0;
        for(int i=0;i<n;i++) c[x[i]]++;
        for(int i=1;i<m;i++) c[i]+=c[i-1];
        for(int i=n-1;i>=0;i--) sa[--c[x[y[i]]]]=y[i];//���������ڶ��ؼ�������ͬʱ����һ�ؼ���Ҳ�Ǿ����ܴ�ģ�sa������󷨿ɲμ����� 
        swap(x,y);
        p=1;x[sa[0]]=0;
        for(int i=1;i<n;i++)
            x[sa[i]]=y[sa[i-1]]==y[sa[i]]&&y[sa[i-1]+k]==y[sa[i]+k]?p-1:p++;//�ֱ�Ƚϵ�һ�ؼ��ֺ͵ڶ��ؼ���
			//����x[i]��ʾ���Ǻ�׺i�Ĵ�СΪ���٣������൱�ڽ���һ���ڶ��ؼ��ֺϲ�Ϊ��һ�ؼ��� 
        if(p>=n) break ;
        m=p;
    }
}
int main(){
    scanf("%s",s);
    Get_sa(123);
    int n=strlen(s);
    for(int i=0;i<n;i++) cout<<sa[i]+1<<" ";
    return 0;
}

