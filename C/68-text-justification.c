#include <string.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** fullJustify(char** words, int wordsSize, int maxWidth, int* returnSize) {
    int count = 0;
    int startLine = 0;
    int endLine = 0;
    int wordsLength = 0;
    char** output = malloc(wordsSize * sizeof(char*));

    for(int i = 0; i < wordsSize; i++){
        int wordLength = strlen(words[i]);
        int wordCount = endLine - startLine;

        if (wordsLength + wordLength + wordCount <= maxWidth){
            endLine++;
            wordsLength += wordLength;
        } else {
            int diff = maxWidth - wordsLength;
            int gapCount = endLine - startLine - 1;

            output[count] = malloc(maxWidth + 1);
            output[count][0] = '\0';

            for(int j = startLine; j < endLine; j++){
                strcat(output[count], words[j]);

                if(j < endLine - 1){
                    int spacesToAdd = diff / gapCount;

                    if(j - startLine < diff % gapCount) spacesToAdd++;

                    for(int k = 0; k < spacesToAdd; k++){
                        strcat(output[count], " ");
                    }
                }
            }

            while(strlen(output[count]) < (size_t)maxWidth){
                strcat(output[count], " ");
            }

            count++;

            startLine = i;
            endLine = i + 1;
            wordsLength = wordLength;
        }
    }

    output[count] = malloc(maxWidth + 1);
    output[count][0] = '\0';

    for(int j = startLine; j < endLine; j++){
        if(j > startLine) strcat(output[count], " ");

        strcat(output[count], words[j]);
    }

    while(strlen(output[count]) < maxWidth){
        strcat(output[count], " ");
    }

    count++;

    *returnSize = count;

    return output;
}
