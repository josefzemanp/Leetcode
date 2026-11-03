#include <string.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    int prefixLen = 0;
    int firstLen = strlen(strs[0]);
    bool isMatching = 1;

    char *prefix = malloc(firstLen + 1);

    if (prefix == NULL) return NULL;

    prefix[0] = '\0';

    while (isMatching && prefixLen < firstLen) {
        for (int i = 0; i < strsSize; i++) {
            if (strs[i][prefixLen] == '\0' || strs[0][prefixLen] != strs[i][prefixLen]) {
                isMatching = 0;
                break;
            }
        }

        if (isMatching) {
            prefix[prefixLen] = strs[0][prefixLen];
            prefixLen++;
        }
    }

    prefix[prefixLen] = '\0';

    return prefix;
}
