/*
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

 
Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: [4,-1,2,1] has the largest sum = 6.

Example 2:

Input: nums = [1]
Output: 1

Example 3:

Input: nums = [5,4,-1,7,8]
Output: 23
 

Constraints:

1 <= nums.length <= 3 * 10^4
-10^5 <= nums[i] <= 10^5
*/

#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
    int maxSubArray(std::vector<int> &nums)
    {
        int nMax = -100000;
        int nSum = 0;
        std::vector<int>::iterator itr;
        for (itr = nums.begin(); itr != nums.end(); itr++)
        {
            nSum += *itr;
            if (nSum <= 0)
            {
                nSum = 0;
                if (*itr > nMax)
                {
                    nMax = *itr;
                }
            }
            else
            {
                if (nSum > nMax)
                {
                    nMax = nSum;
                }
            }
        }

        return nMax;
    }
};

int main()
{
    std::vector<int> input = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    Solution s;
    std::cout << s.maxSubArray(input) << std::endl;
    return 0;
}