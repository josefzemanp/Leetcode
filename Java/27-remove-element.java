// https://leetcode.com/problems/remove-element/submissions/2065880129

class Solution {
    public int removeElement(int[] nums, int val) {
        // [3,5,0,3,3,2,3]
        // 3
        
        int steps = 0;
        int answer = 0;
        
        for(int i = 0; i<nums.length; i++){
            if(nums[i] == val){
                nums[i] = -1;
                steps++;
            } else {
                if(steps != 0){
                    nums[i-steps] = nums[i];
                    nums[i] = -1;
                }
                answer++;
            }
        }
        
        return answer;
    }
}
