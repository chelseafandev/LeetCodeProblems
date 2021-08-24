/*
Given two strings s and t, determine if they are isomorphic.
Two strings s and t are isomorphic if the characters in s can be replaced to get t.
All occurrences of a character must be replaced with another character while preserving the order of characters. 
No two characters may map to the same character, but a character may map to itself.

Example 1:
Input: s = "egg", t = "add"
Output: true

Example 2:
Input: s = "foo", t = "bar"
Output: false

Example 3:
Input: s = "paper", t = "title"
Output: true
 

Constraints:
1 <= s.length <= 5 * 10^4
t.length == s.length
s and t consist of any valid ascii character.
*/

#include <iostream>
#include <vector>
#include <map>

class Solution
{
public:
    bool isIsomorphic(std::string s, std::string t)
    {
        std::vector<int> s_char_to_pattern;
        std::vector<int> t_char_to_pattern;
        
        makePattern(s, s_char_to_pattern);
        makePattern(t, t_char_to_pattern);
        
        int size = s_char_to_pattern.size();
        for(int j = 0; j < size; j++)
        {
            if(s_char_to_pattern[j] != t_char_to_pattern[j])
            {
                return false;
            }
        }

        return true;
    }

private:
    void makePattern(std::string s, std::vector<int>& output_vector)
    {
        int ascii_count[128] = {0, };
        
        std::map<char, int> s_map;

        int label = 0;
        int idx = 0;

        std::string::iterator itr;
        for(itr = s.begin(); itr != s.end(); itr++)
        {
            idx = *itr;
            if(ascii_count[idx] == 0)
            {
                s_map[idx] = label;
                std::cout << "1. output_vector.push_back: " << label << std::endl;
                output_vector.push_back(label);
                label++;
            }
            else
            {
                // find 함수에 대한 예외 처리 필요없음. ascii_count[idx]가 0이 아닌 조건 자체가 key에 해당하는 value가 맵에 반드시 존재한다는 의미!
                auto val = s_map.find(idx);
                std::cout << "2. output_vector.push_back: " << val->second << std::endl;
                output_vector.push_back(val->second);
            }

            ascii_count[idx]++;
        }
    }
};

int main()
{
    std::string s = "paper";
    std::string t = "title";

    Solution sol;
    if(sol.isIsomorphic(s, t))
    {
        std::cout << s << " & " << t << " is isomorphic!" << std::endl;
    }
    else
    {
        std::cout << s << " & " << t << " is not isomorphic!" << std::endl;
    }

    return 0;
}