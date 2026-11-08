int removeDuplicates(int* nums, int numsSize) {
    int writeIndex = 1;

    // 1 2 2 3 4 4 5
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] != nums[writeIndex - 1]) {
            nums[writeIndex] = nums[i];
            writeIndex++;
        }
    }

    return writeIndex;
}
