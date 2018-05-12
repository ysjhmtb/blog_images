<br>

> 31. Next Permutation
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

<br>

[Simple python code](https://leetcode.com/problems/next-permutation/discuss/119205/Simple-python-code) 를 통해서 다음의 알고리즘을 학습하였다.

<br>

```python
class Solution:

    # 1 1 5
    def nextPermutation(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        # 1. get the start index of non-increasing sequence from tail
        # 2. swap
        # 3. sort the non-increasing
        if not nums:
            return nums

        # l = 3
        l = len(nums)

        # i = 1, j = 2
        i, j = l - 2, l - 1

        while i >= 0 and nums[i] >= nums[i + 1]:
            i -= 1

        while j > i and nums[j] <= nums[i]:
            j -= 1

        # i = 1, j = 2
        nums[i], nums[j] = nums[j], nums[i]

        # 1 5 1
        nums[i + 1:] = sorted(nums[i + 1:])

        # 1 5 1







ref = Solution()
nums = [1, 2, 3]

ref.nextPermutation(nums)  # 1 3 2
print(nums)

nums = [3, 2, 1]
ref.nextPermutation(nums)  # 1 2 3
print(nums)

nums = [1, 1, 5]
ref.nextPermutation(nums)  # 1 5 1
print(nums)

nums = [1,5,3,3,3]
ref.nextPermutation(nums)
print(nums) # 3 1 3 3 5
```



<br>

