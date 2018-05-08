

>22. Generate Parentheses
>
>
>
>Given n pairs of parentheses, write a function 
>
>to generate all combinations of well-formed parentheses.
>
>For example, given n = 3, a solution set is:
>
>[
>  "((()))",
>  "(()())",
>  "(())()",
>  "()(())",
>  "()()()"
>]
>
>https://leetcode.com/problems/generate-parentheses/description/

  

<br><br>



Mr. Stefan Pochmann 의 다음의 파이썬 코드를 보면서 해법을 배웠다.

<br>

```Python
class Solution(object):
    def generateParenthesis(self, n):
        def generate(p, left, right, parens=[]):
            if left:
                generate(p + '(', left - 1, right)
            if right > left:
                generate(p + ')', left, right - 1)
            if not right:
                parens += p,
            return parens

        return generate('', n, n)


ref = Solution()
print(ref.generateParenthesis(3))
```

<br>



동시에 다음과 같은 유용한 조언도 감사했다.



> StefanPochmann  	[Jul 5, 2015, 6:48 PM](leetcode.com/problems/generate-parentheses/discuss/10096/4-7-lines-Python/10928)
>
> I learned a lot by reading tutorials/docs and by looking at solutions of others at checkio.org (a Python programming site) and by spending a month on Python topics at Stackoverflow. Also, practice practice practice :-)

<br>



학습한 코드에서 **parens += p,** 를 **parens.append(p)** 로 변경해서 사용하는 것이 더 편했다.

즉 아래와 같다.

<br>

```python
class Solution(object):
    def generateParenthesis(self, n):
        def generate(p, left, right, parens=[]):
            if left:
                generate(p + '(', left - 1, right)
            if right > left:
                generate(p + ')', left, right - 1)
            if not right:
                parens.append(p)
            return parens

        return generate('', n, n)


ref = Solution()
print(ref.generateParenthesis(3))
```

<br>

배운 내용을 다음과 같이 자바 코드로 작성해 보았다.

<br>

```java
public class HelloWorld {

    public static void main(String[] args) {
        Solution ref = new Solution();
        List<String> results = ref.generateParenthesis(3);
        System.out.println(results);
    }
}

class Solution {
    public List<String> generateParenthesis(int n) {
        List<String> answer = new ArrayList<>();

        generate("", n, n, answer);
        return answer;
    }

    public void generate(String prefix, int left, int right, List<String> answer) {
        if (left > 0) {
            generate(prefix + "(", left - 1, right, answer);
        }
        if (right > left) {
            generate(prefix + ")", left, right - 1, answer);
        }
        if (right == 0) {
            answer.add(prefix);
        }
    }
}
```



<br>



