#include <iostream>

class Solution
{
public:
    int pivotInteger(int n)
    {
        int pivot = -1;
        int total_sum = (n*(n+1)) / 2;

        for (int i = 1; i <= n; i++) 
        {
            // (pivot*(pivot+1))/2 = total - (pivot*(pivot+1))/2 + pivot
            if (total_sum == i*i)
            {
                pivot = i;
                break;
            }
        }

        return pivot;
    }
};

int main()
{
    Solution s;
    int n = 4;
    std::cout << s.pivotInteger(n) << std::endl;
    return 0;
}