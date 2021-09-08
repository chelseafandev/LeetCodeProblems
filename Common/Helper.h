#pragma

#include <iostream>
#include <cstring>
#include <iomanip>
#include <queue>

#include "Type.h"

namespace util
{
    class Helper
    {
    public:
        TreeNode* convertStr2BinaryTree(std::string input)
        {
            std::vector<TreeNode*> v;

            const char *delimiters = ",";
            
            int inputLen = input.length();
            char tmpInput[inputLen + 1];
            std::strcpy(tmpInput, input.c_str());

            char *token = std::strtok(tmpInput, delimiters);
            while (token)
            {
                std::string data = token;
                if(data.compare("null") == 0)
                {
                    v.push_back(nullptr);
                    std::cout << "push: nullptr" << std::endl;
                }
                else
                {
                    TreeNode* added = new TreeNode(atoi(token));
                    std::cout << "push: " << atoi(token) << std::endl;
                    v.push_back(added);
                }
                
                token = std::strtok(nullptr, delimiters);
            }

            // left child index = 2i+1
            // right child index = 2i+2
            // 인덱스 범위 체크 필수!
            int maximum_index = v.size() - 1;
            for(int i = 0; i < v.size(); i++)
            {
                if(v[i] == nullptr)
                {
                    continue;
                }

                int left_child_idx = 2*i + 1;
                if(left_child_idx <= maximum_index)
                {
                    v[i]->left = v[left_child_idx];
                }

                int right_child_idx = 2*i + 2;
                if(right_child_idx <= maximum_index)
                {
                    v[i]->right = v[right_child_idx];
                }
            }

            return v[0];
        }

    private:
    };
}