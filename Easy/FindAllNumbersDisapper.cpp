/*
Given an array nums of n integers where nums[i] is in the range [1, n], 
return an array of all the integers in the range [1, n] that do not appear in nums.
 
Example 1:
Input: nums = [4,3,2,7,8,2,3,1]
Output: [5,6]

Example 2:
Input: nums = [1,1]
Output: [2]
 

Constraints:

n == nums.length
1 <= n <= 10^5
1 <= nums[i] <= n
*/
#include <iostream>
#include <vector>

class Solution
{
public:
    std::vector<int> findDisappearedNumbers(std::vector<int> &nums)
    {
        int n = nums.size();
        int *pArray = new int[n + 1];

        for (int i = 0; i < n; i++)
        {
            pArray[i] = 0;
        }

        std::vector<int>::iterator itr;
        for (itr = nums.begin(); itr != nums.end(); itr++)
        {
            pArray[*itr]++;
        }

        std::vector<int> output;
        for (int i = 1; i <= n; i++)
        {
            if (pArray[i] == 0)
            {
                output.push_back(i);
            }
        }
        delete[] pArray;

        return output;
    }
};

int main()
{
    std::vector<int> input = {
        1,
        1};
    Solution s;
    std::vector<int> output = s.findDisappearedNumbers(input);
    int nLen = output.size();
    std::cout << "[";
    for (int i = 0; i < nLen; i++)
    {

        std::cout << output[i] << " ";
    }
    std::cout << "]" << std::endl;
    return 0;
}