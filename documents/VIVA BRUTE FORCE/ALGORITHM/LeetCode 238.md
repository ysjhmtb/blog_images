<br>

> 238. Product of Array Except Self
>
> Given an array `nums` of *n* integers where *n* > 1,  return an array `output` such that `output[i]` is equal to the product of all the elements of `nums` except `nums[i]`.
>
> **Example:**
>
> ```
> Input:  [1,2,3,4]
> Output: [24,12,8,6]
> ```
>
> **Note:** Please solve it **without division** and in O(*n*).
>
> **Follow up:**
> Could you solve it with constant space complexity? (The output array **does not** count as extra space for the purpose of space complexity analysis.)
>
>  https://leetcode.com/problems/product-of-array-except-self/description/

<hr>

[Simple Java solution in O(n) without extra space](https://leetcode.com/problems/product-of-array-except-self/discuss/65622/Simple-Java-solution-in-O(n)-without-extra-space) 의 다음 알고리즘을 학습.

```java
public class HelloWorld {

    public static void main(String[] args) {
        Solution ref = new Solution();

        int[] input = new int[]{1, 2, 3, 4};
        int[] output = ref.productExceptSelf(input);

        for (int i = 0; i < output.length; i++) {
            // 24 12 8 6
            System.out.println(output[i]);
        }


    }
}

class Solution {
    public int[] productExceptSelf(int[] nums) {
        int n = nums.length;
        int[] res = new int[n];
        res[0] = 1;
        for (int i = 1; i < n; i++) {
            // nums[end]의 관점에서 생각해 보면, 왼쪽의 모든 요소들이 곱해진 것이다.
            res[i] = res[i - 1] * nums[i - 1];

        }


        int right = 1;
        for (int i = n - 1; i >= 0; i--) {
            // nums[end]에서는 이미 모든 요소들이 곱해졌으므로 nums[end] * 1로 충분하다.
            // right은 오른쪽 요소들의 누적 곱. 따라서 nums[0]의 관점에서 res[0] * right은
            // 오른쪽 모든 요소들이 곱해진 것이다.
            res[i] *= right;
            right *= nums[i];

        }
        return res;
    }

}

/*
1	1	0	0
1	1	2	0
1	1	2	6

1	1	2	6
1	1	8	6
1	12	8	6
24	12	8	6




nums    {1,2,3,4}
n       4
res     {0,0,0,0}   =>      {1,0,0,0}

i   1)
res[1] = res[0] * nums[0] = 1 * 1 = 1

i   2)
res[2] = res[1] * nums[1] = 1 * 2 = 2

i   3)
res[3] = res[2] * nums[2] = 2 * 3 = 6



res {1,1,2,6}   right   1




i   3)
res[3] = res[3] * 1 = 6 * 1 = 6
right = right * nums[3] = 1 * 4 = 4

i   2)
res[2] = res[2] * 4 = 2 * 4 = 8
right = 4 * nums[2] = 4 * 3 = 12

i   1)
res[1] = res[1] * 12 = 1 * 12 = 12
right = 12 * nums[1] = 24

i   0)
res[0] = res[0] * 24 = 1 * 24 = 24
right = 24 * nums[0] = 25


return res

 */
```

<br>

