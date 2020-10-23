const int moder = (int) 1e9 + 7;
const int inv2 = (moder + 1) / 2;
 
struct field2{
    int x, y, a, p;
 
    field2():x(0), y(0), a(0), p(0){}
    field2(int x, int y, int a, int p):x(x), y(y), a(a), p(p){}
 
    field2 operator *(const field2 &f)const{
        int retx = (1ll * x * f.x + 1ll * y * f.y % p * a) % p;
        int rety = (1ll * x * f.y + 1ll * y * f.x) % p;
        return field2(retx, rety, a, p);
    }
 
    field2 powermod(int exp)const{
        field2 ret(1, 0, a, p), aux = *this;
        for ( ; exp > 0; exp >>= 1){
            if (exp & 1){
                ret = ret * aux;
            }
            aux = aux * aux;
        }
        return ret;
    }
};
 
int powermod(int a, int exp, int moder){
    int ret = 1;
    for ( ; exp; exp >>= 1){
        if (exp & 1){
            ret = 1ll * ret * a % moder;
        }
        a = 1ll * a * a % moder;
    }
    return ret;
}
 
int randint(int n){
    return rand() % n;
}
vector <int> remain2(int a, int p){ //x^2 = a (mod p)
    if (!a || p == 2){ //特判
        return {a, a};
    }
    if (powermod(a, p - 1 >> 1, p) != 1){ //欧拉准则
        return {};
    }
    while (true){
        field2 f(randint(p - 1) + 1, randint(p - 1) + 1, a, p);
        f = f.powermod(p - 1 >> 1);
        if (f.x){
            continue;
        }
        int ret = powermod(f.y, p - 2, p);
        return {ret, p - ret};
    }
} 
