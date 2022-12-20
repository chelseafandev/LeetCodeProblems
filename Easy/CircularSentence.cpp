#include <vector>
#include <iostream>

class Solution {
public:
    bool isCircularSentence(std::string sentence)
    {
        int len = sentence.length();

        if (sentence[0] != sentence[len-1])
        {
            return false;
        }

        // single word
        std::size_t idx = sentence.find_first_of(' ', 0);
        if (idx == std::string::npos)
        {
            return true;
        }
        
        std::vector<std::string> words;
        std::size_t start_position = 0; // start position for substr
        std::size_t prev_idx = -1;
        while(idx != std::string::npos)
        {
            // original string 기준으로 idx값을 추출함
            words.emplace_back(sentence.substr(start_position, idx - prev_idx - 1));

            prev_idx = idx;
            start_position = idx + 1;
            idx = sentence.find_first_of(' ', start_position);
        }

        // last word
        words.emplace_back(sentence.substr(start_position, idx - prev_idx - 1));
        
        // check circular
        int words_size = words.size();
        for (int i = 0; i < words_size - 1; i++)
        {
            if (words[i][words[i].length() - 1] != words[i+1][0])
            {
                return false;
            }
        }

        return true;
    }
};

int main()
{
    Solution s;
    std::string sentence = "leetcode exercises sound delightful";
    std::cout << std::boolalpha << s.isCircularSentence(sentence) << std::endl;
    return 0;
}