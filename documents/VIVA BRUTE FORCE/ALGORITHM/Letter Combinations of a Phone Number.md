```C++
/*

 Letter Combinations of a Phone Number
 
https://leetcode.com/problems/letter-combinations-of-a-phone-number/

2   abc
3   def
4   ghi
5   jkl
6   mno
7   pqrs
8   tuv
9   wxyz

Input: "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].

*/

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    void stringIntoResult(vector<string> &result, string input) {
        if (result.size() == 0) {
            for (unsigned i = 0; i < input.size(); i++) {
                string s = "";
                s.push_back(input.at(i));
                result.push_back(s);
            }
        } else {
            vector<string> temp;

            for (unsigned i = 0; i < result.size(); i++) {
                string s = result.at(i);

                for (unsigned j = 0; j < input.size(); j++) {
//                    s.push_back(input.at(j));
                    temp.push_back(s + input.at(j));
                }
            }

            result = temp;
        }
    }

    vector<string> letterCombinations(string digits) {

        map<int, string> key;
        key.insert(make_pair(2, "abc"));
        key.insert(make_pair(3, "def"));
        key.insert(make_pair(4, "ghi"));
        key.insert(make_pair(5, "jkl"));
        key.insert(make_pair(6, "mno"));
        key.insert(make_pair(7, "pqrs"));
        key.insert(make_pair(8, "tuv"));
        key.insert(make_pair(9, "wxyz"));

        vector<string> result;


        vector<int> input;
        for (unsigned i = 0; i < digits.size(); i++) {

            input.push_back(digits.at(i) - '0');
        }

        for (unsigned i = 0; i < input.size(); i++) {
            int temp = input.at(i);
            this->stringIntoResult(result, key.at(temp));
        }

        for (unsigned i = 0; i < result.size(); i++) {

            cout << result.at(i) << " " << endl;
        }

        return result;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;

    Solution ref;
    ref.letterCombinations("23");

    return 0;
}
```

