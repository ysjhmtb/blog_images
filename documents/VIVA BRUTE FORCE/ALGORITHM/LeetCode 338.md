> 338. [Counting Bits](https://leetcode.com/problems/counting-bits/description/)
>
> Given a non negative integer number **num**. For every numbers **i** in the range **0 ≤ i ≤ num** calculate the number of 1's in their binary representation and return them as an array.
>
> **Example:**
> For `num = 5` you should return `[0,1,1,2,1,2]`.
>
> **Follow up:**
>
> - It is very easy to come up with a solution with run time **O(n\*sizeof(integer))**. But can you do it in linear time **O(n)** /possibly in a single pass?
> - Space complexity should be **O(n)**.
> - Can you do it like a boss? Do it without using any builtin function like **__builtin_popcount** in c++ or in any other language.
>
> **Credits:**
> Special thanks to [@ syedee ](https://leetcode.com/discuss/user/syedee)for adding this problem and creating all test cases.

<br>

[Three-Line Java Solution](https://leetcode.com/problems/counting-bits/discuss/79539/Three-Line-Java-Solution) 알고리즘을 학습.

```java
public class HelloWorld {

    public static void main(String[] args) {
        Solution ref = new Solution();

        // 0 000 / 1 001 / 2 010 / 3 011 / 4 100 / 5 101
        // [0,1,1,2,1,2]
        System.out.println(3 >> 1);
        System.out.println(3 & 1);


    }
}

class Solution {

    //An easy recurrence for this problem is f[i] = f[i / 2] + i % 2.
    public int[] countBits(int num) {
        int[] f = new int[num + 1];
        for (int i = 1; i <= num; i++)
            // 3 = 11b
            // f[1b] + 1b = 1b + 1b = 10b = 2
            f[i] = f[i >> 1] + (i & 1);
        return f;
    }

}
```

