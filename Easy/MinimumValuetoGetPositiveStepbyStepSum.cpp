/*
Given an array of integers nums, you start with an initial positive value startValue.
In each iteration, you calculate the step by step sum of startValue plus elements in nums (from left to right).
Return the minimum positive value of startValue such that the step by step sum is never less than 1.


Example 1:
Input: nums = [-3,2,-3,4,2]
Output: 5
Explanation: If you choose startValue = 4, in the third iteration your step by step sum is less than 1.
step by step sum
startValue = 4 | startValue = 5 | nums
  (4 -3 ) = 1  | (5 -3 ) = 2    |  -3
  (1 +2 ) = 3  | (2 +2 ) = 4    |   2
  (3 -3 ) = 0  | (4 -3 ) = 1    |  -3
  (0 +4 ) = 4  | (1 +4 ) = 5    |   4
  (4 +2 ) = 6  | (5 +2 ) = 7    |   2

Example 2:
Input: nums = [1,2]
Output: 1
Explanation: Minimum start value should be positive.

Example 3:
Input: nums = [1,-2,-3]
Output: 5

Constraints:
1 <= nums.length <= 100
-100 <= nums[i] <= 100
*/

#include <iostream>
#include <vector>

class Solution
{
public:
    int minStartValue(std::vector<int> &nums)
    {
        int postive_sum = 0;
        int negative_sum = 0;
        int sum = 0;

        int target = 1;

        for (const auto& num : nums)
        {
            if (num >= 0)
            {
                postive_sum += num;
            }
            else
            {
                negative_sum += num;
            }

            sum = postive_sum + negative_sum;
            if (sum + target <= 0)
            {
                target += (-1 * (sum + target) + 1);
            }
        }

        return target;
    }
};

int main()
{
    std::vector<int> input = {1, -80, 22, -92};

    Solution s;
    std::cout << s.minStartValue(input) << std::endl;
    
    return 0;
}