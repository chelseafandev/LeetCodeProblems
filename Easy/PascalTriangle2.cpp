/*
Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

Example 1:
Input: rowIndex = 3
Output: [1,3,3,1]

Example 2:
Input: rowIndex = 0
Output: [1]

Example 3:
Input: rowIndex = 1
Output: [1,1]
 

Constraints:
0 <= rowIndex <= 33

Follow up: Could you optimize your algorithm to use only O(rowIndex) extra space?
*/

#include <iostream>
#include <vector>

class Solution
{
public:
    std::vector<int> getRow(int rowIndex)
    {
        // 최적화에 신경써보자(extra space를 O(rowIndex)만 사용해서)
        std::vector<int> result;

        if (rowIndex == 0)
        {
            result.push_back(1);
            return result;
        }

        if (rowIndex == 1)
        {
            result.push_back(1);
            result.push_back(1);
            return result;
        }

        std::vector<int> prev_vector;
        for (int i = 0; i < rowIndex + 1; i ++)
        {
            if (i == 0 || i == 1)
            {
                prev_vector.push_back(1);
            }
            else
            {
                result.clear();
                result.push_back(1);
                for (int j = 0; j < i - 1; j++)
                {
                    result.push_back(prev_vector[j] + prev_vector[j+1]);
                }
                result.push_back(1);

                if (i == rowIndex)
                    return result;
                else
                    prev_vector = std::move(result);
            }
        }

        return result;
    }
};

int main()
{
    int input = 5;
    Solution s;
    auto result = s.getRow(input);
    
    std::cout << "[ ";
    for(auto itr = result.begin(); itr != result.end(); itr++)
    {
        std::cout << *itr << " ";
    }
    std::cout << "]" << std::endl;

    return 0;
}