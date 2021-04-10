/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

Example1:
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Output: Because nums[0] + nums[1] == 9, we return [0, 1].

Constraints:
2 <= nums.length <= 103
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists.
*/
#include <iostream>
#include <vector>

std::vector<int> twoSum(std::vector<int> &nums, int target)
{
    std::vector<int> Ret;
    int nSize = nums.size();
    for (int i = 0; i < nSize - 1; i++)
    {
        for (int j = i + 1; j < nSize; j++)
        {
            if ((nums[i] + nums[j]) == target)
            {
                Ret.push_back(i);
                Ret.push_back(j);
                return Ret;
            }
        }
    }

    return Ret;
}

int main()
{
    std::vector<int> input = {2, 7, 11, 15};
    std::vector<int> output;
    std::vector<int>::iterator itr;
    output = twoSum(input, 9);
    for (itr = output.begin(); itr != output.end(); itr++)
    {
        std::cout << *itr << std::endl;
    }

    return 0;
}