> 665. [Non-decreasing Array](https://leetcode.com/problems/non-decreasing-array/description/)
>
> Given an array with `n` integers, your task is to check if it could become non-decreasing by modifying **at most** `1`element.
>
> We define an array is non-decreasing if `array[i] <= array[i + 1]` holds for every `i` (1 <= i < n).
>
> **Example 1:**
>
> ```
> Input: [4,2,3]
> Output: True
> Explanation: You could modify the first 4 to 1 to get a non-decreasing array.
> ```
>
> **Example 2:**
>
> ```
> Input: [4,2,1]
> Output: False
> Explanation: You can't get a non-decreasing array by modify at most one element.
> ```
>
> **Note:** The `n` belongs to [1, 10,000].

<br>

[[Java/C++] Simple greedy like solution with explanation](https://leetcode.com/problems/non-decreasing-array/discuss/106826/JavaC++-Simple-greedy-like-solution-with-explanation) 의 알고리즘을 학습.

<br>

```java
public class HelloWorld {

    public static void main(String[] args) {
        Solution ref = new Solution();

        // false
        System.out.println(ref.checkPossibility(new int[]{1,2,3,5,4,3}));

        //true
        System.out.println(ref.checkPossibility(new int[]{4, 2, 3}));

        //false
        System.out.println(ref.checkPossibility(new int[]{4, 2, 1}));




    }
}


class Solution {

    public boolean checkPossibility(int[] nums) {
        int cnt = 0;                                            //the number of changes
        for (int i = 1; i < nums.length && cnt <= 1; i++) {
            if (nums[i - 1] > nums[i]) {

                //이 부분이 실행됐다는 것은 나의 앞 부분이 나보다 크다는 것. 카운트 하나 증가.
                cnt++;

                //
                if (i - 2 < 0 || nums[i - 2] <= nums[i]){
                    // i - 2 < 0 이라면 : 감소하는 부분은 분명 존재하는데 나의 인덱스가 1인 상황.
                    // 변경 가능한 부분은 인덱스가 0인 부분뿐.

                    // nums[i - 2] <= nums[i] 라면 : 내가 i-2 보다는 큰데 바로 앞 부분보다만 작은 상황.
                    // 바로 앞부분만 변경하면 된다.
                    nums[i - 1] = nums[i];                      //modify nums[i-1] of a priority
                } else{

                    // 내가 앞부분뿐만 아니라 그 앞보다도 작은 상황.
                    nums[i] = nums[i - 1];                      //have to modify nums[i]
                }

            }

        }
        return cnt <= 1;
    }


}

```

