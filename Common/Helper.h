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
        TreeNode *convert_string_to_tree(std::string input)
        {
            bool includeNullptr = false;

            std::vector<TreeNode *> v;

            const char *delimiters = ",";

            int inputLen = input.length();
            char tmpInput[inputLen + 1];
            std::strcpy(tmpInput, input.c_str());

            char *token = std::strtok(tmpInput, delimiters);
            while (token)
            {
                std::string data = token;
                if (data.compare("null") == 0)
                {
                    includeNullptr = true;
                    v.push_back(nullptr);
                    std::cout << "push: nullptr" << std::endl;
                }
                else
                {
                    TreeNode *added = new TreeNode(atoi(token));
                    std::cout << "push: " << atoi(token) << std::endl;
                    v.push_back(added);
                }

                token = std::strtok(nullptr, delimiters);
            }

            //return includeNullptr ? convert_string_to_binary_tree(v) : convert_string_to_complete_binary_tree(v);
            return convert_string_to_binary_tree(v);
        }

        ListNode *convert_string_to_list(std::string input)
        {
            ListNode *result = nullptr;

            const char *delimiters = ",";

            int inputLen = input.length();
            char tmpInput[inputLen + 1];
            std::strcpy(tmpInput, input.c_str());

            ListNode *prev = nullptr;
            
            char *token = std::strtok(tmpInput, delimiters);
            while (token)
            {
                std::string data = token;
                ListNode *added = new ListNode(atoi(token));
                
                if(prev != nullptr)
                    prev->next = added;
                else
                    result = added;
            
                prev = added;

                token = std::strtok(nullptr, delimiters);
            }

            return result;
        }

        void print_list(ListNode *head)
        {
            std::cout << "print ListNode [ ";

            if (head == nullptr)
            {
                std::cout << "]" << std::endl;
                return;
            }

            ListNode *cur = head;
            do
            {
                std::cout << cur->val << " ";
                cur = cur->next;
            } while (cur != nullptr);

            std::cout << "]" << std::endl;
        }

        void print_tree(TreeNode* root, int depth)
        {
            std::cout << std::setw(4 * depth) << "";
            if (root == nullptr)
            {
                std::cout << "[Empty]" << std::endl;
            }
            else if (root->left == nullptr && root->right == nullptr)
            {
                std::cout << root->val;
                std::cout << " [leaf]" << std::endl;
            }
            else
            {
                std::cout << root->val << std::endl;
                print_tree(root->right, depth + 1);
                print_tree(root->left, depth + 1);
            }
        }

    private:
        TreeNode *convert_string_to_complete_binary_tree(const std::vector<TreeNode *>& v)
        {
            std::cout << "start convert_string_to_complete_binary_tree!" << std::endl;

            // left child index = 2i+1
            // right child index = 2i+2
            // 인덱스 범위 체크 필수!
            int maximum_index = v.size() - 1;
            for (int i = 0; i < v.size(); i++)
            {
                if (v[i] == nullptr)
                {
                    continue;
                }

                int left_child_idx = 2 * i + 1;
                if (left_child_idx <= maximum_index)
                {
                    v[i]->left = v[left_child_idx];
                }

                int right_child_idx = 2 * i + 2;
                if (right_child_idx <= maximum_index)
                {
                    v[i]->right = v[right_child_idx];
                }
            }

            return v[0];
        }

        TreeNode *convert_string_to_binary_tree(const std::vector<TreeNode *>& v)
        {
            std::cout << "start convert_string_to_binary_tree!" << std::endl;

            if(v.empty())
                return nullptr;
            
            int cur_idx = 0;
            TreeNode* cur = v[cur_idx];

            bool left_force_complete = false;
            bool right_force_complete = false;
            for(int i = 1; i < v.size(); i++)
            {
                if( left_force_complete == true && right_force_complete == true ||
                    cur->left != nullptr && cur->right != nullptr ||
                    left_force_complete == true && cur->right != nullptr ||
                    cur->left != nullptr && right_force_complete == true )
                {
                    cur_idx++;
                    cur = v[cur_idx];
                    
                    if(cur == nullptr)
                    {
                        while(cur == nullptr)
                        {
                            cur_idx++;
                            cur = v[cur_idx];
                        }
                    }

                    left_force_complete = false;
                    right_force_complete = false;
                }

                if(cur->left == nullptr && left_force_complete == false)
                {
                    if(v[i] != nullptr)
                    {
                        cur->left = v[i];
                    }
                    else
                    {
                        left_force_complete = true;
                    }
                    continue;
                }
                    
                if(cur->right == nullptr && right_force_complete == false)
                {
                    if(v[i] != nullptr)
                    {
                        cur->right = v[i];
                    }
                    else
                    {
                        right_force_complete = true;
                    }
                    continue;
                }
            }

            return v[0];
        }
    };
}
