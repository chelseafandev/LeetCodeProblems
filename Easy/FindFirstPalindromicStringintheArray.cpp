/*
Given an array of strings words, return the first palindromic string in the array. If there is no such string, return an empty string "".
A string is palindromic if it reads the same forward and backward.


Example 1:
Input: words = ["abc","car","ada","racecar","cool"]
Output: "ada"
Explanation: The first string that is palindromic is "ada".
Note that "racecar" is also palindromic, but it is not the first.

Example 2:
Input: words = ["notapalindrome","racecar"]
Output: "racecar"
Explanation: The first and only string that is palindromic is "racecar".

Example 3:
Input: words = ["def","ghi"]
Output: ""
Explanation: There are no palindromic strings, so the empty string is returned.

Constraints:
1 <= words.length <= 100
1 <= words[i].length <= 100
words[i] consists only of lowercase English letters.
*/

#include <iostream>
#include <vector>

class Solution
{
public:
    std::string firstPalindrome(std::vector<std::string> &words)
    {
        for (const auto& word : words)
        {
            if(is_palindrome(word))
            {
                return word;
            }
        }

        return "";
    }

private:
    bool is_palindrome(const std::string& word)
    {
        int len = word.length();
        
        auto front = word.begin();
        auto rear = word.rbegin();

        for (int i = 0; i < len/2; i++)
        {
            if (*front != *rear)
            {
                return false;
            }

            front++;
            rear++;
        }

        return true;
    }
};

int main()
{
    std::vector<std::string> input = {"abc","car","ada","racecar","cool"};
    
    Solution s;
    std::cout << s.firstPalindrome(input) << std::endl;
    return 0;
}