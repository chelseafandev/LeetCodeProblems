/*
Reverse bits of a given 32 bits unsigned integer.

Note:
Note that in some languages such as Java, there is no unsigned integer type. 
In this case, both input and output will be given as a signed integer type. 
They should not affect your implementation, as the integer's internal binary representation is the same, 
whether it is signed or unsigned. In Java, the compiler represents the signed integers using 2's complement notation. 
Therefore, in Example 2 above, the input represents the signed integer -3 and the output represents the signed integer -1073741825.

Constraints:
The input must be a binary string of length 32
*/

#include <iostream>
#include <cmath>
#include <vector>

class Solution
{
public:
    uint32_t reverseBits(uint32_t n)
    {
        uint32_t output = 0;
        std::vector<int> bag;
        //std::cout << n << std::endl;
        for(int i = 0; i < 32; i++)
        {
            uint32_t tmp = static_cast<uint32_t>(pow(2, i));
            auto result = n & tmp;
            if(result != 0)
                bag.push_back(1);
            else
                bag.push_back(0);
        }

        int idx = 0;
        std::vector<int>::reverse_iterator ritr;
        for(ritr = bag.rbegin(); ritr != bag.rend(); ritr++)
        {
            if(*ritr != 0)
            {
                uint32_t added = static_cast<uint32_t>(pow(2, idx));
                output += added;
            }
            
            idx++;
        }

        std::cout << "output = " << output << std::endl;
        return output;
    }
};

int main()
{
    uint32_t input = 0b00000010100101000001111010011100;
    Solution s;
    s.reverseBits(input);
    return 0;
}