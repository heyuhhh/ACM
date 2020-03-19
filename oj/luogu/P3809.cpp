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
    for(int i=0;i<n;i++) c[x[i]=s[i]]++;//基数排序基本思想，c数组相当于一个桶 
    for(int i=1;i<m;i++) c[i]+=c[i-1]; 
    for(int i=n-1;i>=0;i--) sa[--c[x[i]]]=i;//求出sa数组，这里--c[x[i]]]是用来求出sa数组的下标的，注意弄懂sa数组的含义！！ 
    for(int k=1;k<=n;k++){
        int p=0;
        for(int i=n-k;i<n;i++) y[p++]=i;
        for(int i=0;i<n;i++) if(sa[i]>=k) y[p++]=sa[i]-k;//第二关键字,y[i]表示与第i小的第二关键字配对的第一关键字位置 
        for(int i=0;i<m;i++) c[i]=0;
        for(int i=0;i<n;i++) c[x[i]]++;
        for(int i=1;i<m;i++) c[i]+=c[i-1];
        for(int i=n-1;i>=0;i--) sa[--c[x[y[i]]]]=y[i];//倒序很巧妙，第二关键字最大的同时，第一关键字也是尽可能大的，sa数组的求法可参见上面 
        swap(x,y);
        p=1;x[sa[0]]=0;
        for(int i=1;i<n;i++)
            x[sa[i]]=y[sa[i-1]]==y[sa[i]]&&y[sa[i-1]+k]==y[sa[i]+k]?p-1:p++;//分别比较第一关键字和第二关键字
			//这里x[i]表示的是后缀i的大小为多少，这里相当于将第一、第二关键字合并为第一关键字 
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

