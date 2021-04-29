/*
Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Clarification:

What should we return when needle is an empty string? This is a great question to ask during an interview.
For the purpose of this problem, we will return 0 when needle is an empty string. 
This is consistent to C's strstr() and Java's indexOf().

 

Example 1:

Input: haystack = "hello", needle = "ll"
Output: 2

Example 2:

Input: haystack = "aaaaa", needle = "bba"
Output: -1

Example 3:

Input: haystack = "", needle = ""
Output: 0
 

Constraints:

0 <= haystack.length, needle.length <= 5 * 10^4
haystack and needle consist of only lower-case English characters.
*/
#include <iostream>

class Solution
{
public:
    int strStr(std::string haystack, std::string needle)
    {
        int nRet = -1;

        int haystackSize = haystack.length();
        int needleSize = needle.length();

        if (needleSize == 0)
        {
            return 0;
        }

        if (haystackSize < needleSize)
        {
            return -1;
        }

        for (int i = 0; i <= haystackSize - needleSize; i++)
        {
            int idx = i;
            std::string::iterator itr = needle.begin();
            while (haystack.at(idx) == *itr)
            {
                if (itr == needle.end() - 1)
                {
                    nRet = i;
                    return nRet;
                }

                idx++;
                itr++;
            }
        }

        return nRet;
    }
};

int main()
{
    std::string haystack = "hello";
    std::string needle = "ll";
    Solution s;
    std::cout << s.strStr(haystack, needle) << std::endl;
    return 0;
}