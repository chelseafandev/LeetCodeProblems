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