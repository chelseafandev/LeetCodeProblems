/*
Given a binary tree, find its minimum depth.
The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
Note: A leaf is a node with no children.

Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: 2

Example 2:
Input: root = [2,null,3,null,4,null,5,null,6]
Output: 5

Constraints:
The number of nodes in the tree is in the range [0, 10^5].
-1000 <= Node.val <= 1000
*/

#include <iostream>

#include "Common/Helper.h"

class Solution
{
public:
    Solution()
    {
        min_depth_ = 0;
    }

    int minDepth(TreeNode* root)
    {
        recursiveCall(root, 1);
        return min_depth_;
    }
private:
    int min_depth_;

    void recursiveCall(TreeNode* root, int d)
    {
        if(root == nullptr)
            return;

        if(root->left == nullptr && root->right == nullptr)
        {
            std::cout << "depth: " << d << std::endl;
            if(min_depth_ == 0)
            {
                min_depth_ = d;
            }
            else
            {
                if(min_depth_ > d)
                    min_depth_ = d;
            }
            return;
        }

        int added = d + 1;
        recursiveCall(root->left, added);
        recursiveCall(root->right, added);
    }
};

int main()
{
    std::string input = "3,9,20,null,null,15,7";

    util::Helper helper;
    TreeNode* root = helper.convertStr2BinaryTree(input);
    
    Solution s;
    std::cout << s.minDepth(root) << std::endl;
    return 0;
}