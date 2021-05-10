/*
Given a non-empty array of decimal digits representing a non-negative integer, increment one to the integer.

The digits are stored such that the most significant digit is at the head of the list, 
and each element in the array contains a single digit.

You may assume the integer does not contain any leading zero, except the number 0 itself.

 
Example 1:

Input: digits = [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.

Example 2:

Input: digits = [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.

Example 3:

Input: digits = [0]
Output: [1]
 

Constraints:

1 <= digits.length <= 100
0 <= digits[i] <= 9
*/
#include <iostream>
#include <vector>

class Solution
{
public:
    std::vector<int> plusOne(std::vector<int> &digits)
    {   
        std::vector<int> nRet;
        int nSum = 0;
        int nCarry = 0;
        std::vector<int>::reverse_iterator ritr = digits.rbegin();

        nSum = *ritr + 1;
        if (nSum > 9)
        {
            nCarry = 1;
            *ritr = 0;
        }
        else
        {
            nCarry = 0;
            *ritr = nSum;
        }
        ritr++;

        while (nCarry != 0 && ritr != digits.rend())
        {
            nSum = *ritr + nCarry;
            if (nSum > 9)
            {
                nCarry = 1;
                *ritr = 0;
            }
            else
            {
                nCarry = 0;
                *ritr = nSum;
            }

            ritr++;
        }

        if(nCarry == 1)
        {
            nRet.push_back(1);
        }

        std::vector<int>::iterator itr;
        for(itr = digits.begin(); itr != digits.end(); itr++)
        {
            nRet.push_back(*itr);
        }

        return nRet;
    }
};

int main()
{
    //std::vector<int> input = {1, 9, 9, 9, 9};
    std::vector<int> input = {9};
    Solution s;
    std::vector<int> result = s.plusOne(input);
    std::vector<int>::iterator itr;
    for (itr = result.begin(); itr != result.end(); itr++)
    {
        std::cout << *itr;
    }
    return 0;
}
