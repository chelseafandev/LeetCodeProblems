/*
Given an integer x, return true if x is palindrome integer.

An integer is a palindrome when it reads the same backward as forward. For example, 121 is palindrome while 123 is not.

 

Example 1:

Input: x = 121
Output: true

Example 2:

Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.

Example 3:

Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.

Example 4:

Input: x = -101
Output: false
 

Constraints:

-231 <= x <= 231 - 1
*/
#include <iostream>
#include <cmath>

class Solution
{
public:
    bool isPalindrome(int x)
    {
        // 음수인 경우
        if (x < 0)
        {
            return false;
        }

        std::string int2Str = std::to_string(x);
        int reverseInt = 0;
        std::string tmp;
        std::string::reverse_iterator ritr;
        for (ritr = int2Str.rbegin(); ritr != int2Str.rend(); ritr++)
        {
            tmp.push_back(*ritr);
        }

        if (std::stod(tmp) > pow(2, 31) - 1)
        {
            return false;
        }
        else
        {
            reverseInt = std::stod(tmp);
            if (reverseInt == x)
                return true;
            else
                return false;
        }
    }
};

int main()
{
    Solution s;
    int input = 2113;
    if (s.isPalindrome(input))
    {
        std::cout << input << " is palindrome number!" << std::endl;
    }
    return 0;
}