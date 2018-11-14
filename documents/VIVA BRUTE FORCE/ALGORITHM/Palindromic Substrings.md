```javascript
/*
https://leetcode.com/problems/palindromic-substrings/description/

Palindromic Substrings

Given a string, your task is to count 
how many palindromic substrings in this string.

The substrings with different start indexes or 
end indexes are counted as different substrings even they consist of same characters.


Example 1:
Input: "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".

Example 2:
Input: "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".

Note:
The input string length won't exceed 1000.

*/

const isPalindrome = function(str){

    let left = 0;
    let right = str.length - 1;
    let flag = true;

    while(left <= right){
        if(str[left] != str[right]){
            flag = false;
            break;
        }
        left++;
        right--;
    }
    return flag;
}


const countSubstrings = function(s) {

    let candidates = [];

    for(let i = 0; i < s.length; i++){
        for(let j = i + 1; j < s.length + 1; j++){
            candidates.push(s.substring(i,j));
        }
    }

    let result = 0;

    for(let i = 0; i < candidates.length; i++){
        if(isPalindrome(candidates[i])){
            result++;
        }
    }

    return result;

};


```

<br>