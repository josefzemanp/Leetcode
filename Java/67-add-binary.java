// https://leetcode.com/problems/add-binary/submissions/2067124730

class Solution {
    public String addBinary(String a, String b) {
        StringBuilder answer = new StringBuilder();
        int i = a.length() - 1;
        int j = b.length() - 1;
        int k = 0; // carry (1)

        while (i >= 0 || j >= 0 || k != 0) {
            int ai = (i >= 0) ? (a.charAt(i) - '0') : 0;
            int bi = (j >= 0) ? (b.charAt(j) - '0') : 0;
            int s = ai + bi + k;
            int digit = s % 2;
            k = s / 2;

            answer.append(digit);

            i--;
            j--;
        }

        return answer.reverse().toString();
    }
}
