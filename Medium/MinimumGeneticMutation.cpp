/*
A gene string can be represented by an 8-character long string, with choices from 'A', 'C', 'G', and 'T'.
Suppose we need to investigate a mutation from a gene string start to a gene string end where one mutation is defined as one single character changed in the gene string.
    For example, "AACCGGTT" --> "AACCGGTA" is one mutation.

There is also a gene bank bank that records all the valid gene mutations. A gene must be in bank to make it a valid gene string.
Given the two gene strings start and end and the gene bank bank, return the minimum number of mutations needed to mutate from start to end. If there is no such a mutation, return -1.
Note that the starting point is assumed to be valid, so it might not be included in the bank.


Example 1:
Input: start = "AACCGGTT", end = "AACCGGTA", bank = ["AACCGGTA"]
Output: 1

Example 2:
Input: start = "AACCGGTT", end = "AAACGGTA", bank = ["AACCGGTA","AACCGCTA","AAACGGTA"]
Output: 2

Example 3:
Input: start = "AAAAACCC", end = "AACCCCCC", bank = ["AAAACCCC","AAACCCCC","AACCCCCC"]
Output: 3
 

Constraints:
start.length == 8
end.length == 8
0 <= bank.length <= 10
bank[i].length == 8
start, end, and bank[i] consist of only the characters ['A', 'C', 'G', 'T'].
 */

#include <iostream>
#include <vector>
#include <queue>
#include <set>

class Solution
{
public:
    int minMutation(std::string start, std::string end, std::vector<std::string> &bank)
    {
        // start가 end가 되기위해 필요한 최소한의 mutation의 횟수를 구하는것이 문제 (`1 mutation` is `one single character changed in the gene string`)
        std::vector<char> candidate = {'A', 'C', 'G', 'T'};
        std::set<std::string> dict(bank.begin(), bank.end());

        if (dict.find(end) == dict.end())
        {
            return -1;
        }
            
        int result = 0;
        std::queue<std::string> q;
        q.push(start);

        while (!q.empty())
        {
            int n = q.size();
            for (int i = 0; i < n; i++)
            {
                std::string popped = q.front();
                q.pop();

                if (popped == end)
                {
                    return result;
                }
                    
                dict.erase(popped);

                // popped된 8자리의 gene string에서 1개의 문자만 바뀌는 케이스들을 모두 구해서 유효한 mutation이 있는지를 dict에서 조회
                for (int j = 0; j < 8; j++)
                {
                    char c = popped[j];
                    for (int k = 0; k < 4; k++)
                    {
                        popped[j] = candidate[k];
                        if (dict.find(popped) != dict.end())
                        {
                            q.push(popped);
                            std::cout << "push: " << popped << std::endl;
                        }
                    }
                    popped[j] = c; // 원복
                }
            }

            result++;
            std::cout << "result: " << result << std::endl;
        }

        return -1;
    }
};

int main()
{
    std::string start = "AAAAACCC";
    std::string end = "AACCCCCC";
    std::vector<std::string> bank = {"AAAACCCC","AAACCCCC","AACCCCCC"};
    
    Solution s;
    std::cout << s.minMutation(start, end, bank) << std::endl;
    
    return 0;
}