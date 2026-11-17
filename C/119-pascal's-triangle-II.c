/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize) {
    *returnSize = rowIndex + 1;

    int *row = malloc((rowIndex + 1) * sizeof(int));
    
    row[0] = 1;
    row[rowIndex] = 1;

    // (4 0) (4 1) (4 2) (4 3)
    // C(n, i) = C(n, i - 1) * (n - i + 1) / i
    for(int i = 1; i < rowIndex; i++){
        row[i] = (((long long)row[i-1] * (rowIndex - i + 1)) / i);
    }


    return row;
}
