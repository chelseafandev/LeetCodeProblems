/*
Given an array of integers arr, return the number of subarrays with an odd sum.
Since the answer can be very large, return it modulo 10^9 + 7.


Example 1:
Input: arr = [1,3,5]
Output: 4
Explanation: All subarrays are [[1],[1,3],[1,3,5],[3],[3,5],[5]]
All sub-arrays sum are [1,4,9,3,8,5].
Odd sums are [1,9,3,5] so the answer is 4.

Example 2:
Input: arr = [2,4,6]
Output: 0
Explanation: All subarrays are [[2],[2,4],[2,4,6],[4],[4,6],[6]]
All sub-arrays sum are [2,6,12,4,10,6].
All sub-arrays have even sum and the answer is 0.

Example 3:
Input: arr = [1,2,3,4,5,6,7]
Output: 16

Constraints:
1 <= arr.length <= 10^5
1 <= arr[i] <= 100
*/

#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
    int numOfSubarrays(std::vector<int> &arr)
    {
        int odd_cnt = 0;
        int even_cnt = 0;
        long long result = 0;
        int tmp = 0;

        for (const auto& num : arr)
        {
            if (num % 2 == 0)
            {
                // even

                even_cnt++;
            }
            else
            {
                // odd

                // 짝수 값을 더하는 경우에는 기존의 값의 성격(짝수냐 홀수냐)이 변하지 않음
                // odd  + even = odd
                // even + even = even
                //
                // 홀수 값을 더하는 경우에는 기존의 값의 성격이 반대로 변함
                // odd  + odd = even
                // even + odd = odd
                //
                std::swap(even_cnt, odd_cnt);
                
                // 홀수 값 그 자체로 하나의 subarray이므로
                odd_cnt++;
            }

            result += odd_cnt;
        }

        return result % 1000000007;
    }
};

int main()
{
    std::vector<int> input = {1,2,3,4,5,6,7};
    Solution s;
    std::cout << s.numOfSubarrays(input) << std::endl;
    return 0;
}
