```C++
#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <queue>

using namespace std;

/*
 https://leetcode.com/problems/word-ladder/

 Word Ladder
 */



class Solution {

public:
    string makeSub(string raw, int start, int end) {
        if (start >= raw.size())
            return raw.substr(start - 1, end - start);
        else
            return raw.substr(start, end - start);
    }

    int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
        map<string, vector<string>> dic;
        map<string, bool> visited;
        queue<pair<string, int>> wordQueue;

        for (string word : wordList) {
            for (unsigned i = 0; i < beginWord.length(); i++) {
                string key = this->makeSub(word, 0, i) + "*" + this->makeSub(word, i + 1, beginWord.length());
                dic[key].push_back(word);
            }
        }

        wordQueue.push(make_pair(beginWord, 1));
        visited[beginWord] = true;

        while (!wordQueue.empty()) {
            pair<string, int> element = wordQueue.front();
            wordQueue.pop();
            if (element.first == endWord)
                return element.second;

            for (unsigned i = 0; i < element.first.length(); i++) {
                string candi = this->makeSub(element.first, 0, i) + "*" +
                               this->makeSub(element.first, i + 1, beginWord.length());

                for (string line:dic[candi]) {
                    if (!visited[line]) {
                        visited[line] = true;
                        wordQueue.push(make_pair(line, element.second + 1));
                    }
                }

            }
        }
        return 0;
    }
};


int main() {

    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};

    Solution ref;
    cout << ref.ladderLength(beginWord, endWord, wordList) << endl;

    return 0;
}
```

