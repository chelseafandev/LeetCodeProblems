/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
 

Example 1:

Input: s = "()"
Output: true

Example 2:

Input: s = "()[]{}"
Output: true

Example 3:

Input: s = "(]"
Output: false

Example 4:

Input: s = "([)]"
Output: false

Example 5:

Input: s = "{[]}"
Output: true
 

Constraints:

1 <= s.length <= 104
s consists of parentheses only '()[]{}'.
*/
#include <iostream>
#include <stack>

class Solution
{
public:
    bool isValid(std::string s)
    {
        std::stack<char> container;

        std::string::iterator itr;
        for (itr = s.begin(); itr != s.end(); itr++)
        {
            if ((*itr) == '(' || (*itr) == '{' || (*itr) == '[')
            {
                container.push(*itr);
            }
            else
            {
                if (!container.empty())
                {
                    if (*itr == ')' && container.top() == '(')
                    {
                        container.pop();
                    }
                    else if (*itr == '}' && container.top() == '{')
                    {
                        container.pop();
                    }
                    else if (*itr == ']' && container.top() == '[')
                    {
                        container.pop();
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                {
                    return false;
                }
            }
        }

        if (container.empty())
            return true;
        else
            return false;
    }
};

int main()
{
    Solution s;
    std::cout << s.isValid("(])") << std::endl;
    return 0;
}