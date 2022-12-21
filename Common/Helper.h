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
            if (inputLen == 0)
            {
                return nullptr;
            }

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

        SpecialNode *convert_string_to_tree_for_special_node(std::string input)
        {
            bool includeNullptr = false;

            std::vector<SpecialNode *> v;

            const char *delimiters = ",";

            int inputLen = input.length();
            if (inputLen == 0)
            {
                return nullptr;
            }

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
                    SpecialNode *added = new SpecialNode(atoi(token));
                    std::cout << "push: " << atoi(token) << std::endl;
                    v.push_back(added);
                }

                token = std::strtok(nullptr, delimiters);
            }

            return convert_string_to_binary_tree(v);
        }

        ListNode *convert_string_to_list(std::string input)
        {
            ListNode *result = nullptr;

            const char *delimiters = ",";

            int inputLen = input.length();
            if (inputLen == 0)
            {
                return nullptr;
            }
            
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
        template <typename T>
        T* convert_string_to_complete_binary_tree(const std::vector<T*>& v)
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
        
        // v: left와 right가 모두 nullptr인 val만 존재하는 TreeNode*가 저장된 벡터
        // 해당 함수를 통해 left와 right를 완성해나간다
        template <typename T>
        T* convert_string_to_binary_tree(const std::vector<T*>& v)
        {
            std::cout << "start convert_string_to_binary_tree!" << std::endl;

            if(v.empty())
                return nullptr;
            
            int cur_idx = 0;
            T* cur = v[cur_idx];

            bool left_is_empty = false; // 왼쪽 자식 노드를 채우려고 딱 봤는데 해당 노드가 nullptr인 경우에 true로 변경(채웠다고 생각하고 다음 노드로 넘어가기 위해 사용함)
            bool right_is_empty = false; // 오른쪽 자식 노드를 채우려고 딱 봤는데 해당 노드가 nullptr인 경우에 true로 변경(채웠다고 생각하고 다음 노드로 넘어가기 위해 사용함)
            for(int i = 1; i < v.size(); i++) // 벡터 v의 index는 1부터 시작함
            {
                // 다음 노드를 선택하기 위한 cursor 값 변경(아래 if문 조건이 cursor 값을 변경하기 위한 조건임)
                if( (left_is_empty == true && right_is_empty == true) ||    // 왼쪽, 오른쪽 자식 노드가 둘다 nullptr로 채워진 경우
                    (cur->left != nullptr && cur->right != nullptr) ||      // 왼쪽, 오른쪽 자식 노드가 둘다 nullptr이 아닌 값으로 채워진 경우
                    (left_is_empty == true && cur->right != nullptr) ||     // 왼쪽 자식 노드는 nullptr로 오른쪽 자식 노드는 nullptr이 아닌 값으로 채워진 경우
                    (cur->left != nullptr && right_is_empty == true) )      // 오른쪽 자식 노드는 nullptr로 왼쪽 자식 노드는 nullptr이 아닌 값으로 채워진 경우
                {
                    cur_idx++;
                    cur = v[cur_idx];
                    
                    // 벡터 v에 nullptr이 연속해서 저장되어있는 경우 처리
                    if(cur == nullptr)
                    {
                        // Tree 입력으로 전달되는 문자열의 마지막이 null인 경우(무한루프에 빠지는 경우)가 존재하는가? No!
                        while(cur == nullptr)
                        {
                            cur_idx++;
                            cur = v[cur_idx];
                        }
                    }

                    left_is_empty = false;
                    right_is_empty = false;
                }

                // 왼쪽 자식 노드 연결
                if(cur->left == nullptr && left_is_empty == false)
                {
                    if(v[i] != nullptr)
                    {
                        cur->left = v[i];
                    }
                    else
                    {
                        left_is_empty = true;
                    }
                    continue;
                }
                    
                // 오른쪽 자식 노드 연결
                if(cur->right == nullptr && right_is_empty == false)
                {
                    if(v[i] != nullptr)
                    {
                        cur->right = v[i];
                    }
                    else
                    {
                        right_is_empty = true;
                    }
                    continue;
                }
            }

            return v[0];
        }
    };
}
