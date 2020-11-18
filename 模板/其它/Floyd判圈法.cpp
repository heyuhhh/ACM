<<<<<<< HEAD
// Floydåˆ¤åœˆæ³•
// ç”¨äºŽå¿«é€Ÿåˆ¤æ–­ä¸€ä¸ªå‡½æ•°çš„å¾ªçŽ¯èŠ‚ç›¸å…³ä¿¡æ¯
ll f(ll x) {
    //å‡½æ•°
    return (x + (x >> 20) + 12345) % MOD;
}
//firstä¸ºèµ·ç‚¹å¤„çš„å€¼ï¼Œlenä¸ºå¾ªçŽ¯èŠ‚é•¿åº¦ï¼Œidä¸ºå¾ªçŽ¯èŠ‚èµ·å§‹å¤„åæ ‡ï¼Œvalä¸ºå¾ªçŽ¯èŠ‚èµ·å§‹å¤„çš„å€¼
=======
ll f(ll x) {
    //º¯Êý
    return (x + (x >> 20) + 12345) % MOD;
}
//firstÎªÆðµã´¦µÄÖµ£¬lenÎªÑ­»·½Ú³¤¶È£¬idÎªÑ­»·½ÚÆðÊ¼´¦×ø±ê£¬valÎªÑ­»·½ÚÆðÊ¼´¦µÄÖµ
>>>>>>> 69e9080b9001e454b6fc968183fcfd8a9df062de
bool FloydCycle(ll first, ll& len, ll& id, ll& val) {
    ll slow, fast;
    slow = f(first);
    fast = f(f(first));
    int cnt = 1;
    while(slow != fast && cnt <= 1000000000)
    {
<<<<<<< HEAD
        //å¿«æŒ‡é’ˆçš„ç§»åŠ¨é€Ÿåº¦æ˜¯æ…¢æŒ‡é’ˆçš„2å€
=======
        //¿ìÖ¸ÕëµÄÒÆ¶¯ËÙ¶ÈÊÇÂýÖ¸ÕëµÄ2±¶
>>>>>>> 69e9080b9001e454b6fc968183fcfd8a9df062de
        slow = f(slow);
        fast = f(f(fast));
        cnt++;
    }
<<<<<<< HEAD
    if(slow != fast) return false;//æ— çŽ¯

    len = 1;//çŽ¯çš„é•¿åº¦
=======
    if(slow != fast) return false;//ÎÞ»·

    len = 1;//»·µÄ³¤¶È
>>>>>>> 69e9080b9001e454b6fc968183fcfd8a9df062de
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
<<<<<<< HEAD
} 
=======
}
>>>>>>> 69e9080b9001e454b6fc968183fcfd8a9df062de
