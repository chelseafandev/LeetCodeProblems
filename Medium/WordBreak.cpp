/*
Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.
Note that the same word in the dictionary may be reused multiple times in the segmentation.

Example 1:
Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".

Example 2:
Input: s = "applepenapple", wordDict = ["apple","pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
Note that you are allowed to reuse a dictionary word.

Example 3:
Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
Output: false


Constraints:
1 <= s.length <= 300
1 <= wordDict.length <= 1000
1 <= wordDict[i].length <= 20
s and wordDict[i] consist of only lowercase English letters.
All the strings of wordDict are unique.
*/

#include <iostream>
#include <vector>
#include <set>
#include <stack>

class WordInfo
{
public:
    WordInfo(std::string word, int s, int e) : word_(word), start_idx_(s), end_idx_(e)
    {

    }

    int start_idx_;
    int end_idx_;
    std::string word_;
}

class Solution
{
public:
    bool wordBreak(std::string s, std::vector<std::string> &wordDict)
    {
        // 단어를 찾을때 O(logn)의 시간복잡도를 갖도록 하기위해 set에 저장
        std::set<std::string> words;
        for (const auto& word : wordDict)
        {
            words.insert(word);
        }

        // match된 단어의 마지막 인덱스를 저장해두는 stack
        std::stack<WordInfo> match_index;

        // 최초 match 단어 찾은 후 stack에 push
        bool is_matched = false;
        std::string first = "";
        int start_idx = 0;
        int end_idx = 0;
        for (const auto& character : s)
        {
            first += character;
            if (words.find(first) != words.end())
            {
                is_matched = true;
                break;
            }
            end_idx++;
        }

        if (!is_matched)
        {
            return false;
        }

        WordInfo info(first, start_idx, end_idx);
        match_index.push(info);

        // assemble looping
        // - start_idx와 end_idx는 계속 tracking
        // - first를 찾은 후 남은 문자열 s에서 wordDict에 매칭되는 단어를 찾았으면 stack에 push
        // - 찾지 못한 경우라면 stack의 top값(WordInfo)에서 start_idx 및 end_idx를 조회하여 이어서 assemble
        // - loop 탈출 조건은 다시 한번 생각해보기

        return true;
    }
};

int main()
{
    std::string input = "leetcode";
    std::vector<std::string> wordDict = {"leet", "code"};
    Solution s;
    std::cout << std::boolalpha << s.wordBreak(input, wordDict) << std::endl;
    return 0;
}