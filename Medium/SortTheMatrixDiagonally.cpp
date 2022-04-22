/*
A matrix diagonal is a diagonal line of cells starting from some cell in either the topmost row or leftmost column and going in the bottom-right direction until reaching the matrix's end.
For example, the matrix diagonal starting from mat[2][0], where mat is a 6 x 3 matrix, includes cells mat[2][0], mat[3][1], and mat[4][2].

Given an m x n matrix mat of integers, sort each matrix diagonal in ascending order and return the resulting matrix.

Example 1:
Input: mat = [[3,3,1,1],[2,2,1,2],[1,1,1,2]]
Output: [[1,1,1,1],[1,2,2,2],[1,2,3,3]]

Example 2:
Input: mat = [[11,25,66,1,69,7],[23,55,17,45,15,52],[75,31,36,44,58,8],[22,27,33,25,68,4],[84,28,14,11,5,50]]
Output: [[5,17,4,1,52,7],[11,11,25,45,8,69],[14,23,25,44,58,15],[22,27,31,36,50,66],[84,28,75,33,55,68]]
 

Constraints:
m == mat.length
n == mat[i].length
1 <= m, n <= 100
1 <= mat[i][j] <= 100
*/

#include <iostream>
#include <vector>
#include <algorithm>

class Solution
{
public:
    std::vector<std::vector<int>> diagonalSort(std::vector<std::vector<int>> &mat)
    {
        int row_size = 0;
        int col_size = 0;

        row_size = mat.size();
        if (row_size != 0)
        {
            col_size = mat[0].size();
        }

        // row (`c is 0`)
        for (int r = 0; r < row_size; r++)
        {
            make_asc_order(mat, row_size, col_size, r, 0);
        }

        // col (except index 0) (`r is 0`)
        for (int c = 1; c < col_size; c++)
        {
            make_asc_order(mat, row_size, col_size, 0, c);
        }

        return mat;
    }
    
private:
    void make_asc_order(std::vector<std::vector<int>>& mat, const int& row_size, const int& col_size, int r, int c)
    {
        int init_r = r;
        int init_c = c;

        std::vector<int> diagonal;

        // find diagonal in matrix
        while (r < row_size && c < col_size)
        {
            diagonal.push_back(mat[r++][c++]);
        }

        // sort diagonal
        std::sort(diagonal.begin(), diagonal.end());

        // update matrix
        for (const auto& num : diagonal)
        {
            mat[init_r++][init_c++] = num;
        }
    }
};

int main()
{
    // std::vector<std::vector<int>> mat = {{3,3,1,1},{2,2,1,2},{1,1,1,2}};
    std::vector<std::vector<int>> mat = {{11,25,66,1,69,7},{23,55,17,45,15,52},{75,31,36,44,58,8},{22,27,33,25,68,4},{84,28,14,11,5,50}};
    Solution s;
    
    std::cout << "{ ";
    for (const auto& outer : s.diagonalSort(mat))
    {
        std::cout << "{ ";
        for (const auto& data : outer)
        {
            std::cout << data << " ";
        }
        std::cout << "} ";
    }
    std::cout << "}" << std::endl;

    return 0;
}