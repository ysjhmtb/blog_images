'''
https://leetcode.com/problems/k-closest-points-to-origin/

Input: points = [[1,3],[-2,2]], K = 1
Output: [[-2,2]]

Input: points = [[3,3],[5,-1],[-2,4]], K = 2
Output: [[3,3],[-2,4]]



Accepted
'''

# class Solution:
#     def kClosest(self, points: List[List[int]], K: int) -> List[List[int]]:
import math
from queue import PriorityQueue


class Solution:
    def getDistance(self, point):
        return math.sqrt(math.pow(point[0], 2) + math.pow(point[1], 2))

    def kClosest(self, points, K):
        queue = PriorityQueue()

        for point in points:
            distance = self.getDistance(point)
            queue.put((distance, point))

        results = []
        for i in range(K):
            results.append(queue.get()[1])

        return results


points1 = [[1, 3], [-2, 2]]
K1 = 1

points2 = [[3, 3], [5, -1], [-2, 4]]
K2 = 2

ref = Solution()
print(ref.kClosest(points1, K1))
print(ref.kClosest(points2, K2))
