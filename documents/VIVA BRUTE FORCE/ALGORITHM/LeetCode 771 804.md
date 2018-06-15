<br>

> 771. [Jewels and Stones](https://leetcode.com/problems/jewels-and-stones/description/)
>
> You're given strings `J` representing the types of stones that are jewels, and `S` representing the stones you have.  Each character in `S` is a type of stone you have.  You want to know how many of the stones you have are also jewels.
>
> The letters in `J` are guaranteed distinct, and all characters in `J` and `S` are letters. Letters are case sensitive, so `"a"` is considered a different type of stone from `"A"`.
>
> **Example 1:**
>
> ```
> Input: J = "aA", S = "aAAbbbb"
> Output: 3
> ```
>
> **Example 2:**
>
> ```
> Input: J = "z", S = "ZZ"
> Output: 0
> ```
>
> **Note:**
>
> - `S` and `J` will consist of letters and have length at most 50.
> - The characters in `J` are distinct.

<br>

[1-liners Python/Java/Ruby](https://leetcode.com/problems/jewels-and-stones/discuss/113574/1-liners-PythonJavaRuby) 의 너무나 간결한 코드를 보고 놀람.

<br>

```java
public class HelloWorld {

    public static void main(String[] args) {
        Solution ref = new Solution();

        // 3
        System.out.println(ref.numJewelsInStones(new String("aA"),new String("aAAbbbb")));

        // 0
        System.out.println(ref.numJewelsInStones(new String("z"),new String("ZZ")));

    }
}


class Solution {
    public int numJewelsInStones(String J, String S){
        return S.replaceAll("[^" + J + "]","").length();
    }
}
```

<br>

<hr>

> 804. Unique Morse Code Words
>
> International Morse Code defines a standard encoding where each letter is mapped to a series of dots and dashes, as follows: `"a"` maps to `".-"`, `"b"` maps to `"-..."`, `"c"` maps to `"-.-."`, and so on.
>
> For convenience, the full table for the 26 letters of the English alphabet is given below:
>
> ```
> [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
> ```
>
> Now, given a list of words, each word can be written as a concatenation of the Morse code of each letter. For example, "cab" can be written as "-.-.-....-", (which is the concatenation "-.-." + "-..." + ".-"). We'll call such a concatenation, the transformation of a word.
>
> Return the number of different transformations among all words we have.
>
> ```
> Example:
> Input: words = ["gin", "zen", "gig", "msg"]
> Output: 2
> Explanation: 
> The transformation of each word is:
> "gin" -> "--...-."
> "zen" -> "--...-."
> "gig" -> "--...--."
> "msg" -> "--...--."
> 
> There are 2 different transformations, "--...-." and "--...--.".
> ```
>
>  
>
> **Note:**
>
> - The length of `words` will be at most `100`.
> - Each `words[i]` will have length in range `[1, 12]`.
> - `words[i]` will only consist of lowercase letters.

<br>

[Easy Java HashSet](https://leetcode.com/problems/unique-morse-code-words/discuss/130490/Easy-Java-HashSet) 의 알고리즘

<br>

```java

public class HelloWorld {

    public static void main(String[] args) {
        Solution ref = new Solution();

        String[] words = new String[]{"gin", "zen", "gig", "msg"};

        // 2
        System.out.println(ref.uniqueMorseRepresentations(words));


    }
}


class Solution {

    public int uniqueMorseRepresentations(String[] words) {
        HashSet<String> hashSet = new HashSet<String>();
        String[] index = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        for(String word : words){
            String mcode = null;

            for(int i = 0; i < word.length(); i++) {
                mcode += index[word.charAt(i) - 'a'];
            }
            hashSet.add(mcode);
        }
        return hashSet.size();
    }

}
```

<br>

<hr>

