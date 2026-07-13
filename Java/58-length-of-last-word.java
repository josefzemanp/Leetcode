// https://leetcode.com/problems/length-of-last-word/submissions/2066318894

class Solution {
    public int lengthOfLastWord(String s) {
        int i = s.length() - 1;
        while (s.charAt(i) == ' ') {
            i--;
        }

        int answer = 0;
        while (i >= 0 && s.charAt(i) != ' ') {
            answer++;
            i--;
        }

        return answer;
    }
}
