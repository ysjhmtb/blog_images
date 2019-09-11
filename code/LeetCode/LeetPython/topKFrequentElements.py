'''
https://leetcode.com/problems/top-k-frequent-elements/

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]

Input: nums = [1], k = 1
Output: [1]




1) The first step is to build a hash map element -> its frequency. O(N)
2) The second step is to build a heap. O(Nlog(k))
3) The last step to build an output list has O(klog(k)) time complexity.
'''


# class Solution:
#     def topKFrequent(self, nums: List[int], k: int) -> List[int]:

class Solution:
    def topKFrequent(self, nums, k):
        return
