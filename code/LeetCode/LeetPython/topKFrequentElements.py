'''
https://leetcode.com/problems/top-k-frequent-elements/

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]

Input: nums = [1], k = 1
Output: [1]

Accepted
'''

# class Solution:
#     def topKFrequent(self, nums: List[int], k: int) -> List[int]:

import heapq


class Solution:
    def topKFrequent(self, nums, k):
        hashMap = {}
        for num in nums:
            if num in hashMap:
                hashMap[num] += 1
            else:
                hashMap[num] = 1

        heap = []
        for key, value in hashMap.items():
            heapq.heappush(heap, (-value, key))

        result = []
        for i in range(k):
            result.append(heapq.heappop(heap)[1])

        return result


nums1 = [1, 1, 1, 2, 2, 3]
k1 = 2
ref = Solution()
print(ref.topKFrequent(nums1, k1))
