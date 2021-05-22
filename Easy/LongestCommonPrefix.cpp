/*
Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "".


Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"

Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
 

Constraints:

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lower-case English letters.
*/
#include <iostream>
#include <vector>

class Solution
{
public:
    std::string longestCommonPrefix(std::vector<std::string> &strs)
    {
        int inputLen = strs.size();
        std::vector<char> vecPrefix;
        std::vector<char> vecCandidate;
        std::vector<std::string>::iterator itr;
        int idx = 0;
        while (1)
        {
            for (itr = strs.begin(); itr != strs.end(); itr++)
            {
                if ((*itr).length() == 0)
                {
                    break;
                }

                // idx 체크
                if (idx > (*itr).length() - 1)
                {
                    break;
                }

                if (vecCandidate.empty())
                {
                    // tmp가 비어있는 경우
                    vecCandidate.push_back((*itr).at(idx));
                }
                else
                {
                    if (vecCandidate.at(0) == (*itr).at(idx))
                    {
                        vecCandidate.push_back((*itr).at(idx));
                    }
                }
            }

            if (vecCandidate.size() == inputLen)
            {
                vecPrefix.push_back(vecCandidate.at(0));
                vecCandidate.clear();
                idx++;
            }
            else
            {
                break;
            }
        }

        if (vecPrefix.size() == 0)
        {
            return "";
        }
        else
        {
            std::string retStr = "";
            std::vector<char>::iterator itr;
            for (itr = vecPrefix.begin(); itr != vecPrefix.end(); itr++)
            {
                retStr += (*itr);
            }

            return retStr;
        }
    }
};

int main()
{
    std::vector<std::string> strs = {"flower", "flow", "flight"};
    Solution s;
    std::cout << s.longestCommonPrefix(strs) << std::endl;
    return 0;
}