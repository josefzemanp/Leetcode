#include <string.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

const char *letters[] = {
    "abc",  // 2
    "def",  // 3
    "ghi",  // 4
    "jkl",  // 5
    "mno",  // 6
    "pqrs", // 7
    "tuv",  // 8
    "wxyz"  // 9
};

char** letterCombinations(char* digits, int* returnSize) {
    size_t digitsCount = strlen(digits);
    int combsCount = 0;
    
    int blocks[digitsCount] = {};

    for(int i = 0; i < digitsCount; i++){
        if(i == 0){
            combsCount = strlen(letters[digits[i] - '2']);
            blocks[i] = digits[i] - '2';
            continue;
        }
        
        blocks[i] = digits[i] - '2';
        combsCount *= strlen(letters[digits[i] - '2']);
    }

    char **res = malloc(combsCount * sizeof(char *));

    for(int i = 0; i < combsCount; i++){
        res[i] = malloc(digitsCount + 1);

        int index = i;

        for(int j = (int)digitsCount - 1; j >= 0; j--){
            const char *chars = letters[digits[j] - '2'];
            int count = strlen(chars);

            res[i][j] = chars[index % count];

            index /= count;
        }
        
        res[i][digitsCount] = '\0';
    }

    *returnSize = combsCount;

    return res;
}
