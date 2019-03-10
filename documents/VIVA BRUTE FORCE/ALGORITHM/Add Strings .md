```python

'''

https://leetcode.com/problems/add-strings/description/


    2 9
  1 2 3
  1 5 2



    9 7 3
    5 9 7
  1 5 7 0
'''


class Solution:

    def getMaxSize(self, str1, str2):
        a = list(str1)
        b = list(str2)
        return max(len(str1), len(str2))

    def listMaker(self, size):
        return [0] * size

    def getStrList(self, str, neededLen):
        strList = self.listMaker(neededLen - 1)
        start = len(strList) - len(str)
        temp = list(str)

        j = 0
        for i in range(start, len(strList)):
            strList[i] += int(temp[j])
            j += 1

        return strList

    def addStrings(self, num1, num2):

        neededLen = self.getMaxSize(num1, num2) + 1
        resList = self.listMaker(neededLen)

        num1L = self.getStrList(num1, neededLen)
        num2L = self.getStrList(num2, neededLen)

        fromEnd = len(num1L) - 1

        carry = 0
        rli = len(resList) - 1
        while fromEnd >= 0:
            temp = num1L[fromEnd] + num2L[fromEnd] + carry

            if temp > 9:
                carry = temp // 10
                remainder = temp % 10
                resList[rli] = remainder
                fromEnd -= 1
                rli -= 1

            else:
                resList[rli] = temp
                carry = 0
                fromEnd -= 1
                rli -= 1

        resList[0] = carry
        

        result = ""
        for i in range(len(resList)):
            if i == 0 and resList[0] == 0:
                continue
            result += str(resList[i])

        return result


ref = Solution()
print(ref.addStrings("29", "123"))
print(ref.addStrings("973","597"))

```

