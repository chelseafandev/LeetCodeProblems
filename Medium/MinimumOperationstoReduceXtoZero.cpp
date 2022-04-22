/*
You are given an integer array nums and an integer x. In one operation, you can either remove the leftmost or the rightmost element from the array nums and subtract its value from x. Note that this modifies the array for future operations.
Return the minimum number of operations to reduce x to exactly 0 if it is possible, otherwise, return -1.


Example 1:
Input: nums = [1,1,4,2,3], x = 5
Output: 2
Explanation: The optimal solution is to remove the last two elements to reduce x to zero.

Example 2:
Input: nums = [5,6,7,8,9], x = 4
Output: -1

Example 3:
Input: nums = [3,2,20,1,1,3], x = 10
Output: 5
Explanation: The optimal solution is to remove the last three elements and the first two elements (5 operations in total) to reduce x to zero.


Constraints:
1 <= nums.length <= 10^5
1 <= nums[i] <= 10^4
1 <= x <= 10^9
*/

#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
    int minOperations(std::vector<int> &nums, int x)
    {
        int total_sum = 0;
        int window_len = 0;

        for (const auto& num : nums)
        {
            total_sum += num;
        }   

        if (total_sum == x)
        {
            return nums.size();
        }
            
        // 우리가 찾고자 하는 윈도우에 포함된 모든 요소를 더한 값
        int window_sum = total_sum - x;

        int cur_window_left_idx = 0; // 윈도우의 왼쪽 끝 인덱스
        int cur_window_right_idx = 0; // 윈도우의 오른쪽 끝 인덱스
        int cur_window_sum = 0; // 현재 윈도우의

        while (cur_window_left_idx <= cur_window_right_idx)
        {
            if (cur_window_sum < window_sum)
            {
                if (cur_window_right_idx < nums.size())
                {
                    cur_window_sum += nums[cur_window_right_idx++];
                }
                else
                {
                    break;
                }
            }
            else if (cur_window_sum > window_sum)
            {
                cur_window_sum -= nums[cur_window_left_idx++];
            }
            else
            {
                window_len = std::max(window_len, cur_window_right_idx - cur_window_left_idx);
                cur_window_sum -= nums[cur_window_left_idx++];
            }
        }

        if (cur_window_sum == window_sum)
        {
            window_len = std::max(window_len, cur_window_right_idx - cur_window_left_idx);
        }

        if (window_len == 0)
        {
            return -1;
        }

        return nums.size() - window_len;
    }
};

int main()
{
    std::vector<int> input = {1,1,4,2,3};
    int target = 5;
    Solution s;
    std::cout << s.minOperations(input, target) << std::endl;
}