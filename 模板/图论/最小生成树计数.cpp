/*
	bΪ����������󣬼���������-�ڽӾ���ע��Ҫ�����رߣ��ظ��ı�ֻ��һ�Ρ�
*/
ll Det(int n){
    int i,j,k;
    ll ret = 1;
    for(i=2;i<=n;i++){
        for(j = i+1;j <= n;j++){
            while(b[j][i]){
                ll tmp=b[i][i]/b[j][i];//�����ڳ���������� 
                for(k = i;k <= n;k++)
                    b[i][k] -= tmp*b[j][k];
                for(k=i;k<=n;k++)
                    swap(b[i][k],b[j][k]);  
                ret = -ret;
            }
        }
        if(!b[i][i]) return 0;
        ret *= b[i][i];
    }
    if(ret < 0) ret = -ret;
    return ret;
}
