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
        std::stack<char> characters;
        std::stack<int> repetitions;

        std::string str_number = "";
        auto start = s.begin();
        while (start != s.end())
        {
            if (*start >= '0' && *start <= '9')
            {
                // repetition number 처리
                // 제약조건에 따라 repetition number 값의 범위는 [1, 300]
                str_number += *start;
            }
            else if (*start == '[')
            {
                // '['인 경우
                // '[' 이전 문자가 숫자인 경우와 아닌 경우로 나누는 이유는 1이 생략된 경우를 처리하기 위해서다(주어진 문제만 봐서는 1이 생략될수있는지 여부를 알기힘들다.. 일단 Wrong Answer를 보고나서야..)
                char previous = *(start - 1);
                if (previous >= '0' && previous <= '9')
                {
                    characters.push(*start);
                    repetitions.push(std::stoi(str_number)); // string to int
                    str_number = ""; // string init
                }
                else
                {
                    characters.push(*start);
                    repetitions.push(1);
                }
            }
            else if (*start == ']')
            {
                // ']'인 경우
                // 1. characters 스택에서 다음 '['가 나올때까지 문자들을 pop해서 문자열을 완성한다. 다만 여기서 완성된 문자열은 다시 한번 reverse(!)해주어야 한다.
                // 2. 1번 과정이 완료된 후에 repetitions 스택에 저장된 숫자가 존재하는 경우 맨위의 값을 꺼내어 생성된 문자열을 그 값만큼 반복해준다.
                // 3. 2번 과정까지 완료된 문자열을 다시 characters 스택에 저장
                std::string added = "";
                while(characters.top() != '[')
                {
                    added = characters.top() + added; // 나중에 reverse 안하려고 여기에서 처리함
                    characters.pop();
                }

                if (characters.top() == '[')
                {
                    characters.pop();
                }

                if (!repetitions.empty())
                {
                    std::string origin = added;
                    added = "";
                    for (int i = 0; i < repetitions.top(); i++)
                    {
                        added += origin;
                    }
                    repetitions.pop();
                }
                
                std::cout << "complete added: " << added << std::endl;

                for (auto& c : added)
                {
                    characters.push(c);
                }
            }
            else
            {
                // character 처리
                characters.push(*start);
            }

            start++;
        }

        std::string result = "";
        while(!characters.empty())
        {
            result = characters.top() + result;
            characters.pop();
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