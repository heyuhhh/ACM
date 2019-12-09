/*
	��ͨ���Ի��Ͳ�˵�ˣ��������Ի��󽻼���ģ��
	
	�󽻵Ļ���ž��Ƕ�������������$B_1,B_2$,ö��$B_2$�еĻ��������$B_1$�����޹أ�
	��ô�Ͳ���$B_1$����ȥ������Ͷ��ڵ�ǰ�Ļ�������$B_1$��֮ǰ���ȥ��$B_2$�Ļ���
	Ȼ������뽻����������ˡ�
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
            res.ins(x ^ tmp.calc(x)); //ȥ��ԭv�л���Ӱ�� 
        } else tmp.ins2(x);
    }
    return res;
} 
