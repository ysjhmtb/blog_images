>781. [Rabbits in Forest](https://leetcode.com/problems/rabbits-in-forest/description/)
>
>In a forest, each rabbit has some color. Some subset of rabbits (possibly all of them) tell you how many other rabbits have the same color as them. Those `answers` are placed in an array.
>
>Return the minimum number of rabbits that could be in the forest.
>
>```
>Examples:
>Input: answers = [1, 1, 2]
>Output: 5
>Explanation:
>The two rabbits that answered "1" could both be the same color, say red.
>The rabbit than answered "2" can't be red or the answers would be inconsistent.
>Say the rabbit that answered "2" was blue.
>Then there should be 2 other blue rabbits in the forest that didn't answer into the array.
>The smallest possible number of rabbits in the forest is therefore 5: 3 that answered plus 2 that didn't.
>
>Input: answers = [10, 10, 10]
>Output: 11
>
>Input: answers = []
>Output: 0
>```
>
>**Note:**
>
>1. `answers` will have length at most `1000`.
>2. Each `answers[i]` will be an integer in the range `[0, 999]`.
>
>

<br>

<hr>

[My easy Java HashMap solution](https://leetcode.com/problems/rabbits-in-forest/discuss/114719/My-easy-Java-HashMap-solution) 의 알고리즘을 통해 학습. 이번에 다시 한번 느낀 점은 **for statement and reductionism** 이다.



```java
public class HelloWorld {

    public static void main(String[] args) {
        Solution ref = new Solution();
        System.out.println(ref.numRabbits(new int[]{1, 1, 2}));       // 5
        System.out.println(ref.numRabbits(new int[]{10, 10, 10}));    // 11


    }
}
/*
for statement and reductionism


group = mag.get(n) / (n+1) = 2 / 2 = 1
res += map.get(n) % (n+1) = 2 % 2 = 0   -> group * (n+1) = 1 * 2 = 2

group = 1 / 3 = 0
res += 1 % 3 = 1 -> 1 * 3 = 3

res 5
 */

class Solution {

    public int numRabbits(int[] answers) {
        int res = 0;
        Map<Integer, Integer> map = new HashMap<>();
        for (int answer : answers) {
            map.put(answer, map.getOrDefault(answer, 0) + 1);
        }


        for (Integer n : map.keySet()) {
            int group = map.get(n) / (n + 1);
            res += map.get(n) % (n + 1) != 0 ? (group + 1) * (n + 1) : group * (n + 1);
        }
        return res;
    }



}
```











































