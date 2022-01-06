/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future
to sell that stock. Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

Example 1:
Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

Example 2:
Input: prices = [7,6,4,3,1]
Output: 0
Explanation: In this case, no transactions are done and the max profit = 0.

Constraints:
1 <= prices.length <= 10^5
0 <= prices[i] <= 10^4
*/
#include <iostream>
#include <vector>

class Solution
{
public:
    int maxProfit(std::vector<int>& prices)
    {
        // sell할 수 있는 날들 중 가장 비싼 값을 미리 저장
        // max_sell[i] : i번째 날에 buy를 하는 경우, 남은 날들 중 가장 비싸게 팔 수 있는 가격
        int tmp = 0;
        int max_sell[prices.size() - 1];
        for (int i = prices.size() - 2; i >= 0; i--)
        {
            if (tmp < prices[i+1])
            {
                tmp = prices[i+1];
            }

            max_sell[i] = tmp;
        }

        // 아래 for문에서 i는 buy 시점
        int buy = 0;
        int profit = 0;
        int max_profit = 0;
        for (int i = 0; i < prices.size() - 1; i++)
        {
            profit = max_sell[i] - prices[i];

            if(max_profit < profit)
            {
                max_profit = profit;
            }
        }

        return max_profit;
    }
};

int main()
{
    std::vector<int> input = {7,6,4,3,1};
    Solution s;
    std::cout << s.maxProfit(input) << std::endl;
    return 0;
}