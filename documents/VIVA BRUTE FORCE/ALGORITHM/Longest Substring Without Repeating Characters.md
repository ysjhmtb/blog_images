```C++
#include <iostream>
#include <set>

using namespace std;

/*
 Longest Substring Without Repeating Characters
 
 https://leetcode.com/problems/longest-substring-without-repeating-characters/

 Input: "abcabcbb"
 Output: 3

 Input: "bbbbb"
 Output: 1

 Input: "pwwkew"
 Output: 3
 */

class Solution {

public:

    bool hasIt(set<char> &charset, char &ch) {
        set<char>::iterator itr;
        itr = charset.find(ch);
        if (itr == charset.end()) {
            return true;
        } else {
            return false;
        }
    }

    int lengthOfLongestSubstring(string s) {

        set<char> charset;
        int i = 0, j = 0, result = 0;
        int slen = s.length();


        while (i < slen && j < slen) {
            if (this->hasIt(charset, s.at(j))) {
                charset.insert(s.at(j++));
                result = max(result, j - i);
            } else {
                charset.erase(s.at(i++));
            }
        }

        return result;
    }
};

int main() {

    Solution ref;
    cout << ref.lengthOfLongestSubstring("abcabcbb") << endl;
    cout << ref.lengthOfLongestSubstring("bbbbb") << endl;
    cout << ref.lengthOfLongestSubstring("pwwkew") << endl;

    return 0;
}
```

