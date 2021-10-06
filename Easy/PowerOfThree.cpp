/*
Given an integer n, return true if it is a power of three. Otherwise, return false.
An integer n is a power of three, if there exists an integer x such that n == 3^x.

Example 1:
Input: n = 27
Output: true

Example 2:
Input: n = 0
Output: false

Example 3:
Input: n = 9
Output: true

Example 4:
Input: n = 45
Output: false
 

Constraints:
-2^31 <= n <= 2^31 - 1
 
Follow up: Could you solve it without loops/recursion?
*/

#include <iostream>
#include <cmath>

class Solution
{
public:
    bool isPowerOfThree(int n)
    {
        if (n == 0)
            return false;
        
        if (n == 1)
            return true;

        if (n % 3 != 0)
            return false;
        
        int temp = n / 3;
        if (temp == 1)
            return true;

        return isPowerOfThree(temp);
    }
};

int main()
{
    int input = 1;
    Solution s;
    std::cout << std::boolalpha << s.isPowerOfThree(input) << std::endl;
    return 0;
}