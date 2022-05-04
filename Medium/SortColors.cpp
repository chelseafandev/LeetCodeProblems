/*
Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
You must solve this problem without using the library's sort function.


Example 1:
Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]

Example 2:
Input: nums = [2,0,1]
Output: [0,1,2]

Constraints:
n == nums.length
1 <= n <= 300
nums[i] is either 0, 1, or 2.

Follow up: Could you come up with a one-pass algorithm using only constant extra space?
*/

#include <iostream>
#include <vector>

class Solution
{
public:
    void sortColors(std::vector<int> &nums)
    {
        // red, white, blue 가 nums안에 몇개씩 들어있는지를 카운팅하기 위한 변수. 색상은 index로 구분
        std::vector<int> counts = {0, 0, 0};

        for (const auto& num : nums)
        {
            counts[num]++;
        }

        nums.clear();

        for (int color = 0; color < 3; color++)
        {
            for (int count = 0; count < counts[color]; count++)
            {
                nums.push_back(color);
            }
        }
    }
};

int main()
{
    std::vector<int> input = {2,0,2,1,1,0};

    Solution s;
    s.sortColors(input);

    std::cout << "[ ";
    for (const auto num : input)
    {
        std::cout << num << " ";
    }
    std::cout << "]" << std::endl;

    return 0;
}