/*
https://leetcode.com/problems/fraction-to-recurring-decimal/

Example 1:
Input: numerator = 1, denominator = 2
Output: "0.5"

Example 2:
Input: numerator = 2, denominator = 1
Output: "2"

Example 3:
Input: numerator = 2, denominator = 3
Output: "0.(6)"
*/

import Foundation

class N166 {
    func fractionToDecimal(_ numerator: Int, _ denominator: Int) -> String {
        var negative = false
        if numerator > 0 && denominator < 0 || numerator < 0 && denominator > 0 {
            negative = true
        }
        var numer = abs(numerator)
        var deno = abs(denominator)
        var res = "\(numer / deno)"
        if negative {
            res = "-" + res
        }
        var remain = numer % deno
        if remain == 0 {
            return res
        }
        var map = [Int: Int]()
        res += "."

        while (remain != 0) {
            if map[remain] != nil {
                var index = map[remain]!
                var firstIndex = res.index(res.startIndex, offsetBy: index)
                res = res[..<firstIndex] + "(" + res[firstIndex...] + ")"
                return res
            } else {
                map[remain] = res.count
            }
            remain = remain * 10
            res = res + "\(remain / deno)"
            remain = remain % deno
        }
        return res
    }
}