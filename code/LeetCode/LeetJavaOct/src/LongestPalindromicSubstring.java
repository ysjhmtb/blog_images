/*
https://leetcode.com/problems/longest-palindromic-substring/

Example 1:
Input: "babad"
Output: "bab"
Note: "aba" is also a valid answer.

Example 2:
Input: "cbbd"
Output: "bb"
 */

// Wrong Answer

import java.util.*;

public class LongestPalindromicSubstring {

    private Map<List<Integer>, Boolean> keyStore;
    private String answer;

    private boolean isPalindrome(String s) {
        int start = 0, end = s.length() - 1;
        if (start > end) return false;

        char[] checkArr = s.toCharArray();
        while (start <= end) {
            if (this.keyStore.containsKey(Arrays.asList(start, end)) && this.keyStore.get(Arrays.asList(start, end))) {
                return true;
            } else if (this.keyStore.containsKey(Arrays.asList(start, end)) && !this.keyStore.get(Arrays.asList(start, end))) {
                return false;
            }

            if (checkArr[start] != checkArr[end]) {
                this.keyStore.put(new ArrayList<>(Arrays.asList(start, end)), false);
                return false;
            }
            this.keyStore.put(Arrays.asList(start, end), true);
            start++;
            end--;
        }
        return true;
    }

    public void recursive(String s, int start, int end) {
        if (start < 0 || s.length() - 1 < end)
            return;
        else if (start == end) {
            if (this.isPalindrome(s.substring(start, start + 1)) && this.answer.length() < s.substring(start, start + 1).length()) {
                this.answer = s.substring(start, start + 1);
            }
        } else if (this.isPalindrome(s.substring(start, end + 1)) && this.answer.length() < s.substring(start, end + 1).length()) {
            this.answer = s.substring(start, end + 1);
        }
        this.recursive(s, start - 1, end + 1);
    }

    public String longestPalindrome(String s) {
        this.keyStore = new HashMap<>();
        this.answer = "";
        for (int i = 0; i <= s.length(); i++) {
            this.recursive(s, i, i);
            this.recursive(s, i - 1, i );
        }
        return answer;
    }
}
