```C++
#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

/*
 https://leetcode.com/problems/group-anagrams/

 Group Anagrams

 Example:

Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]

 */

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {

        if (strs.size() == 0) {
            vector<vector<string>> null_vec;
            return null_vec;
        }

        // https://bit.ly/2ZkQv1h
        map<string, vector<string> > ansMap;
        for (string each : strs) {
            vector<char> temp_char;
            for (unsigned i = 0; i < each.size(); i++) {
                temp_char.push_back(each.at(i));
            }
            sort(temp_char.begin(), temp_char.end());

            string temp_str(temp_char.begin(), temp_char.end());
            if (!ansMap.count(temp_str)) {
                ansMap[temp_str] = vector<string>{};
                ansMap[temp_str].push_back(each);
            } else {
                ansMap[temp_str].push_back(each);
            }
        }

        vector<vector<string> > ans;
        map<string, vector<string> >::iterator itr;
        for (itr = ansMap.begin(); itr != ansMap.end(); itr++) {
            ans.push_back(itr->second);
        }

        return ans;
    }
};


int main() {

    Solution ref;

    vector<string> input = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string> > output = ref.groupAnagrams(input);

    return 0;
}
```

