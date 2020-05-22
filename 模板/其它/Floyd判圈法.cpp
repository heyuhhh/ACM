ll f(ll x) {
    //����
    return (x + (x >> 20) + 12345) % MOD;
}
//firstΪ��㴦��ֵ��lenΪѭ���ڳ��ȣ�idΪѭ������ʼ�����꣬valΪѭ������ʼ����ֵ
bool FloydCycle(ll first, ll& len, ll& id, ll& val) {
    ll slow, fast;
    slow = f(first);
    fast = f(f(first));
    int cnt = 1;
    while(slow != fast && cnt <= 1000000000)
    {
        //��ָ����ƶ��ٶ�����ָ���2��
        slow = f(slow);
        fast = f(f(fast));
        cnt++;
    }
    if(slow != fast) return false;//�޻�

    len = 1;//���ĳ���
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
