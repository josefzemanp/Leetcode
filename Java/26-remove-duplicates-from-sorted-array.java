// https://leetcode.com/problems/remove-duplicates-from-sorted-array/submissions/2065876068

class Solution {
    public int removeDuplicates(int[] nums) {
        if (nums.length == 0) return 0;
        
        //[0,0,1,1,1,2,2]
        int write = 1; // first num is always unique 
        for(int i = 1; i < nums.length; i++){
            if(nums[i] != nums[write-1]){
                nums[write] = nums[i];
                write++;
            }
        }
        
        return write;        
    }
}
