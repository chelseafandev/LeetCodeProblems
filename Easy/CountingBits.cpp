/*
Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), 
ans[i] is the number of 1's in the binary representation of i.

Example 1:
Input: n = 2
Output: [0,1,1]
Explanation:
0 --> 0
1 --> 1
2 --> 10

Example 2:
Input: n = 5
Output: [0,1,1,2,1,2]
Explanation:
0 --> 0
1 --> 1
2 --> 10
3 --> 11
4 --> 100
5 --> 101


Constraints:
0 <= n <= 10^5
*/
#include <iostream>
#include <vector>

class Solution
{
public:
    std::vector<int> countBits(int n)
    {
        std::vector<int> result;

        // 2진수로 변환한 후 1의 개수 구하기
        for (int i = 0; i <= n; i++)
        {
            result.push_back(makeBinary(i));
        }

        return result;
    }

private:
    int makeBinary(int num)
    {
        if (num == 0)
        {
            return 0;
        }

        if (num == 1)
        {
            return 1;
        }

        int ret = 0;
        int quotient = 0;
        int remain = 0;

        remain = num % 2;
        if (remain == 1)
        {
            ret++;
        }
        quotient = num / 2;

        while (quotient >= 2)
        {
            remain = quotient % 2;
            if (remain == 1)
            {
                ret++;
            }

            quotient = quotient / 2;
        }

        if (quotient == 1)
        {
            ret++;
        }

        return ret;
    }
};

int main()
{
    int n = 100000;
    Solution s;
    std::vector<int> result = s.countBits(n);
    std::vector<int>::iterator itr;
    for (itr = result.begin(); itr != result.end(); itr++)
    {
        if (itr != result.end() - 1)
        {
            std::cout << *itr << ", ";
        }
        else
        {
            std::cout << *itr << std::endl;
        }
    }
    return 0;
}