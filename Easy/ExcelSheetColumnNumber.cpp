/*
Given a string columnTitle that represents the column title as appear in an Excel sheet, return its corresponding column number.

For example:

A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28 
... 

Example 1:
Input: columnTitle = "A"
Output: 1

Example 2:
Input: columnTitle = "AB"
Output: 28

Example 3:
Input: columnTitle = "ZY"
Output: 701

Example 4:
Input: columnTitle = "FXSHRXW"
Output: 2147483647
 

Constraints:
1 <= columnTitle.length <= 7
columnTitle consists only of uppercase English letters.
columnTitle is in the range ["A", "FXSHRXW"].
*/

#include <iostream>
#include <cmath>
#include <map>

class Solution
{
public:
    int titleToNumber(std::string columnTitle)
    {
        int result = 0;
        for(char c : columnTitle){
            int d = c - 'A' + 1;
            result = result*26 + d;
        }
        return result;
    }
};

int main()
{
    std::string input = "FXSHRXW";
    Solution s;
    std::cout << s.titleToNumber(input) << std::endl;
    return 0;
}