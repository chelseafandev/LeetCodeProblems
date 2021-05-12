/*
Given two binary strings a and b, return their sum as a binary string.

Example 1:

Input: a = "11", b = "1"
Output: "100"

Example 2:

Input: a = "1010", b = "1011"
Output: "10101"
 

Constraints:

1 <= a.length, b.length <= 10^4
a and b consist only of '0' or '1' characters.
Each string does not contain leading zeros except for the zero itself.
*/
#include <iostream>
#include <vector>

class Solution
{
public:
    std::string addBinary(std::string a, std::string b)
    {
        std::vector<char> vecRet;

        char result = '0';
        char carry = '0';

        int nLenA = a.length();
        int nLenB = b.length();
        int nDiff = 0;
        
        std::string strSmall;
        std::string strBig;

        if (nLenA > nLenB)
        {
            strBig = a;
            strSmall = b;
            nDiff = nLenA - nLenB;
        }
        else
        {
            strBig = b;
            strSmall = a;
            nDiff = nLenB - nLenA;
        }

        std::string::reverse_iterator ritrSmall, ritrBig;
        for (ritrSmall = strSmall.rbegin(), ritrBig = strBig.rbegin(); ritrSmall != strSmall.rend(); ritrSmall++, ritrBig++)
        {
            makeSumResult(*ritrSmall, *ritrBig, result, carry);
            vecRet.push_back(result);
        }

        for (ritrBig = strBig.rbegin() + strSmall.length(); ritrBig != strBig.rend(); ritrBig++)
        {
            makeSumResult('0', *ritrBig, result, carry);
            vecRet.push_back(result);
        }

        std::string strRet = "";
        if(carry == '1')
        {
             strRet += '1';
        }

        std::vector<char>::reverse_iterator ritrVec;
        for (ritrVec = vecRet.rbegin(); ritrVec != vecRet.rend(); ritrVec++)
        {
            strRet += *ritrVec;
        }

        return strRet;
    }

private:
    void makeSumResult(char a, char b, char& result, char& carry)
    {
        if(a == '0' && b == '0' && carry == '0')
        {
            result = '0';
            carry = '0';
        }
        else if(a == '0' && b == '0' && carry == '1')
        {
            result = '1';
            carry = '0';
        }
        else if(a == '0' && b == '1' && carry == '0')
        {
            result = '1';
            carry = '0';
        }
        else if(a == '0' && b == '1' && carry == '1')
        {
            result = '0';
            carry = '1';
        }
        else if(a == '1' && b == '0' && carry == '0')
        {
            result = '1';
            carry = '0';
        }
        else if(a == '1' && b == '0' && carry == '1')
        {
            result = '0';
            carry = '1';
        }
        else if(a == '1' && b == '1' && carry == '0')
        {
            result = '0';
            carry = '1';
        }
        else
        {
            result = '1';
            carry = '1';
        }
    }
};

int main()
{
    std::string a = "1111";
    std::string b = "11111";

    Solution s;
    std::cout << s.addBinary(a, b) << std::endl;

    return 0;
}