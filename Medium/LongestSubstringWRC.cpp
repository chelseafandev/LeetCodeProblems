/*
Given a string s, find the length of the longest substring without repeating characters.

 
Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

Example 4:

Input: s = ""
Output: 0
 

Constraints:

0 <= s.length <= 5 * 104
s consists of English letters, digits, symbols and spaces.

*/
#include <iostream>
#include <map>

class Solution
{
public:
    int lengthOfLongestSubstring(std::string s)
    {
        bool bIsExist[128] = {
            false,
        };

        if (s.length() == 1)
        {
            return 1;
        }

        int nMax = 0;
        int nTmpCnt = 0;
        for (int i = 0; i < s.length(); i++)
        {
            std::string::iterator itr;
            for (itr = s.begin() + i; itr != s.end(); itr++)
            {
                // ASCII 범위 밖인 경우
                if (*itr < 0 || *itr > 127)
                {
                    return -1;
                }

                if (bIsExist[*itr] == true)
                {
                    if (nTmpCnt > nMax)
                    {
                        nMax = nTmpCnt;
                    }

                    for (int i = 0; i < 128; i++)
                    {
                        bIsExist[i] = false;
                    }

                    nTmpCnt = 0;
                    break;
                }
                else
                {
                    bIsExist[*itr] = true;
                    nTmpCnt++;

                    if (itr + 1 == s.end())
                    {
                        if (nTmpCnt > nMax)
                        {
                            nMax = nTmpCnt;
                        }
                    }
                }
            }
        }

        return nMax;
    }
};

int main()
{
    std::string input = "dvdf";
    Solution s;
    std::cout << s.lengthOfLongestSubstring(input) << std::endl;
    input = "aab";
    std::cout << s.lengthOfLongestSubstring(input) << std::endl;
    input = "au";
    std::cout << s.lengthOfLongestSubstring(input) << std::endl;
    input = " ";
    std::cout << s.lengthOfLongestSubstring(input) << std::endl;
    input = "pwwkew";
    std::cout << s.lengthOfLongestSubstring(input) << std::endl;
    input = "aaaaa";
    std::cout << s.lengthOfLongestSubstring(input) << std::endl;
    return 0;
}