/*
Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

 

Example 1:

Input: x = 123
Output: 321
Example 2:

Input: x = -123
Output: -321
Example 3:

Input: x = 120
Output: 21
Example 4:

Input: x = 0
Output: 0
 

Constraints:

-231 <= x <= 231 - 1
*/
#include <iostream>
#include <cmath>

class Solution
{
public:
    int reverse(int x)
    {
        int nRet = 0;
        bool isNegative = x < 0 ? true : false;

        if (isNegative && x < (-1 * (pow(2, 31) - 1)))
            return 0;
        else if (isNegative && x >= (-1 * (pow(2, 31) - 1)))
            x *= -1;

        std::string toStr = std::to_string(x);
        std::string reverseStr;
        std::string::reverse_iterator ritr;
        for (ritr = toStr.rbegin(); ritr != toStr.rend(); ritr++)
        {
            reverseStr.push_back(*ritr);
        }

        if (isNegative)
        {
            // 음수
            if (-1 * pow(2, 31) > -1 * std::stod(reverseStr))
            {
                std::cout << "(Negative) Out of bound" << std::endl;
                return 0;
            }
            else
            {
                nRet = -1 * std::stod(reverseStr);
            }
        }
        else
        {
            // 양수
            if (pow(2, 31) - 1 < std::stod(reverseStr))
            {
                std::cout << "(Postive) Out of bound" << std::endl;
                return 0;
            }
            else
            {
                nRet = std::stod(reverseStr);
            }
        }

        return nRet;
    }
};

int main()
{
    Solution s;
    std::cout << s.reverse(-2147483648) << std::endl;
    std::cout << s.reverse(-2147483647) << std::endl;
    return 0;
}