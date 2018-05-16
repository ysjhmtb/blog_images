<br>

> 32. Longest Valid Parentheses
>
> Given a string containing just the characters `'('` and `')'`, find the length of the longest valid (well-formed) parentheses substring.
>
> **Example 1:**
>
> ```
> Input: "(()"
> Output: 2
> Explanation: The longest valid parentheses substring is "()"
> ```
>
> **Example 2:**
>
> ```
> Input: ")()())"
> Output: 4
> Explanation: The longest valid parentheses substring is "()()"
> ```
>
> https://leetcode.com/problems/longest-valid-parentheses/description/

<br>

[Java solution using HashMap](https://leetcode.com/problems/longest-valid-parentheses/discuss/130199/Java-solution-using-HashMap) 에서 배운 다음과 같은 알고리즘.

<br>

```Java
public class HelloWorld {

    public static void main(String[] args) {
        Solution ref = new Solution();
        String input = new String(")()");
        String input1 = new String("(()");
        String input2 = new String(")()())");

        System.out.println(ref.longestValidParentheses(input));
        System.out.println(ref.longestValidParentheses(input1));
        System.out.println(ref.longestValidParentheses(input2));


    }
}

/*
https://leetcode.com/problems/longest-valid-parentheses/discuss/130199/Java-solution-using-HashMap

Imagine you are climbing a mountain, '(' goes up and ')' goes down.
In every trip (start to climb up then come back to the same height)
you can not go lower than your starting point. Find the longest distance
you can go horizontally in one trip.
Map stores the last valid starting point of a certain height.
 */

class Solution {

    public int longestValidParentheses(String s) {
        Map<Integer, Integer> map = new HashMap<>();
        map.put(0, -1);
        int count = 0;
        int max = 0;
        int min = 0;

        for (int i = 0; i < s.length(); i++) {
            char curr = s.charAt(i);

            if (curr == '(') {
                count++;
                map.put(count, i);
            } else {
                count--;

                if (count < min) {
                    map.put(count, i);
                    min = count;

                } else {
                    max = Math.max(max, i - map.get(count));

                }
            }
        }
        return max;

    }
}



/*
)()

i = 0)
curr    )
count   -1
map.put(-1, 0)
min     -1

i = 1)
curr    (
count   0
map.put(0, 1)

i = 2)
curr    )
count   -1
max = Math.max(0, 2 - 0) = 2
 */




```

<br>

"(()" 입력의 경우 다음과 같은 해시 맵을 확인할 수 있다.



|      | count |  i   |
| :--: | :---: | :--: |
| map  |   0   |  -1  |
|      |   1   |  0   |
|      |   2   |  1   |

<br>

그리고 max = 2(i) - 0(map.get(1)) = 2 가 반환되게 된다.

