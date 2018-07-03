> 462. [Minimum Moves to Equal Array Elements II](https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/description/)
>
> Given a **non-empty** integer array, find the minimum number of moves required to make all array elements equal, where a move is incrementing a selected element by 1 or decrementing a selected element by 1.
>
> You may assume the array's length is at most 10,000.
>
> **Example:**
>
> ```
> Input:
> [1,2,3]
> 
> Output:
> 2
> 
> Explanation:
> Only two moves are needed (remember each move increments or decrements one element):
> 
> [1,2,3]  =>  [2,2,3]  =>  [2,2,2]
> ```

<br>

[Java(just like meeting point problem)]( https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/discuss/94937/Java(just-like-meeting-point-problem) ) 의 알고리즘을 학습.

<br>

```java


public class HelloWorld {

    public static void main(String[] args) {
        Solution ref = new Solution();
        System.out.println(ref.minMoves2(new int[]{1, 2, 3}));


    }
}

class Solution {

    public int minMoves2(int[] nums) {

        //배열이 정렬되어 있지 않으면, count에 음수가 더해질 수 있다.
        Arrays.sort(nums);
        int i = 0, j = nums.length - 1;
        int count = 0;

        while (i < j) {
            count += nums[j] - nums[i];
            i++;
            j--;
        }
        return count;
    }
}


```

