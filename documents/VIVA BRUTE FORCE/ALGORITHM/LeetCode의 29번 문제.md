<br>



> 29. Divide Two Integers
>
> Given two integers `dividend` and `divisor`, divide two integers without using multiplication, division and mod operator.
>
> Return the quotient after dividing `dividend` by `divisor`.
>
> The integer division should truncate toward zero.
>
> **Example 1:**
>
> ```
> Input: dividend = 10, divisor = 3
> Output: 3
> ```
>
> **Example 2:**
>
> ```
> Input: dividend = 7, divisor = -3
> Output: -2
> ```
>
> **Note:**
>
> - Both dividend and divisor will be 32-bit signed integers.
> - The divisor will never be 0.
> - Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 231 − 1 when the division result overflows.
>
> https://leetcode.com/problems/divide-two-integers/description/



<br>

이 문제에 대한 [해법](https://leetcode.com/problems/divide-two-integers/discuss/13403/Clear-python-code)을 참조하여 파이썬 코드로 다음과 같이 학습하였다.

<br>

```python
class Solution(object):
    def divide(self, dividend, divisor):
        positive = (dividend < 0) is (divisor < 0)
        dividend, divisor = abs(dividend), abs(divisor)
        res = 0
        while dividend >= divisor:
            temp, i = divisor, 1
            while dividend >= temp:
                dividend -= temp
                res += i
                i <<= 1
                temp <<= 1
        if not positive:
            res = -res
        return min(max(-2147483648, res), 2147483647)

ref = Solution()
print(ref.divide(10, 3))  # 3
print(ref.divide(7, -3))  # -2
```



<br>

다음은 학습한 내용을 다음과 같이 자바 코드로 작성하였다.   



```java
public class HelloWorld {

    public static void main(String[] args) {
        Solution ref = new Solution();
        System.out.println(ref.divide(10, 3)); // 3
        System.out.println(ref.divide(7, -3)); // -2

    }

}


class Solution {

    public int divide(int dividend, int divisor){

        boolean positive;
        if(dividend * divisor > 0){
            positive = true;
        }else{
            positive = false;
        }

        dividend = Math.abs(dividend);
        divisor = Math.abs(divisor);
        int res = 0;


        while(dividend >= divisor){
            dividend -= divisor;
            res++;
        }

        if(positive == false){
            res = -res;
        }

        return Math.min(Math.max(res, -2147483648), 2147483647);

    }

}
```



<br>

```java
public class HelloWorld {

    public static void main(String[] args) {
        Solution ref = new Solution();
        System.out.println(ref.divide(10, 3)); // 3
        System.out.println(ref.divide(7, -3)); // -2


    }
}


class Solution {
    public int divide(int dividend, int divisor) {
        boolean positive;
        if (dividend * divisor > 0) {
            positive = true;
        } else {
            positive = false;
        }

        dividend = Math.abs(dividend);
        divisor = Math.abs(divisor);
        int res = 0;

        while (dividend >= divisor) {
            int temp = divisor;
            int i = 1;

            while (dividend >= temp) {
                dividend -= temp;
                res += i;

                temp *= 2;
                i *= 2;
            }
        }

        if (positive == false) {
            res = -res;
        }

        return Math.min(Math.max(res, -2147483648), 2147483647);
    }
}
```



<br>



 



