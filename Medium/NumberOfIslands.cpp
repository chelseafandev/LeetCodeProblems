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
        for (int i = 0; i < 300; i++)
        {
            for (int j = 0; j < 300; j++)
            {
                flag_map_[i][j] = false;
            }
        }
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

        int total_island_cnt = 0;
        row_ = grid.size();
        col_ = grid[0].size();
       
        // 전략
        // 1. 일단 grid내에 land가 존재한다면 그 land는 항상 island일 것이다.
        // 2. 인접한 모든 land를 전부 다 조회하면 하나의 island가 된다.
        //
        // grid의 요소를 방문했는지 여부를 저장하기 위해 bool형 2차원 배열을 선언하고, 최초 (0,0)에서 시작하여 해당 grid의 요소가 land인 경우에는 인접한 모든 land의 2차원 배열의 값 갱신을 수행함. 인접한 모든 land를 찾았다면 총 island의 개수 값을 증가시켜줌.
        //
        // 모든 grid의 요소를 방문하며, 해당 요소가 land인 경우에는 인접(up, down, left, right)한 모든 land를 다 방문하여 flag값을 바꿔줌. 이때 인접한 모든 grid의 요소를 체크하기 위해 stack을 활용(DFS 개념)
        
        // grid의 좌표 값을 저장하기위해 pair 타입을 사용함
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
                    total_island_cnt++;
                }
            }
        }
        
        return total_island_cnt;
    }

private:
    // 인접한 land를 stack에 push하는 함수. grid의 인덱스 체크는 필수
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

    // grid의 요소를 방문했는지 여부를 확인하기 위한 bool형 2차원 배열
    // leetcode에서는 std::vector<std::vector<bool>> 사용이 안되던데..? 그래서 그냥 2차원 배열로 바꿈
    bool flag_map_[300][300];
};

int main()
{
    std::vector<std::vector<char>> input = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}};

    Solution s;
    std::cout << s.numIslands(input) << std::endl;
    return 0;
}