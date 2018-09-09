



> [438. Find All Anagrams in a String](https://leetcode.com/problems/find-all-anagrams-in-a-string/description/)    
>
> <br>
>
> Given a string **s** and a **non-empty** string **p**, find all the start indices of **p**'s anagrams in **s**. 
>
> <br>
>
> Strings consists of lowercase English letters only and the length of both strings **s** and **p** will not be larger than 20,100.
>
> <br>
>
> The order of output does not matter.
>
> <br>
>
> **Example 1:**
>
> ```
> Input:
> s: "cbaebabacd" p: "abc"
> 
> Output:
> [0, 6]
> 
> Explanation:
> The substring with start index = 0 is "cba", which is an anagram of "abc".
> The substring with start index = 6 is "bac", which is an anagram of "abc".
> ```
>
> <br>
>
> **Example 2:**
>
> ```
> Input:
> s: "abab" p: "ab"
> 
> Output:
> [0, 1, 2]
> 
> Explanation:
> The substring with start index = 0 is "ab", which is an anagram of "ab".
> The substring with start index = 1 is "ba", which is an anagram of "ab".
> The substring with start index = 2 is "ab", which is an anagram of "ab".
> ```

<br>

<br>





[Java using isAnagram() helper function, easy to understand](https://leetcode.com/problems/find-all-anagrams-in-a-string/discuss/92032/Java-using-isAnagram()-helper-function-easy-to-understand) 의 알고리즘을 학습. 

<br>

```java
public class HelloWorld {

    public static void main(String[] args) {


        Solution ref = new Solution();

        String s1 = "cbaebabacd";
        String p1 = "abc";

        // 0 6
        List<Integer> result = ref.findAnagrams(s1, p1);
        for (int i = 0; i < result.size(); i++) {
            System.out.println(result.get(i));
        }


        String s2 = "abab";
        String p2 = "ab";

        // 0 1 2
        result = ref.findAnagrams(s2, p2);
        for (int i = 0; i < result.size(); i++) {
            System.out.println(result.get(i));
        }


    }

}


class Solution {

    public List<Integer> findAnagrams(String s, String p) {

        List<Integer> res = new ArrayList<>();
        if (p == null || s == null || s.length() < p.length())
            return res;

        int m = s.length(), n = p.length();

        //s = "cbaebabacd", p = "abc" 라면 m = 10, n = 3
        //m - n + 1 = 10 - 3 + 1 = 8
        //결국 i < 8은 i가 7일 때까지만 반복문이 실행된다는 의미.
        //p의 길이를 감안하면 8부터는 탐색할 필요가 없다.
        //
        //현재 지점 i에서 p의 길미만큼을 잘라내서 p와 일치하는지 검사하고
        //일치한다면 현재 지점인 i를 결과에 추가한다. 
        for (int i = 0; i < m - n + 1; i++) {
            String cur = s.substring(i, i + n);

            if (helper(cur, p))
                res.add(i);
        }

        return res;
    }

    public boolean helper(String a, String b) {

        if (a == null || b == null || a.length() != b.length())
            return false;

        int[] dict = new int[26];

        for (int i = 0; i < a.length(); i++) {
            char ch = a.charAt(i);
            dict[ch - 'a']++;
        }

        for (int i = 0; i < b.length(); i++) {
            char ch = b.charAt(i);
            dict[ch - 'a']--;
            if (dict[ch - 'a'] < 0)
                return false;
        }

        return true;
    }

}


```

