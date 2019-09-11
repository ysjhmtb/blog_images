'''
https://leetcode.com/problems/top-k-frequent-words/

Input: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
Output: ["i", "love"]

Input: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k = 4
Output: ["the", "is", "sunny", "day"]

Try to solve it in O(n log k) time and O(n) extra space.


Count the frequency of each word, and sort the words with a custom ordering relation
that uses these frequencies. Then take the best k of them.

'''


# class Solution:
#     def topKFrequent(self, words: List[str], k: int) -> List[str]:

class Solution:
    def topKFrequent(self, words, k):
       return