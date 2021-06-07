/*
Given an array nums of size n, return the majority element.
The majority element is the element that appears more than ⌊n / 2⌋ times. 
You may assume that the majority element always exists in the array.
 
Example 1:
Input: nums = [3,2,3]
Output: 3

Example 2:
Input: nums = [2,2,1,1,1,2,2]
Output: 2
 

Constraints:
n == nums.length
1 <= n <= 5 * 10^4
-2^31 <= nums[i] <= 2^31 - 1
*/
#include <iostream>
#include <vector>
#include <map>

class Solution
{
public:
    int majorityElement(std::vector<int> &nums)
    {
        int result = 0;
        if (nums.size() == 1)
        {
            return nums[0];
        }

        std::map<int, std::vector<int>> map_;
        std::map<int, std::vector<int>>::iterator map_itr;

        std::vector<int>::iterator vector_itr;

        int min = nums.size() / 2;

        for (vector_itr = nums.begin(); vector_itr != nums.end(); vector_itr++)
        {
            map_itr = map_.find(*vector_itr);
            if (map_itr == map_.end())
            {
                // insert
                std::vector<int> vector_;
                vector_.push_back(*vector_itr);
                map_.insert(std::pair<int, std::vector<int>>(*vector_itr, vector_));
            }
            else
            {
                (map_itr->second).push_back(*vector_itr);
                if ((map_itr->second).size() > min)
                {
                    result = *vector_itr;
                }
            }
        }

        return result;
    }
};

int main()
{
    std::vector<int> input = {2, 2, 1, 1, 1, 2, 2};
    Solution s;
    std::cout << s.majorityElement(input) << std::endl;
    return 0;
}