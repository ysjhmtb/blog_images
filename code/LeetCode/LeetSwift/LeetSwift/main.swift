//
//  main.swift
//  LeetSwift
//
//  Created by yun on 2019/12/23.
//  Copyright © 2019 yun. All rights reserved.
//

import Foundation

print("Hello, World!")
var ref: N88 = N88()
var nums1: [Int] = [1, 2, 3, 0, 0, 0]
var nums2: [Int] = [2, 5, 6]
print(ref.merge(&nums1, 3, nums2, 3))
