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
        int idx_buy = 0;
        int idx_sell = 0;
        int profit = 0;

        if(prices.size() == 0)
        {
            return 0;
        }

        idx_buy = 0;
        while (idx_buy < prices.size()-1)
        {
            int tmp_idx_sell = 0;
            int tmp_max_price = 0;
            for (int i = idx_buy + 1; i < prices.size(); i++)
            {
                // 최대값을 구한다
                // 여기서 equal 조건이 빠지면 무한 루프에 빠짐(!)
                if (tmp_max_price <= prices[i])
                {
                    tmp_max_price = prices[i];
                    tmp_idx_sell = i;
                }
            }

            for (int i = idx_buy + 1; i < tmp_idx_sell; i++)
            {
                if (prices[idx_buy] > prices[i])
                {
                    idx_buy = i;
                }
            }

            int tmp_profit = prices[tmp_idx_sell] - prices[idx_buy];
            if(profit < tmp_profit)
            {
                profit = tmp_profit;
            }

            idx_buy = tmp_idx_sell;
        }

        return profit;
    }
};

int main()
{
    std::vector<int> input = {98,100,99,98,97,96,95,94,93,1,4};
    Solution s;
    std::cout << s.maxProfit(input) << std::endl;
    return 0;
}