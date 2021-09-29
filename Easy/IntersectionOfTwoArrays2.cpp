/*
Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.

Example 1:
Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]

Example 2:
Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]
Explanation: [9,4] is also accepted.

Constraints:
1 <= nums1.length, nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 1000


Follow up:
What if the given array is already sorted? How would you optimize your algorithm?
What if nums1's size is small compared to nums2's size? Which algorithm is better?
What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?
*/
#include <iostream>
#include <vector>

class Solution
{
public:
    // 배열 요소 간 순서에 무관한 intersection
    std::vector<int> intersect(std::vector<int> &nums1, std::vector<int> &nums2)
    {
        std::vector<int> result;

        int nCount[1000 + 1];
        for(int i = 0; i < 1000; i++)
        {
            nCount[i] = 0;
        }

        for(auto elem : nums1)
        {
            nCount[elem]++;
        }

        for(auto elem : nums2)
        {
            if(nCount[elem] != 0)
            {
                result.push_back(elem);
                nCount[elem]--;
            }
        }

        return result;
    }

    // 배열 요소 간 순서 고려한 intersection
    std::vector<int> intersect2(std::vector<int> &nums1, std::vector<int> &nums2)
    {
        std::vector<int> bigger;
        std::vector<int> smaller;

        if(nums1.size() > nums2.size())
        {
            bigger = std::move(nums1);
            smaller = std::move(nums2);
        }
        else
        {
            bigger = std::move(nums2);
            smaller = std::move(nums1);
        }

        if(smaller.size() == 0)
        {
            std::vector<int> result;
            return result;
        }

        auto ret = makeResult(bigger, smaller);
        if (ret.empty())
        {
            ret = makeResult(smaller, bigger);
        }

        return ret;
    }

private:
    std::vector<int> makeResult(std::vector<int> &bigger, std::vector<int> &smaller)
    {
        std::vector<std::vector<int>> results;
        std::vector<int> result;

        int idx = 0;
        for (int i = 0; i < bigger.size(); i++)
        {
            if (idx >= smaller.size())
            {
                idx = 0;
                results.push_back(result);
                result.clear();
                continue;
            }

            if (bigger[i] == smaller[idx])
            {
                result.push_back(smaller[idx]);
                idx++;
            }
            else if (bigger[i] != smaller[idx])
            {
                idx = 0;
                results.push_back(result);
                result.clear();
                if (bigger[i] == smaller[idx])
                {
                    result.push_back(smaller[idx]);
                    idx++;
                }
            }
        }

        if(!result.empty())
        {
            results.push_back(result);
        }

        int max = 0;
        int target_idx = 0;
        for (int i = 0; i < results.size(); i++)
        {
            if (results[i].size() > max)
            {
                max = results[i].size();
                target_idx = i;
            }
        }

        return results[target_idx];
    }
};

int main()
{
    std::vector<int> nums1 = {2, 1};
    std::vector<int> nums2 = {1, 1};

    Solution s;
    auto v = s.intersect(nums1, nums2);
    
    std::cout << "[ ";
    for(auto itr = v.begin(); itr != v.end(); itr++)
    {
        std::cout << *itr << " ";
    }
    std::cout << "]" << std::endl;

    return 0;
}