/*
You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Example 1:

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps

Example 2:

Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
 

Constraints:

1 <= n <= 45
*/
#include <iostream>
#include <vector>

class Solution
{
public:
    int climbStairs(int n)
    {

        // 점화식 만들기 문제인가..
        std::vector<int> v;
        v.push_back(1);
        v.push_back(2);
        for (int i = 2; i < n; i++)
        {
            v.push_back(v[i - 1] + v[i - 2]);
        }

        return v[n - 1];
    }
};

int main()
{
    int input = 5;
    Solution s;
    std::cout << s.climbStairs(input) << std::endl;
    return 0;
}