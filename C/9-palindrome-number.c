bool isPalindrome(int x) {
    if (x < 0) return 0;

    int divisor = 1;

    while (x / divisor >= 10) {
        divisor *= 10;
    }

    while (x > 0) {
        int leftDigit = x / divisor;
        int rightDigit = x % 10;

        if (leftDigit != rightDigit) {
            return 0;
        }

        x = (x % divisor) / 10;

        divisor /= 100;
    }

    return 1;
}
