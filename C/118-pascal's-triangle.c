/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
    *returnSize = numRows;
    *returnColumnSizes = malloc(numRows * sizeof(int));

    int **pascal = malloc(numRows * sizeof(*pascal));

    for(int row = 0; row < numRows; row++){
        pascal[row] = malloc((row + 1) * sizeof(int));
        (*returnColumnSizes)[row] = row + 1;

        if(row == 0) {
            pascal[row][0] = 1;
            continue;    
        }
        if(row == 1) {
            pascal[row][0] = 1;
            pascal[row][1] = 1;
            continue;
        }

        for(int i = 0; i < (row + 1); i++){
            if(i == 0 || i == row){
                pascal[row][i] = 1;
                continue;
            }

            int prevSum = pascal[row - 1][i - 1] + pascal[row - 1][i];
            pascal[row][i] = prevSum;
        }
    }

    return pascal;
}
