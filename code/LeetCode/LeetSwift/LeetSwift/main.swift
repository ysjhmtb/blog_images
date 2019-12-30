//
//  main.swift
//  LeetSwift
//
//  Created by yun on 2019/12/23.
//  Copyright © 2019 yun. All rights reserved.
//

import Foundation

print("Hello, World!")
var ref: N31 = N31()
var nums: [Int] = [1, 5, 8, 4, 7, 6, 5, 3, 1]
ref.nextPermutation(&nums)
print(nums)

