/*
https://leetcode.com/problems/happy-number/

Example:

Input: 19
Output: true
Explanation:
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1

Accepted
*/

import Foundation

class N202 {
    func isHappy(_ n: Int) -> Bool {
        var sum = n
        var seen = Set<Int>()
        while sum > 1{
            if seen.contains(sum){
                return false
            }
            seen.insert(sum)
            sum = getNext(sum)
        }
        return true
    }

    func getNext(_ num: Int) -> Int {
        var sum = 0
        var n = num
        while n > 0 {
            sum = (n % 10) * (n % 10)
            n = n / 10
        }
        return sum
    }
}
