// O(n^2)
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    int x = *(const int *)a;
    int y = *(const int *)b;

    return (x > y) - (x < y);
}

int distance(int a, int b){
    if((a - b) < 0){
        return (a - b) + -2 * (a - b);
    }

    return a - b;
}

int threeSumClosest(int* nums, int numsSize, int target) {
    int closestSum = 0;
    int closestDist = 0;
    bool first = 1;

    qsort(nums, numsSize, sizeof(int), cmp);

    for (int i = 0; i < numsSize; i++) { // 1 
        int left = i + 1;
        int right = numsSize - 1;

        while(left < right){
            int sum = nums[i] + nums[left] + nums[right];

            int dist = distance(target, sum);

            if (first || dist < closestDist) {
                closestSum = sum;
                closestDist = dist;
                first = false;
            }

            if (sum < target)
                left++;
            else if (sum > target)
                right--;
            else
                return sum;
        }
    }

    return closestSum;
}
