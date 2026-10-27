// O(n^3)
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

    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            for (int k = j + 1; k < numsSize; k++) {
                int sum = nums[i] + nums[j] + nums[k];

                int dist = distance(target, sum);

                if (first || dist < closestDist) {
                    closestSum = sum;
                    closestDist = dist;
                    first = false;
                }
            }
        }
    }

    return closestSum;
}
