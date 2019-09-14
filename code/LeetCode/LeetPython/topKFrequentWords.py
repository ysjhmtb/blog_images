'''
https://leetcode.com/problems/top-k-frequent-words/

Input: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
Output: ["i", "love"]

Input: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k = 4
Output: ["the", "is", "sunny", "day"]

Try to solve it in O(n log k) time and O(n) extra space.

Accepted
'''

# class Solution:
#     def topKFrequent(self, words: List[str], k: int) -> List[str]:
import heapq


class Solution:
    def topKFrequent(self, words, k):

        wordDict = {}
        for word in words:
            if word in wordDict:
                wordDict[word] += 1
            else:
                wordDict[word] = 1

        heap = []
        for key, value in wordDict.items():
            heapq.heappush(heap, (-value, key))

        result = []
        for i in range(k):
            result.append(heapq.heappop(heap)[1])

        return result


words = ["i", "love", "leetcode", "i", "love", "coding"]
k = 2

ref = Solution()
print(ref.topKFrequent(words, k))
