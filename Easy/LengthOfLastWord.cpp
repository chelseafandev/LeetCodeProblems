/*
Given a string s consists of some words separated by spaces, return the length of the last word in the string. 
If the last word does not exist, return 0.

A word is a maximal substring consisting of non-space characters only.


Example 1:

Input: s = "Hello World"
Output: 5

Example 2:

Input: s = " "
Output: 0
 

Constraints:

1 <= s.length <= 10^4
s consists of only English letters and spaces ' '.
*/
#include <iostream>

class Solution
{
public:
    int lengthOfLastWord(std::string s)
    {
        if (s.length() == 1 && s.compare(" ") == 0)
        {
            return 0;
        }

        int nRet = 0;

        std::string::reverse_iterator ritr = s.rbegin();
        while (ritr != s.rend())
        {
            if (*ritr == ' ')
            {
                // input이 "a "와 같이 마지막이 문자열인 경우 예외 처리
                if (nRet == 0)
                {
                    ritr++;
                    continue;
                }
                else
                {
                    break;
                }
            }
            else
            {
                nRet++;
            }

            ritr++;
        }

        return nRet;
    }
};

int main()
{
    std::string input = "Hello ";
    Solution s;
    std::cout << s.lengthOfLastWord(input) << std::endl;
    return 0;
}