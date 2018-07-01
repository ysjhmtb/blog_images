> 748. [Shortest Completing Word](https://leetcode.com/problems/shortest-completing-word/description/)
>
> Find the minimum length word from a given dictionary `words`, which has all the letters from the string `licensePlate`. Such a word is said to *complete* the given string `licensePlate`
>
> Here, for letters we ignore case. For example, `"P"` on the `licensePlate` still matches `"p"` on the word.
>
> It is guaranteed an answer exists. If there are multiple answers, return the one that occurs first in the array.
>
> The license plate might have the same letter occurring multiple times. For example, given a `licensePlate` of `"PP"`, the word `"pair"` does not complete the `licensePlate`, but the word `"supper"` does.
>
> **Example 1:**
>
> ```
> Input: licensePlate = "1s3 PSt", words = ["step", "steps", "stripe", "stepple"]
> Output: "steps"
> Explanation: The smallest length word that contains the letters "S", "P", "S", and "T".
> Note that the answer is not "step", because the letter "s" must occur in the word twice.
> Also note that we ignored case for the purposes of comparing whether a letter exists in the word.
> ```
>
> **Example 2:**
>
> ```
> Input: licensePlate = "1s3 456", words = ["looks", "pest", "stew", "show"]
> Output: "pest"
> Explanation: There are 3 smallest length words that contains the letters "s".
> We return the one that occurred first.
> ```
>
> **Note:**
>
> 1. `licensePlate` will be a string with length in range `[1, 7]`.
> 2. `licensePlate` will contain digits, spaces, or letters (uppercase or lowercase).
> 3. `words` will have a length in the range `[10, 1000]`.
> 4. Every `words[i]` will consist of lowercase letters, and have length in range `[1, 15]`.
>
>  

<br>

[Java Solution using character Array](https://leetcode.com/problems/shortest-completing-word/discuss/110137/Java-Solution-using-character-Array) 의 알고리즘을 학습.

```java
public class HelloWorld {

    public static void main(String[] args) {
        Solution ref = new Solution();

        String licensePlate = "1s3 PSt";
        String[] words = new String[]{"step", "steps", "stripe", "stepple"};

        System.out.println(ref.shortestCompletingWord(licensePlate, words));

    }
}

class Solution {


    public String shortestCompletingWord(String licensePlate, String[] words) {

        //대소문자 구별을 하지 않기에 모두 소문자로 변환.
        String target = licensePlate.toLowerCase();
        //어떤 소문자가 몇개가 들어있는지 세어야 한다.
        int[] charMap = new int[26];

        // Construct the character map
        //소문자로 변환된 것들 중 어떤 글자가 몇개인지 기록.
        for (int i = 0; i < target.length(); i++) {
            if (Character.isLetter(target.charAt(i)))
                charMap[target.charAt(i) - 'a']++;
        }

        int minLength = Integer.MAX_VALUE;
        String result = null;

        //words는 후보들을 담아놓은 배열. 하나씩 요구되는 글자를 모두 담고 있으면서,
        //길이도 가장 짧은지 확인한다.
        for (int i = 0; i < words.length; i++) {
            String word = words[i].toLowerCase();

            if (matches(word, charMap) && word.length() < minLength) {
                minLength = word.length();
                result = words[i];
            }
        }
        return result;
    }

    private boolean matches(String word, int[] charMap) {
        int[] targetMap = new int[26];

        for (int i = 0; i < word.length(); i++) {
            if (Character.isLetter(word.charAt(i)))
                targetMap[word.charAt(i) - 'a']++;
        }

        for (int i = 0; i < 26; i++) {
            if (charMap[i] != 0 && targetMap[i] < charMap[i])
                return false;
        }
        return true;
    }


}
```



<br>

