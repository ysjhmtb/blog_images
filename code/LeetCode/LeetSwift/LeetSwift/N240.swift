/*
https://leetcode.com/problems/search-a-2d-matrix-ii/

Example:

Consider the following matrix:

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]
Given target = 5, return true.

Given target = 20, return false.
*/


import Foundation

class N240 {
    func searchMatrix(_ matrix: [[Int]], _ target: Int) -> Bool {
        if matrix.count == 0 || matrix[0].count == 0 {
            return false
        }
        let rows = matrix.count
        let cols = matrix[0].count
        var row = 0
        var col = cols - 1
        while (row < rows && col >= 0) {
            if target < matrix[row][col] {
                col -= 1
            } else if target > matrix[row][col] {
                row += 1
            } else {
                return true
            }
        }
        return false
    }
}