/*
Given an encoded string, return its decoded string.
The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.
You may assume that the input string is always valid; there are no extra white spaces, square brackets are well-formed, etc.
Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there will not be input like 3a or 2[4].

Example 1:
Input: s = "3[a]2[bc]"
Output: "aaabcbc"

Example 2:
Input: s = "3[a2[c]]"
Output: "accaccacc"

Example 3:
Input: s = "2[abc]3[cd]ef"
Output: "abcabccdcdcdef"

Constraints:
1 <= s.length <= 30
s consists of lowercase English letters, digits, and square brackets '[]'.
s is guaranteed to be a valid input.
All the integers in s are in the range [1, 300].
*/

#include <iostream>
#include <stack>

class Solution
{
public:
    std::string decodeString(std::string s)
    {
        std::stack<int> integerstack;
        std::stack<char> stringstack;

        std::string temp = "";
        std::string result = "";

        // Traversing the string
        for (int i = 0; i < s.length(); i++)
        {
            int count = 0;

            // If number, convert it into number
            // and push it into integerstack.
            if (s[i] >= '0' && s[i] <= '9')
            {
                while (s[i] >= '0' && s[i] <= '9')
                {
                    count = count * 10 + s[i] - '0';
                    i++;
                }

                i--;
                integerstack.push(count);
            }

            // If closing bracket ']', pop element until
            // '[' opening bracket is not found in the
            // character stack.
            else if (s[i] == ']')
            {
                temp = "";
                count = 0;

                if (!integerstack.empty())
                {
                    count = integerstack.top();
                    integerstack.pop();
                }

                while (!stringstack.empty() && stringstack.top() != '[')
                {
                    temp = stringstack.top() + temp;
                    stringstack.pop();
                }

                if (!stringstack.empty() && stringstack.top() == '[')
                    stringstack.pop();

                // Repeating the popped string 'temo' count
                // number of times.
                for (int j = 0; j < count; j++)
                    result = result + temp;

                // Push it in the character stack.
                for (int j = 0; j < result.length(); j++)
                    stringstack.push(result[j]);

                result = "";
            }

            // If '[' opening bracket, push it into character stack.
            else if (s[i] == '[')
            {
                if (s[i - 1] >= '0' && s[i - 1] <= '9')
                    stringstack.push(s[i]);

                else
                {
                    stringstack.push(s[i]);
                    integerstack.push(1);
                }
            }

            else
                stringstack.push(s[i]);
        }

        // Pop all the element, make a string and return.
        while (!stringstack.empty())
        {
            result = stringstack.top() + result;
            stringstack.pop();
        }

        return result;
    }
};

int main()
{
    // std::string input = "3[a2[c3[d]]]";
    // std::string input = "3[a]2[b]c4[d]";

    // std::string input = "3[a]2[bc]";
    // std::string input = "3[a2[c]]";
    // std::string input = "2[abc]3[cd]ef";
    std::string input = "3[z]2[2[y]pq4[2[jk]e1[f]]]ef";

    Solution s;
    std::string result = s.decodeString(input);
    std::cout << "result: " << result << std::endl;
    return 0;
}