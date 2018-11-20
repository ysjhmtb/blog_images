```javascript
/*
https://leetcode.com/problems/top-k-frequent-elements/description/

Top K Frequent Elements


Given a non-empty array of integers, return the k most frequent elements.


Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]


Example 2:

Input: nums = [1], k = 1
Output: [1]


Note:

You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
*/





const topKFrequent = function(nums, k) {
    let myMap = new Map();

    for(let i = 0; i < nums.length; i++){
        if(myMap.has(nums[i])){
            myMap.set(nums[i], myMap.get(nums[i]) + 1 );
        }else{
            myMap.set(nums[i], 1);
        }
    }

    // Map { 1 => 3, 2 => 2, 3 => 1 }
    console.log(myMap);

    let res = [];
    for(let i = 0; i <= nums.length; i++){
        res.push([]);
    }

    // [ [], [], [], [], [], [], [] ]
    console.log(res);

    for( let [key, value] of myMap.entries()){
        res[value].push(key);  
    }

    // [ [], [ 3 ], [ 2 ], [ 1 ], [], [], [] ]
    console.log(res);

    let lastRes = [];
    for(let i = nums.length; i >= 0 && lastRes.length < k; i--){

        if(res[i].length > 0){
            lastRes.push(res[i]);   
        }

    }

    // [ [ 1 ], [ 2 ] ]
    console.log(lastRes);

    let lastRes2 = lastRes;
    lastRes = [];

    for(let i = 0; i < lastRes2.length; i++){
        for(let j = 0; j < lastRes2[i].length && lastRes.length < k; j++){
            lastRes.push(lastRes2[i][j]);
        }
    }

    // [ 1, 2 ]
    console.log(lastRes);

    return lastRes;

};

console.log(topKFrequent([1,1,1,2,2,3], 2));
console.log(topKFrequent([1], 1));
console.log(topKFrequent([1,2], 2));
console.log(topKFrequent([4,1,-1,2,-1,2,3], 2));
```

