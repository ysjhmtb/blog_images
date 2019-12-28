/*
https://leetcode.com/problems/merge-sorted-array/

Example:

Input:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

Output: [1,2,2,3,5,6]
*/

import Foundation

class N88 {
    func merge(_ nums1: inout [Int], _ m: Int, _ nums2: [Int], _ n: Int) {
        guard nums1.count >= m + n else {
            fatalError("nums1 length is not enough")
        }
        var p1 = 0
        var p2 = 0
        var all = [Int]()

        for _ in 0..<m + n {
            if p1 >= m {
                all.append(contentsOf: Array(nums2[p2...]))
                break
            }
            if p2 >= n {
                all.append(contentsOf: Array(nums1[p1...]))
                break
            }
            if nums1[p1] < nums2[p2] {
                all.append(nums1[p1])
                p1 += 1
            } else {
                all.append(nums2[p2])
                p2 += 1
            }
        }
        nums1 = Array(all[0..<m + n])
    }
}

/*
class N88 {
    func merge(_ nums1: inout [Int], _ m: Int, _ nums2: [Int], _ n: Int) {
        guard nums1.count >= m + n else { fatalError("nums1 length is not enough.") }
        var p1 = 0
        var p2 = 0
        var all = [Int]()
        for _ in 0..<m+n {
            if p1 >= m {
                all.append(contentsOf: Array(nums2[p2...]))
                break
            }
            if p2 >= n {
                all.append(contentsOf: Array(nums1[p1...]))
                break
            }

            if nums1[p1] < nums2[p2] {
                all.append(nums1[p1])
                p1 += 1
            } else {
                all.append(nums2[p2])
                p2 += 1
            }
        }
        nums1 = Array(all[0..<m+n])
    }
}
*/