/*
Write an algorithm to determine if a number n is happy.

A happy number is a number defined by the following process:

Starting with any positive integer, replace the number by the sum of the squares of its digits.
Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
Those numbers for which this process ends in 1 are happy.
Return true if n is a happy number, and false if not.


Example 1:
Input: n = 19
Output: true
Explanation:
1^2 + 9^2 = 82
8^2 + 2^2 = 68
6^2 + 8^2 = 100
1^2 + 0^2 + 0^2 = 1

Example 2:
Input: n = 2
Output: false

Constraints:
1 <= n <= 2^31 - 1
*/
#include <iostream>
#include <cmath>

class Solution
{
public:
    bool isHappy(int n)
    {
        bool isCheck[810 + 1] = {
            false,
        };

        std::string input2str = std::to_string(n);
        while (1)
        {
            int sum = 0;
            int len = input2str.length();
            for (int i = 0; i < len; i++)
            {
                int tmp = input2str[i] - '0';
                int added = static_cast<int>(pow(tmp, 2));
                sum += added;
            }

            if (sum == 1)
                return true;

            if (isCheck[sum])
                break;
            else
                isCheck[sum] = true;

            input2str = std::to_string(sum);
        }

        return false;
    }
};

int main()
{
    while (1)
    {
        int input = 0;
        std::cout << "input을 입력하세요 >> ";
        std::cin >> input;

        Solution s;
        bool result = s.isHappy(input);
        if (result)
            std::cout << "Happy!" << std::endl;
        else
            std::cout << "Unhappy!" << std::endl;
    }
}