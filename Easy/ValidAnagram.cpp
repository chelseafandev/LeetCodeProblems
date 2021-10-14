/*
Given two strings s and t, return true if t is an anagram of s, and false otherwise.

Example 1:
Input: s = "anagram", t = "nagaram"
Output: true

Example 2:
Input: s = "rat", t = "car"
Output: false
 

Constraints:
1 <= s.length, t.length <= 5 * 10^4
s and t consist of lowercase English letters.
 

Follow up: What if the inputs contain Unicode characters? How would you adapt your solution to such a case?
*/

#include <iostream>

class Solution
{
public:
    bool isAnagram(std::string s, std::string t)
    {
        int alphabet_count[26] = {0, };

        for (auto ch : s)
        {
            int idx = ch % 97;
            alphabet_count[idx]++;
        }

        for (auto ch : t)
        {
            int idx = ch % 97;
            if (alphabet_count[idx] != 0)
            {
                alphabet_count[idx]--;
            }
            else
            {
                std::cout << "thers is no '" << ch << "' in input \"s\"" << std::endl;
                return false;
            }
        }

        for(auto cnt : alphabet_count)
        {
            if (cnt != 0)
                return false;
        }

        return true;
    }
};

int main()
{
    std::string ss = "ab";
    std::string tt = "a";

    Solution s;
    std::cout << std::boolalpha << s.isAnagram(ss, tt) << std::endl;
    return 0;
}