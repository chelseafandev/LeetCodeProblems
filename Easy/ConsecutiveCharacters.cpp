/*
The power of the string is the maximum length of a non-empty substring that contains only one unique character.

Given a string s, return the power of s.



Example 1:

Input: s = "leetcode"
Output: 2
Explanation: The substring "ee" is of length 2 with the character 'e' only.
Example 2:

Input: s = "abbcccddddeeeeedcba"
Output: 5
Explanation: The substring "eeeee" is of length 5 with the character 'e' only.


Constraints:

1 <= s.length <= 500
s consists of only lowercase English letters.
*/

#include <iostream>

class Solution
{
public:
    int maxPower(std::string s)
    {
        if (s.length() == 1)
        {
            return 1;
        }

        int max_power = 0;
        int repeat_count = 1;
        std::string::iterator prev = s.begin();
        for (auto cur = s.begin() + 1; cur != s.end(); cur++)
        {
            if (*cur == *prev)
            {
                repeat_count++;
            }
            else
            {
                repeat_count = 1;
            }

            // upate max_power
            if (repeat_count > max_power)
            {
                max_power = repeat_count;
            }

            // update prev
            prev = cur;
        }
        
        return max_power;
    }
};

int main()
{
    std::string input = "abbcccddddeeeeedcba";
    Solution s;
    std::cout << s.maxPower(input) << std::endl;
    return 0;
}
