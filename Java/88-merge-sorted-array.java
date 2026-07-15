// https://leetcode.com/problems/merge-sorted-array/submissions/2068450711

class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int nums1Index = m - 1;
        int nums2Index = n - 1;

        for (int i = m + n - 1; i >= 0; i--) {
            if (nums1Index < 0) {
                nums1[i] = nums2[nums2Index];
                nums2Index--;
                continue;
            }
            if (nums2Index < 0) {
                nums1[i] = nums1[nums1Index];
                nums1Index--;
                continue;
            }

            if (nums1[nums1Index] <= nums2[nums2Index]) {
                nums1[i] = nums2[nums2Index];
                nums2Index--;
            } else {
                nums1[i] = nums1[nums1Index];
                nums1Index--;
            }
        }
    }
}
