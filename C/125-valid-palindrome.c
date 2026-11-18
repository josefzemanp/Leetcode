#include <ctype.h>

bool isPalindrome(char* s) {
    int length = 0;

    while (s[length] != '\0') {
        length++;
    }

    int i = 0;
    int j = length - 1;

    while (i < j) {
        if (!isalnum((unsigned char)s[i])) {
            i++;
            continue;
        }

        if (!isalnum((unsigned char)s[j])) {
            j--;
            continue;
        }

        if (tolower((unsigned char)s[i]) != tolower((unsigned char)s[j])) {
            return 0;
        }

        i++;
        j--;
    }

    return 1;
}
