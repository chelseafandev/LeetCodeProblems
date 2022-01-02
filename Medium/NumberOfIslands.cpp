/*
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.
An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:
Input: grid = [
["1","1","1","1","0"],
["1","1","0","1","0"],
["1","1","0","0","0"],
["0","0","0","0","0"]
]
Output: 1

Example 2:
Input: grid = [
["1","1","0","0","0"],
["1","1","0","0","0"],
["0","0","1","0","0"],
["0","0","0","1","1"]
]
Output: 3

Constraints:
m == grid.length
n == grid[i].length
1 <= m, n <= 300
grid[i][j] is '0' or '1'.
*/

#include <iostream>
#include <vector>
#include <stack>

class Solution
{
public:
    Solution()
    {
        last_flag_ = 0;
    }

    int numIslands(const std::vector<std::vector<char>> &grid)
    {
        if (grid.empty())
        {
            std::cout << "row of grid is empty" << std::endl;
            return 0;
        }

        if (grid[0].empty())
        {
            std::cout << "col of grid is empty" << std::endl;
            return 0;
        }

        row_ = grid.size();
        flag_map_.reserve(row_);
        col_ = grid[0].size();
        for(int i = 0; i < row_; i++)
        {
            flag_map_[i].reserve(col_);
        }

        for (int i = 0; i < row_; i++)
        {
            for (int j = 0; j < col_; j++)
            {
                flag_map_[i][j] = false;
            }
        }
        
        // 인접한 모든 grid의 요소를 체크하기 위해 stack 활용
        std::stack<std::pair<int, int>> s;
        for (int i = 0; i < row_; i++)
        {
            for (int j = 0; j < col_; j++)
            {
                if (!flag_map_[i][j] && grid[i][j] == '1')
                {
                    s.push(std::make_pair(i, j));
                    while (!s.empty())
                    {
                        auto popped = s.top();
                        s.pop();
                        flag_map_[popped.first][popped.second] = true;
                        push_adjacent_land(grid, popped.first, popped.second, s);
                    }
                    last_flag_++;
                }
            }
        }
        
        return last_flag_;
    }

private:
    void push_adjacent_land(const std::vector<std::vector<char>> &grid, int r, int c, std::stack<std::pair<int, int>>& s)
    {
        // up
        int cur = r - 1;
        if (cur >= 0)
        {
            if (grid[cur][c] == '1' && flag_map_[cur][c] == false)
            {
                s.push(std::make_pair(cur, c));
            }
        }

        // down
        cur = r + 1;
        if (cur < row_)
        {
            if (grid[cur][c] == '1' && flag_map_[cur][c] == false)
            {
                s.push(std::make_pair(cur, c));
            }
        }

        // left
        cur = c - 1;
        if (cur >= 0)
        {
            if (grid[r][cur] == '1' && flag_map_[r][cur] == false)
            {
                s.push(std::make_pair(r, cur));
            }
        }

        // right
        cur = c + 1;
        if (cur < col_)
        {
            if (grid[r][cur] == '1' && flag_map_[r][cur] == false)
            {
                s.push(std::make_pair(r, cur));
            }
        }
    }

    int row_;
    int col_;

    std::vector<std::vector<bool>> flag_map_;
    int last_flag_;
};

int main()
{
    std::vector<std::vector<char>> input = {
        {'1', '1', '0', '1', '0'},
        {'1', '1', '1', '1', '1'},
        {'0', '0', '0', '0', '0'},
        {'0', '0', '0', '1', '1'}};

    Solution s;
    std::cout << s.numIslands(input) << std::endl;
    return 0;
}