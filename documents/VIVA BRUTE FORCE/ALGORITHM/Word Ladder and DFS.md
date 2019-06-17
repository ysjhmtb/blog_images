<br>

**Word Ladder** 를 다음과 같이 DFS로 해결하려 했으나, **Time Limit Exceeded** 로 모든 테스트 케이스 통과에 실패. BFS로 다시 풀 생각임.

<br>

```C++
#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

/*
 https://leetcode.com/problems/word-ladder/

 Word Ladder
 */

class Solution {

private:
    bool isAdjacent(string a, string b) {

        int count = 0;
        for (unsigned i = 0; i < a.size(); i++) {
            if (a.at(i) != b.at(i))
                count++;
        }
        return count == 1 ? true : false;
    }

    void
    helper(int &result, int count, map<string, bool> isVisited, string cur, string endWord, vector<string> &wordList) {

        cout << count << endl;

        if (cur == endWord) {
            if (result == 0)
                result = count;
            else
                result = min(result, count);
        }

        for (unsigned i = 0; i < wordList.size(); i++) {
            if (!isVisited[wordList.at(i)] && this->isAdjacent(cur, wordList.at(i))) {
                isVisited[wordList.at(i)] = true;
                this->helper(result, count + 1, isVisited, wordList.at(i), endWord, wordList);
            }
        }
    }

public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList) {


        int result = 0;
        map<string, bool> isVisited;
        for (unsigned i = 0; i < wordList.size(); i++) {
            isVisited[wordList.at(i)] = false;
        }
        this->helper(result, 1, isVisited, beginWord, endWord, wordList);
        return result;
    }
};


int main() {

    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};

    Solution ref;
    cout << ref.ladderLength(beginWord, endWord, wordList) << endl;

    string beginWord2 = "qa";
    string endWord2 = "sq";
    vector<string> wordList2 = {"si", "go", "se", "cm", "so", "ph", "mt", "db", "mb", "sb", "kr", "ln", "tm", "le",
                                "av", "sm", "ar", "ci", "ca", "br", "ti", "ba", "to", "ra", "fa", "yo", "ow", "sn",
                                "ya", "cr", "po", "fe", "ho", "ma", "re", "or", "rn", "au", "ur", "rh", "sr", "tc",
                                "lt", "lo", "as", "fr", "nb", "yb", "if", "pb", "ge", "th", "pm", "rb", "sh", "co",
                                "ga", "li", "ha", "hz", "no", "bi", "di", "hi", "qa", "pi", "os", "uh", "wm", "an",
                                "me", "mo", "na", "la", "st", "er", "sc", "ne", "mn", "mi", "am", "ex", "pt", "io",
                                "be", "fm", "ta", "tb", "ni", "mr", "pa", "he", "lr", "sq", "ye"};

    cout << ref.ladderLength(beginWord2, endWord2, wordList2) << endl;

    return 0;


}

```

