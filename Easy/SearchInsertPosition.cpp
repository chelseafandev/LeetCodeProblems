/*
Given a sorted array of distinct integers and a target value, return the index if the target is found. 
If not, return the index where it would be if it were inserted in order.


Example 1:

Input: nums = [1,3,5,6], target = 5
Output: 2

Example 2:

Input: nums = [1,3,5,6], target = 2
Output: 1

Example 3:

Input: nums = [1,3,5,6], target = 7
Output: 4

Example 4:

Input: nums = [1,3,5,6], target = 0
Output: 0

Example 5:

Input: nums = [1], target = 0
Output: 0
 

Constraints:

1 <= nums.length <= 10^4
-10^4 <= nums[i] <= 10^4
nums contains distinct values sorted in ascending order.
-10^4 <= target <= 10^4
*/
#include <iostream>
#include <vector>

class Solution
{
public:
    int searchInsert(std::vector<int> &nums, int target)
    {
        int nLen = nums.size();
        if (target < nums[0])
        {
            return 0;
        }

        int i = 0;
        for (i = 0; i < nLen; i++)
        {
            if (nums[i] == target || nums[i] > target)
            {
                return i;
            }
        }

        return i;
    }
};

int main()
{
    std::vector<int> nums = {1, 3, 5, 6};
    int target = 0;

    Solution s;
    std::cout << s.searchInsert(nums, target) << std::endl;
    return 0;
}