int reverse(int x){
    int res = 0;
    unsigned int n = x;
    bool isNegative = 0;
    
    if(x < 0){
        n += -2*n;
        isNegative = 1;
    } 

    // 123
    while(n != 0){
        int a = n % 10;

        if (res > INT_MAX / 10) return 0;

        res = res == 0 ? a : 10 * res + a;
        n /= 10;
        x /= 10;
    }

    return isNegative ? -1 * res : res;
}
