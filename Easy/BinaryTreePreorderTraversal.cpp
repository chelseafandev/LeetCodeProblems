#include <vector>
#include <iostream>
#include "Common/Helper.h"

class Solution {
public:
    std::vector<int> preorderTraversal(TreeNode* root)
    {
        if (root == nullptr)
        {
            return nodes_;
        }

        recursive_solution(root);

        return nodes_;
    }

private:
    void recursive_solution(TreeNode* root)
    {
        if (root == nullptr)
        {
            return;
        }

        nodes_.emplace_back(root->val);
        recursive_solution(root->left);
        recursive_solution(root->right);
    }

    std::vector<int> nodes_;
};

int main()
{
    std::string input = "1,2,3,4,5,6,7";
    util::Helper h;
    TreeNode* root = h.convert_string_to_tree(input);
    
    Solution s;
    auto result = s.preorderTraversal(root);
    std::cout << "[ ";
    for (const auto& val : result)
    {
        std::cout << val << " ";
    }
    std::cout << "]" << std::endl;

    return 0;
}