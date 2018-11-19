

```javascript
/*
https://leetcode.com/problems/product-of-array-except-self/description/

Product of Array Except Self

 Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal 
 to the product of all the elements of nums except nums[i].

Example:

Input:  [1,2,3,4]
Output: [24,12,8,6]

Note: Please solve it without division and in O(n).



1 2 3 4
1 1 2 6
24 12 8 6

*/

const productExceptSelf = function(nums) {
    let res = []

    if(nums.length == 0){
        return;
    }

    let prefix = 1;

    for(let i = 0; i < nums.length; i++){
        res.push(1);
    }

    for(let i = 0; i < nums.length; i++){
        res[i] = prefix;
        prefix *= nums[i];
    }

    // 1 1 2 6

    prefix = 1;

    for(let i = nums.length - 1; i >= 0; i--){
        res[i] *= prefix;
        prefix *= nums[i];
    }

    // 24 12 8 6 

    return res;

};



console.log(productExceptSelf([1,2,3,4]));
```

