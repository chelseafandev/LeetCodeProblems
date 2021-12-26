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
#include <vector>

class Solution
{
public:
    std::string decodeString(std::string s)
    {
        // no repetition
        if (s[0] < '0' || s[0] > '9')
        {
            return s;
        }

        std::stack<std::string> brackets;
        std::stack<std::string> characters;
        std::stack<int> repetition;

        // for tracking
        std::string::iterator cur = s.begin();

        repetition.push(*cur - '0');
        std::cout << "push repetition : " << *cur - '0' << std::endl;
        cur++;

        bool no_more_push_in_nested = false;
        std::string character = "";
        std::stack<std::string> nested;
        while (cur != s.end())
        {
            if (*cur == '[')
            {
                if(brackets.empty())
                {
                    brackets.push("[");
                }
                else
                {
                    brackets.push("[");
                    std::cout << "push nested : " << character << std::endl;
                    nested.push(character); // construct nested bracket
                    character = "";
                }
            }
            else if (*cur == ']')
            {
                brackets.pop();

                if (brackets.empty())
                {
                    if(nested.empty())
                    {
                        std::cout << "complete character : " << character << std::endl;
                        characters.push(character); // complete character
                        character = "";             // init character
                    }
                    else
                    {
                        std::string candidate = "";
                        std::string top = nested.top();
                        for (int i = 0; i < repetition.top(); i++)
                        {
                            std::string tmp = top + character;
                            candidate += tmp;
                        }
                        character = candidate;
                        std::cout << "complete character : " << character << std::endl;
                        characters.push(character); // complete character
                        character = "";             // init character
                        nested.pop();
                        repetition.pop();
                    }
                }
                else
                {
                    if(!nested.empty() && !no_more_push_in_nested)
                    {
                        std::cout << "push nested : " << character << std::endl;
                        nested.push(character); // construct nested bracket
                        character = "";
                    }

                    if(character.compare("") == 0)
                    {
                        for (int i = 0; i < repetition.top(); i++)
                        {
                            character += nested.top();
                        }
                        std::cout << "(empty character) construct character: " << character << std::endl;
                        no_more_push_in_nested = true;
                    }
                    else
                    {
                        std::string candidate = "";
                        std::string top = nested.top();
                        for (int i = 0; i < repetition.top(); i++)
                        {
                            std::string tmp = top + character;
                            candidate += tmp;
                        }
                        character = candidate;
                    }
                    nested.pop();
                    repetition.pop();
                }
            }
            else if (*cur >= '0' && *cur <= '9')
            {
                std::cout << "push repetition : " << *cur - '0' << std::endl;
                repetition.push(*cur - '0');
            }
            else
            {
                // construct character
                character += *cur;
                std::cout << "construct character : " << character << std::endl;
                
                if(brackets.empty())
                {
                    repetition.push(1);
                    characters.push(character);
                    character = "";
                }
            }

            cur++;
        }

        // make result
        std::vector<std::string> v;
        std::string added = "";
        while (!repetition.empty())
        {
            for (int i = 0; i < repetition.top(); i++)
            {
                added += characters.top();
            }
            v.push_back(added);
            added.clear();

            repetition.pop();
            characters.pop();
        }

        std::string result = "";
        for(auto ritr = v.rbegin(); ritr != v.rend(); ritr++)
        {
            result += *ritr;
        }

        return result.empty() ? characters.top() : result;
    }
};

int main()
{
    //std::string input = "3[a2[c3[d]]]";
    //std::string input = "3[a]2[b]c4[d]";
    
    //std::string input = "3[a]2[bc]";
    //std::string input = "3[a2[c]]";
    std::string input = "2[abc]3[cd]ef";

    Solution s;
    std::string result = s.decodeString(input);
    std::cout << "result = " << result << std::endl;
    return 0;
}