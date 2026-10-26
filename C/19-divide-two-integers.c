int divide(int dividend, int divisor) {
    if (dividend == INT_MIN && divisor == -1) {
        return INT_MAX;
    }

    int isDividendNegative = dividend < 0;
    int isDivisorNegative = divisor < 0;

    if (dividend > 0) {
        dividend = -dividend;
    }

    if (divisor > 0) {
        divisor = -divisor;
    }

    int res = 0;

    while (dividend <= divisor) {
        int chunk = divisor;
        int count = -1;

        while (chunk >= INT_MIN - chunk && dividend <= chunk + chunk) {
            chunk += chunk;
            count += count;
        }

        dividend -= chunk;
        res += count;
    }

    if (isDividendNegative == isDivisorNegative) {
        return -res;
    }

    return res;
}
