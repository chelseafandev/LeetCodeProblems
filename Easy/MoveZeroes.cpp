/*
Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
Note that you must do this in-place without making a copy of the array.

Example 1:
Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]

Example 2:
Input: nums = [0]
Output: [0]
 

Constraints:
1 <= nums.length <= 10^4
-2^31 <= nums[i] <= 2^31 - 1
*/
#include <iostream>
#include <vector>

class Solution
{
public:
    void moveZeroes(std::vector<int> &nums)
    {
        int num_of_zeroes = 0;
        std::vector<int>::iterator itr;
        for (itr = nums.begin(); itr != nums.end();)
        {
            if (*itr == 0)
            {
                itr = nums.erase(itr);
                num_of_zeroes++;
            }
            else
            {
                itr++;
            }
        }

        for (int i = 0; i < num_of_zeroes; i++)
        {
            nums.push_back(0);
        }
    }
};

int main()
{
    std::vector<int> input = {0, 0, 1, 0, 3, 12};
    Solution s;
    s.moveZeroes(input);

    std::vector<int>::iterator itr;
    std::cout << "[";
    for (itr = input.begin(); itr != input.end(); itr++)
    {
        if (itr != input.end() - 1)
        {
            std::cout << *itr << ", ";
        }
        else
        {
            std::cout << *itr;
        }
    }
    std::cout << "]" << std::endl;

    return 0;
}