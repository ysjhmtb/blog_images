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




/*
https://leetcode.com/problems/longest-palindromic-substring/discuss/3060/(AC)-relatively-short-and-very-clear-Java-solution

Key idea, every time we move to right, we only need to consider whether using this new character
as tail could produce new palindrome string of length (current length +1) or (current length +2)

babad
Second  i: 0, currLength: 0, i - currLength: 0, res: b
First  i: 2, currLength: 1, i - currLength - 1: 0, res: bab
bab

cbbd
Second  i: 0, currLength: 0, i - currLength: 0, res: c
Second  i: 2, currLength: 1, i - currLength: 1, res: bb
bb

abb
Second  i: 0, currLength: 0, i - currLength: 0, res: a
Second  i: 2, currLength: 1, i - currLength: 1, res: bb
bb

다른 코드에서 많이 배움.
 */

public class LongestPalindromicSubstring {

    public String longestPalindrome(String s) {
        System.out.println(s);
        String res = "";
        int currLength = 0;
        for (int i = 0; i < s.length(); i++) {
            if (isPalindrome(s, i - currLength - 1, i)) {
                System.out.println("First  i: " + i + ", currLength: " + currLength
                        + ", i - currLength - 1: " + (i - currLength - 1)
                        + ", res: " + s.substring(i - currLength - 1, i + 1));
                res = s.substring(i - currLength - 1, i + 1);
                currLength = currLength + 2;

            } else if (isPalindrome(s, i - currLength, i)) {
                System.out.println("Second  i: " + i + ", currLength: " + currLength
                        + ", i - currLength: " + (i - currLength)
                        + ", res: " + s.substring(i - currLength, i + 1));
                res = s.substring(i - currLength, i + 1);
                currLength = currLength + 1;
            }
        }
        return res;
    }

    public boolean isPalindrome(String s, int begin, int end) {
        if (begin < 0) return false;
        while (begin < end) {
            if (s.charAt(begin++) != s.charAt(end--)) return false;
        }
        return true;
    }


}


