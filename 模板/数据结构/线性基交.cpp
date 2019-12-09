/*
	普通线性基就不说了，给出线性基求交集的模板
	
	求交的话大概就是对于两个基集合$B_1,B_2$,枚举$B_2$中的基，如果与$B_1$线性无关，
	那么就插在$B_1$里面去；否则就对于当前的基，异或掉$B_1$中之前插进去的$B_2$的基，
	然后将其插入交集里面就行了。
*/
struct node{
    ui r[32], f[32];
    bool ins(ui x) {
        for(int i = 31; i >= 0; i--) {
            if(x >> i) {
                if(!r[i]) {r[i] = x; return 1;}
                else x ^= r[i];
            }
        }
        return 0;
    }
    bool ins2(ui x) {
        ui tmp = x;
        for(int i = 31; i >= 0; i--) {
            if(x >> i) {
                if(!r[i]) {r[i] = x; f[i] = tmp; return 1;}
                else {
                    x ^= r[i]; tmp ^= f[i];
                }
            }
        }
        return 0;
    }
    void clear() {
        for(int i = 0; i <= 31; i++) r[i] = f[i] = 0;
    }
    bool find(ui x) {
        for(int i = 31; i >= 0; i--) {
            if(x >> i) {
                if(!r[i]) return 0;
                x ^= r[i];
            }
        }
        return x == 0;
    }
    int calc(ui x) {
        int ans = 0;
        for(int i = 31; i >= 0; i--) {
            if(x >> i) {
                x ^= r[i];
                ans ^= f[i];
            }
        }
        return ans;
    }
};
node _merge(node u, node v) {
    node tmp, res; res.clear();
    tmp = u;
    for(int i = 31; i >= 0; i--) {
        ui x = v.r[i];
        if(tmp.find(x)) {
            res.ins(x ^ tmp.calc(x)); //去除原v中基的影响 
        } else tmp.ins2(x);
    }
    return res;
} 
