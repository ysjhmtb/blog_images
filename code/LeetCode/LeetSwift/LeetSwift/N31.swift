/*

https://leetcode.com/problems/next-permutation/

1 5 8 (4) 7 6 (5) 3 1
1 5 8  5  7 6  4  3 1
1 5 8  5  1 3  4  6 7
*/

import Foundation

class N31 {
    func nextPermutation(_ nums: inout [Int]) {
        var n = nums.count
        var k = -1
        var l = -1
        for i in (0..<n - 1).reversed() {
            if nums[i] < nums[i + 1] {
                k = i
            }
        }

        if k == -1 {
            nums = nums.reversed()
        } else {
            for j in (0..<n).reversed() {
                if nums[k] < nums[j]{
                    l = j
                }
            }
        }

        nums.swapAt(k, l)
        nums = nums[0 ... k] + nums[k+1 ... n-1].reversed()         
    }
}

/*
class N31 {
    func nextPermutation(_ nums: inout [Int]) {
        var n = nums.count
        var k = -1
        var l = -1
        for i in (0..<n - 1).reversed() {
            if nums[i] < nums[i + 1] {
                k = i
                break
            }
        }
        if k == -1 {
            nums = nums.reversed()
        } else {
            for j in (0..<n).reversed() {
                if nums[j] > nums[k] {
                    l = j
                    break
                }
            }
            nums.swapAt(k, l)
            nums = nums[0...k] + nums[k + 1...nums.count - 1].reversed()
        }
    }
}
*/