int majorityElement(int* nums, int numsSize) {
    int candidate;
    int count = 1;

    candidate = nums[0];
    for(int i = 1; i < numsSize; i++){
        if(count == 0) candidate = nums[i];
        
        if(candidate != nums[i])
            count--;
        else
            count++;
    }

    return candidate;
}
