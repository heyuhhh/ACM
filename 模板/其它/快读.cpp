template <class T>
inline void read(T& x) {
    static char c;
    x = 0;
    bool sign = 0;
    while (!isdigit(c = getchar()))
        if (c == '-')
            sign = 1;
    for (; isdigit(c); x = x * 10 + c - '0', c = getchar())
        ;
    if (sign)
        x = -x;
}
