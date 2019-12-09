ll p[65];
void xor_base(){
    for(int i=1;i<=n;i++){
        for(ll j=62;j>=0;j--){
            if((1LL<<j)&a[i]){
                if(!p[j]){
                    p[j]=a[i];
                    break;
                }
                a[i]^=p[j];
            }
        }
    }
} 
