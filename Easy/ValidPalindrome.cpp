/*
Given a string s, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Example 1:
Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.

Example 2:
Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.
 

Constraints:
1 <= s.length <= 2 * 10^5
s consists only of printable ASCII characters.
*/

#include <iostream>
#include <vector>

class Solution
{
public:
    bool isPalindrome(std::string s)
    {
        std::vector<char> valid_string = makeValidString(s);
        auto itr = valid_string.begin();
        auto ritr = valid_string.rbegin();

        int len = valid_string.size();

        for (int i = 0; i < len - 1; i++)
        {
            if (*itr != *ritr)
            {
                return false;
            }
            else
            {
                itr++;
                ritr++;
            }
        }

        return true;
    }

private:
    std::vector<char> makeValidString(std::string input)
    {
        std::vector<char> result;

        for(auto itr = input.begin(); itr != input.end(); itr++)
        {
            if (*itr >= 65 && *itr <= 90)
            {
                // Only alphanumeric characters & Ignoring cases
                result.push_back(*itr + 32);
            }
            else if (*itr >= 97 && *itr <= 122)
            {
                // Only alphanumeric characters
                result.push_back(*itr);
            }
            else if (*itr>= 48 && *itr <= 57)
            {
                // Only alphanumeric characters
                result.push_back(*itr);
            }
        }
        
        return result;
    }
};

int main()
{
    std::string input = "0P";

    Solution s;
    std::cout << std::boolalpha << s.isPalindrome(input) << std::endl;
    return 0;
}