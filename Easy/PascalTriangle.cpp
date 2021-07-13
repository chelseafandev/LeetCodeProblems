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
                    int data = output[i - 1][j - 1] + output[i - 1][j];
                    element.push_back(data);
                }
            }
            output.push_back(element);
        }
        return output;
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
