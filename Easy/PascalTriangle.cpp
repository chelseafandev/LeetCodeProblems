/*
Given an integer numRows, return the first numRows of Pascal's triangle.
In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

Example 1:
Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

Example 2:
Input: numRows = 1
Output: [[1]]
 

Constraints:
1 <= numRows <= 30
*/

#include <iostream>
#include <vector>

class Solution
{
public:
    std::vector<std::vector<int>> generate(int numRows)
    {
        /*
        std::vector<std::vector<int>> output;
        output.reserve(numRows);
        for (int i = 0; i < numRows; i++)
        {
            std::vector<int> element;
            element.push_back(1);
            for (int j = 1; j < i + 1; j++)
            {
                if (j == numRows - 1)
                {
                    element.push_back(1);
                }
                else
                {
                    // 아래 코드는 LeetCode 실행 결과, heap-buffer-overflow가 발생함
                    element.push_back(output[i - 1][j - 1] + output[i - 1][j]);
                }
            }
            output.push_back(element);
        }
        return output;
        */

        //
        std::vector<std::vector<int>> retVector;
        int output[30][30] = {0, };
        for (int i = 0; i < numRows; i++)
        {
            output[i][0] = 1;
            for (int j = 1; j < i + 1; j++)
            {
                if (j == numRows - 1)
                {
                    output[i][j] = 1;
                }
                else
                {
                    output[i][j] = output[i - 1][j - 1] + output[i - 1][j];
                }
            }
        }

        for (int i = 0; i < numRows; i++)
        {
            std::vector<int> tmp;
            for (int j = 0; j < i + 1; j++)
            {
                tmp.push_back(output[i][j]);
            }
            retVector.push_back(tmp);
        }

        return retVector;
    }
};

int main()
{
    Solution s;
    std::vector<std::vector<int>>::iterator itr;
    auto result = s.generate(5);
    for (itr = result.begin(); itr != result.end(); itr++)
    {
        int size = (*itr).size();
        for (int i = 0; i < size; i++)
        {
            std::cout << (*itr)[i] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
