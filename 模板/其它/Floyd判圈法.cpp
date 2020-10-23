// Floyd判圈法
// 用于快速判断一个函数的循环节相关信息
ll f(ll x) {
    //函数
    return (x + (x >> 20) + 12345) % MOD;
}
//first为起点处的值，len为循环节长度，id为循环节起始处坐标，val为循环节起始处的值
bool FloydCycle(ll first, ll& len, ll& id, ll& val) {
    ll slow, fast;
    slow = f(first);
    fast = f(f(first));
    int cnt = 1;
    while(slow != fast && cnt <= 1000000000)
    {
        //快指针的移动速度是慢指针的2倍
        slow = f(slow);
        fast = f(f(fast));
        cnt++;
    }
    if(slow != fast) return false;//无环

    len = 1;//环的长度
    slow = f(slow);
    while(slow != fast)
    {
        slow = f(slow);
        len++;
    }

    id = 0;
    slow = first;
    while(slow != fast)
    {
        slow = f(slow);
        fast = f(fast);
        id++;
    }
    val = slow;

    return true;   
} 