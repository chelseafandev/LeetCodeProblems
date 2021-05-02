/*
Given a string s, return the longest palindromic substring in s.

 

Example 1:

Input: s = "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"
Example 3:

Input: s = "a"
Output: "a"
Example 4:

Input: s = "ac"
Output: "a"
 

Constraints:

1 <= s.length <= 1000
s consist of only digits and English letters (lower-case and/or upper-case),
*/
#include <iostream>

class Solution
{
public:
    std::string longestPalindrome(std::string s)
    {
        std::string strRet;
        int nMax = 0;
        for (int i = 0; i < s.length(); i++)
        {
            std::string::iterator itr = s.begin() + i;
            std::string tmpSubstr = "";

            int nLen = 0;
            bool isPalin = false;
            while (itr != s.end())
            {
                tmpSubstr += *itr;
                nLen = tmpSubstr.length();
                // nMax보다 큰 substring에 대해서만 palindrome 여부 검사를 하겠다.
                if (nLen > nMax)
                {
                    isPalin = isPalindrome(tmpSubstr);
                    if (isPalin)
                    {
                        nMax = nLen;
                        strRet = tmpSubstr;
                    }
                }
                itr++;
            }
        }

        return strRet;
    }

private:
    bool isPalindrome(std::string &substr)
    {
        // iterator와 reverse_iterator 활용해서 palindrome 여부 체크
        std::string::iterator itr = substr.begin();
        std::string::reverse_iterator ritr;
        for (ritr = substr.rbegin(); ritr != substr.rend(); ritr++)
        {
            if (*itr != *ritr)
            {
                return false;
            }

            itr++;
        }

        return true;
    }
};

int main()
{
    Solution s;
    //std::string input = "jrjnvwefdlrgndirjhnedkweghthflknfuerkjnduwdfgkjeridfgkweglkjdfigdrthysdffbtywefyjsdfehhrthasdqnerwegergqwdfnrthjwefqthryhjasdfdhgergtefbjefqdfrhwefwgergegqsdqerbdfgthwerglmrowhrh4qefdhrgbctoqgzimtoklkxcknwmhiztomaofwwzjnhrijwkgmwwuazcowskjhitejnvtblqyepxispasrgvgzqlvrmvhxusiqqzzibcyhpnruhrgbzsmlsuacwptmzxuewnjzmwxbdzqyvsjzxiecsnkdibudtvthzlizralpaowsbakzconeuwwpsqynaxqmgngzpovauxsqgypinywwtmekzhhlzaeatbzryreuttgwfqmmpeywtvpssznkwhzuqewuqtfuflttjcxrhwexvtxjihunpywerkktbvlsyomkxuwrqqmbmzjbfyfkridnfldkrjgldfkneirmngekjaiemngialkdmdfkwejrmndlrjkgndkrigndjkriogjfdfuirnsdfglsdfkljwefoisjwelkftdddnkasmdyukawrzrnhdmaefzltddipcrhuchvdcoegamlfifzistnplqabtazunlelslicrkuuhosoyduhootlwsbtxautewkvnvlbtixkmxhngidxecehslqjpcdrtlqswmyghmwlttjecvbueswsixoxmymcepbmuwtzanmvujmalyghzkvtoxynyusbpzpolaplsgrunpfgdbbtvtkahqmmlbxzcfznvhxsiytlsxmmtqiudyjlnbkzvtbqdsknsrknsykqzucevgmmcoanilsyyklpbxqosoquolvytefhvozwtwcrmbnyijbammlzrgalrymyfpysbqpjwzirsfknnyseiujadovngogvptphuyzkrwgjqwdhtvgxnmxuheofplizpxijfytfabx";
    std::string input = "0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000";
    std::cout << s.longestPalindrome(input) << std::endl;
    return 0;
}