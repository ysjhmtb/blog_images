

<br>

> 31. Next Permutation
>
> <br>
>
> Implement **next permutation**, which rearranges numbers into the lexicographically next greater permutation of numbers.
>
> If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
>
> The replacement must be **in-place** and use only constant extra memory.
>
> Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
>
> `1,2,3` → `1,3,2`
> `3,2,1` → `1,2,3`
> `1,1,5` → `1,5,1`
>
> https://leetcode.com/problems/next-permutation/description/



<br>

[Python // 7 lines easy solution with explanation // 48 ms // beats 98 %](https://leetcode.com/problems/next-permutation/discuss/129796/Python-7-lines-easy-solution-with-explanation-48-ms-beats-98) 의 아래 내용을 참조하여 학습하였다.

<br>

```Python
'''
We try to find the rightmost number that has bigger number after itself in the array.
When we find the number we exchange l(eft) and r(ight) numbers and sort the remaining array
after rightmost number index, including l(eft) instead of r(ight) in the remaining array.
If we don't find proper rightmost number, we just sort the array for minimum number.
'''


class Solution:
    def nextPermutation(self, nums):
        perm, l = False, len(nums) - 2
        while 0 <= l:
            r = len(nums) - 1
            while l < r and nums[r] <= nums[l]:
                r -= 1
            if r <= l:
                l -= 1
            else:
                nums[l], nums[l + 1:], perm = \
                    nums[r], sorted(nums[l + 1:r] + [nums[l]] + nums[r + 1:]), True
                break
        if not perm:
            nums.sort()


ref = Solution()
nums = [1,2,3]

ref.nextPermutation(nums) # 1 3 2
print(nums)

nums = [3,2,1]
ref.nextPermutation(nums) # 1 2 3
print(nums)

nums = [1,1,5]
ref.nextPermutation(nums) # 1 5 1
print(nums)
        
```

<br>

이를 바탕으로 다음과 같이 자바 코드를 작성해 보았다.

