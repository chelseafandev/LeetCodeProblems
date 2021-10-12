/*
Write a function that reverses a string. The input string is given as an array of characters s.

Example 1:
Input: s = ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]

Example 2:
Input: s = ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]
 

Constraints:
1 <= s.length <= 10^5
s[i] is a printable ascii character.
 

Follow up: Do not allocate extra space for another array. You must do this by modifying the input array in-place with O(1) extra memory.
*/

#include <iostream>
#include <vector>

class Solution
{
public:
    void reverseString(std::vector<char> &s)
    {
        std::vector<char>::reverse_iterator ritr = s.rbegin();
        int size = s.size();
        for(int i = 0; i < size; i++)
        {
            s.push_back(*ritr);
            std::vector<char>::iterator itr = s.begin();
            s.erase(itr + size - (i + 1));
            ritr = s.rbegin() + i + 1;
        }
    }
};

int main()
{
    //std::vector<char> input = {'h','e','l','l','o'};
    //std::vector<char> input = {'H','a','n','n','a','h'};
    std::vector<char> input = {'H'};
    Solution s;
    s.reverseString(input);
    std::cout << "[ ";
    for(auto itr = input.begin(); itr != input.end(); itr++)
    {
        std::cout << *itr << " ";
    }
    std::cout << "]" << std::endl;
    return 0;
}