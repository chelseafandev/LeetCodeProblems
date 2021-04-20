/*
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, 2 is written as II in Roman numeral, just two one's added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. 
Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given a roman numeral, convert it to an integer.

 

Example 1:

Input: s = "III"
Output: 3

Example 2:

Input: s = "IV"
Output: 4

Example 3:

Input: s = "IX"
Output: 9

Example 4:

Input: s = "LVIII"
Output: 58
Explanation: L = 50, V= 5, III = 3.

Example 5:

Input: s = "MCMXCIV"
Output: 1994
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
 

Constraints:

1 <= s.length <= 15
s contains only the characters ('I', 'V', 'X', 'L', 'C', 'D', 'M').
It is guaranteed that s is a valid roman numeral in the range [1, 3999].
*/
#include <iostream>
#include <vector>

class Solution
{
public:
    int romanToInt(std::string s)
    {
        int nRet = 0;
        std::vector<int> arrayInt;
        std::string::iterator itr;
        for (itr = s.begin(); itr != s.end(); itr++)
        {
            arrayInt.push_back(changeRomanToInt(*itr));
        }

        int nLen = arrayInt.size();
        for (int i = 0; i < nLen; i++)
        {
            // 예외 처리
            if (i == 0)
            {
                nRet += arrayInt.at(i);
            }
            else
            {
                if ((arrayInt.at(i - 1) == arrayInt.at(i)) || (arrayInt.at(i - 1) > arrayInt.at(i)))
                {
                    nRet += arrayInt.at(i);
                }
                else if (arrayInt.at(i - 1) < arrayInt.at(i))
                {
                    nRet += (arrayInt.at(i) - 2*arrayInt.at(i - 1));
                }
            }
        }

        return nRet;
    }

    int changeRomanToInt(char s)
    {
        int nRet = 0;
        // 'I', 'V', 'X', 'L', 'C', 'D', 'M'
        switch (s)
        {
        case 'I':
            nRet = 1;
            break;
        case 'V':
            nRet = 5;
            break;
        case 'X':
            nRet = 10;
            break;
        case 'L':
            nRet = 50;
            break;
        case 'C':
            nRet = 100;
            break;
        case 'D':
            nRet = 500;
            break;
        case 'M':
            nRet = 1000;
            break;
        default:
            break;
        }

        return nRet;
    }
};

int main()
{
    Solution s;
    std::string input = "XXIV";
    std::cout << s.romanToInt(input) << std::endl;
    input = "LVIII";
    std::cout << s.romanToInt(input) << std::endl;
    input = "MCMXCIV";
    std::cout << s.romanToInt(input) << std::endl;
    input = "XXXXIV";
    std::cout << s.romanToInt(input) << std::endl;
    input = "MMMMIL";
    std::cout << s.romanToInt(input) << std::endl;
}
