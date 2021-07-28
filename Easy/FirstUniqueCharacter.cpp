/*
Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.

Example 1:
Input: s = "leetcode"
Output: 0

Example 2:
Input: s = "loveleetcode"
Output: 2

Example 3:
Input: s = "aabb"
Output: -1
 

Constraints:
1 <= s.length <= 10^5
s consists of only lowercase English letters.
*/
#include <iostream>

class Solution
{
public:
    int firstUniqChar(std::string s)
    {
        int alphabet_count[26] = {0, };
        int len = s.length();
        for(int i = 0; i < len; i++)
        {
            alphabet_count[s[i] - 'a']++;
        }

        for(int i = 0; i < len; i++)
        {
            int tmp_idx = s[i] - 'a';
            if(alphabet_count[tmp_idx] == 1)
            {
                return i;
            }
        }

        return -1;
    }
};

int main()
{
    std::string input = "leetcode";
    Solution s;
    std::cout << "result: " << s.firstUniqChar(input) << std::endl;
    return 0;
}
