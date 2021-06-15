/*
Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
You must implement a solution with a linear runtime complexity and use only constant extra space.

Example 1:
Input: nums = [2,2,1]
Output: 1

Example 2:
Input: nums = [4,1,2,1,2]
Output: 4

Example 3:
Input: nums = [1]
Output: 1

Constraints:
1 <= nums.length <= 3 * 10^4
-3 * 10^4 <= nums[i] <= 3 * 10^4
Each element in the array appears twice except for one element which appears only once.
*/
#include <iostream>
#include <vector>
#include <set>

class Solution
{
public:
    int singleNumber(std::vector<int> &nums)
    {
        std::set<int> bag;
        std::vector<int>::iterator itr;
        for (itr = nums.begin(); itr != nums.end(); itr++)
        {
            // bag에 이미 존재한다면? 2개라는 의미
            if (bag.find(*itr) != bag.end())
            {
                // 삭제
                bag.erase(*itr);
            }
            else
            {
                bag.insert(*itr);
            }
        }

        // bag에 남아있는 값을 반환
        return *bag.begin();
    }
};

int main()
{
    std::vector<int> input = {4, 1, 2, 1, 2};
    Solution s;
    std::cout << s.singleNumber(input) << std::endl;
    return 0;
}