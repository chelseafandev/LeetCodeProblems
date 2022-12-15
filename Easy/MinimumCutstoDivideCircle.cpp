#include <iostream>

class Solution {
public:
    int numberOfCuts(int n) {
        if (n == 1)
        {
            return 0;
        }
        
        if (n % 2 == 0)
        {
            return n / 2;
        }
        
        return n;
    }
};

int main()
{
    Solution s;
    int n = 5;
    std::cout << s.numberOfCuts(n) << std::endl;
    return 0;
}