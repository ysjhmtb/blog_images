/*
https://leetcode.com/problems/container-with-most-water/

Input: [1,8,6,2,5,4,8,3,7]
Output: 49
*/

import Foundation

class N11 {
    func maxArea(_ height: [Int]) -> Int {
    var area = 0
    var i = 0
    var j = height.count - 1
    while (i < j) {
        let width = j - i
        var h = 0
        if (height[i] < height[j]) {
            h = height[i]
            i += 1
        } else {
            h = height[j]
            j -= 1
        }
        area = max(area, h * width)
    }
    return area
}
}