/*
Given an integer n, return a string array answer (1-indexed) where:

answer[i] == "FizzBuzz" if i is divisible by 3 and 5.
answer[i] == "Fizz" if i is divisible by 3.
answer[i] == "Buzz" if i is divisible by 5.
answer[i] == i if non of the above conditions are true.

Example 1:
Input: n = 3
Output: ["1","2","Fizz"]

Example 2:
Input: n = 5
Output: ["1","2","Fizz","4","Buzz"]

Example 3:
Input: n = 15
Output: ["1","2","Fizz","4","Buzz","Fizz","7","8","Fizz","Buzz","11","Fizz","13","14","FizzBuzz"]

Constraints:
1 <= n <= 10^4
*/

#include <iostream>
#include <vector>

class Solution
{
public:
    std::vector<std::string> fizzBuzz(int n)
    {

    }
};

int main()
{
    int input = 3;
    Solution s;
    auto v = s.fizzBuzz(input);
    std::cout << "[ ";
    for(auto itr = v.begin(); itr != v.end(); itr++)
    {
        std::cout << *itr << " ";
    }
    std::cout << "]" << std::endl;
    return 0;
}