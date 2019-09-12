'''
https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/

Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, K = 2
Output: [7,4,1]



Accepted
'''


class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def annotateParents(self, root, parentsDict):
        if root.left != None:
            parentsDict[root.left] = root
            self.annotateParents(root.left, parentsDict)
        if root.right != None:
            parentsDict[root.right] = root
            self.annotateParents(root.right, parentsDict)

    def checkDistance(self, root, K, count, paraentsDict, seen, resultsList):
        seen.add(root)
        if count == K:
            resultsList.append(root.val)
            return

        if root in paraentsDict and not paraentsDict[root] in seen:
            self.checkDistance(
                paraentsDict[root], K, count+1, paraentsDict, seen, resultsList)
        if root.left != None and not root.left in seen:
            self.checkDistance(root.left, K, count+1,
                               paraentsDict, seen, resultsList)
        if root.right != None and not root.right in seen:
            self.checkDistance(root.right, K, count+1,
                               paraentsDict, seen, resultsList)

    def distanceK(self, root, target, K):
        seen = set()
        parentsDict = {}
        resultsList = []

        self.annotateParents(root, parentsDict)
        self.checkDistance(target, K, 0, parentsDict, seen, resultsList)
        return resultsList



n1 = TreeNode(3)
n2 = TreeNode(5)
n3 = TreeNode(1)
n4 = TreeNode(6)
n5 = TreeNode(2)
n6 = TreeNode(0)
n7 = TreeNode(8)
n8 = TreeNode(7)
n9 = TreeNode(4)
n1.left = n2
n1.right = n3
n2.left = n4
n2.right = n5
n3.left = n6
n3.right = n7
n5.left = n8
n5.right = n9

ref = Solution()
print(ref.distanceK(n1, n2, 2))
