// https://leetcode.com/problems/two-sum/submissions/2067366367

class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> seen = new HashMap<>();
        int[] answer = new int[2];

        for (int i = 0; i < nums.length; i++) {
            if (seen.containsKey(target - nums[i])) {
                answer[0] = seen.get(target - nums[i]);
                answer[1] = i;
                break;
            }
            seen.put(nums[i], i);
        }

        return answer;
    }
}
