/*
Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.
If target is not found in the array, return [-1, -1].
You must write an algorithm with O(log n) runtime complexity.

Example 1:
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Example 2:
Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]

Example 3:
Input: nums = [], target = 0
Output: [-1,-1]

Constraints:
0 <= nums.length <= 10^5
-10^9 <= nums[i] <= 10^9
nums is a non-decreasing array.
-10^9 <= target <= 10^9
*/

#include <iostream>
#include <vector>

class Solution {
public:
    Solution()
    {
        range_left_ = 0;
        range_right_ = 0;

        /*
        // for debugging
        secound_operation_count_ = 0;
        third_operation_count_ = 0;
        */
    }

    std::vector<int> searchRange(std::vector<int>& nums, int target)
    {
        // 해당 문제는 target을 찾고 끝나는것이 아니기 때문에 단순 이진 탐색으로는 target의 전체 범위를 찾을 수 없음. O(logn)을 만족하기 위해서는 어떻게 접근해야할까...?
        std::vector<int> result;

        // 1. 최초 target을 찾는다. O(logn)
        bool is_found = false;
        int start = 0;
        int end = nums.size() - 1;
        int mid = 0;
        while(start <= end)
        {
            mid = (start + end) / 2;
            if (nums[mid] > target)
            {
                end = mid - 1;
            }
            else if (nums[mid] < target)
            {
                start = mid + 1;
            }
            else
            {
                is_found = true;
                break;
            }
        }

        if (!is_found)
        {
            result.push_back(-1);
            result.push_back(-1);
            return result;
        }

        range_left_ = mid;
        range_right_ = mid;

        // 2. 최초 target 인덱스를 기준으로 양쪽으로 나누어 range의 양끝을 구한다.
        result.push_back(find_target_index(nums, target, start, mid - 1, true)); // O(logn)
        // std::cout << "second step operation count: " << secound_operation_count_ << std::endl; // for debugging

        result.push_back(find_target_index(nums, target, mid + 1, end, false)); // O(logn)
        // std::cout << "third step operation count: " << third_operation_count_ << std::endl; // for debugging

        return result;
    }

private:
    int find_target_index(const std::vector<int>& nums, int target, int start, int end, bool is_left)
    {
        // base condition
        if (start > end)
        {
            if (is_left)
            {
                return range_left_;
            }
            else
            {
                return range_right_;
            }
        }

        /*
        // for debugging
        if(is_left)
        {
            secound_operation_count_++;
        }
        else
        {
            third_operation_count_++;
        }
        */

        int mid = (start + end) / 2;
        if (nums[mid] > target)
        {
            end = mid - 1;
            return find_target_index(nums, target, start, end, is_left);
        }
        else if (nums[mid] < target)
        {
            start = mid + 1;
            return find_target_index(nums, target, start, end, is_left);
        }
        else
        {
            if (is_left)
            {
                // 현재 target을 찾은 인덱스 값인 mid 바로 이전(mid-1)에 중복된 target값이 있다면 range 확장을 위해 탐색을 한번 더 수행한다.
                if (mid - 1 >= 0 && nums[mid-1] == target)
                {
                    end = mid - 1;
                    return find_target_index(nums, target, start, end, is_left);
                }
                else
                {
                    return mid;
                }
            }
            else
            {
                // 현재 target을 찾은 인덱스 값인 mid 바로 이후(mid+1)에 중복된 target값이 있다면 range 확장을 위해 탐색을 한번 더 수행한다.
                if (mid + 1 < nums.size() && nums[mid+1] == target)
                {
                    start = mid + 1;
                    return find_target_index(nums, target, start, end, is_left);
                }
                else
                {
                    return mid;
                }
            }
        }
    }

    int range_left_;
    int range_right_;

    /*
    // for debugging
    int secound_operation_count_;
    int third_operation_count_;
    */
};

int main()
{
    std::vector<int> nums = {5,7,7,8,8,10};
    int target = 8;
    Solution s;
    std::cout << "[ ";
    for (const auto& data : s.searchRange(nums, target))
    {
        std::cout << data << " ";
    }
    std::cout << "]" << std::endl;
    return 0;
}