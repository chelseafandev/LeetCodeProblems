/*
Given a binary tree, determine if it is height-balanced.
For this problem, a height-balanced binary tree is defined as:
a binary tree in which the left and right subtrees of every node differ in height by no more than 1.


Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: true

Example 2:
Input: root = [1,2,2,3,3,null,null,4,4]
Output: false

Example 3:
Input: root = []
Output: true

Constraints:
The number of nodes in the tree is in the range [0, 5000].
-10^4 <= Node.val <= 10^4
*/

#include "Common/Helper.h"
#include <iostream>

class Solution
{
public:
    Solution()
    {
        isBalanced_ = true;
    }

    bool isBalanced(TreeNode *root)
    {
        recursiveCall(root, 0);
        return isBalanced_;
    }

private:
    bool isBalanced_;

    int recursiveCall(TreeNode *root, int h)
    {
        if(root == nullptr)
            return h;

        int added = h + 1;
        int left_depth = recursiveCall(root->left, added);
        std::cout << "h: " << h << " root->val: " << root->val << " left_depth = " << left_depth << std::endl;
        int right_depth = recursiveCall(root->right, added);
        std::cout << "h: " << h << " root->val: " << root->val << " right_depth = " << right_depth << std::endl;

        int larger = 0;
        int diff = 0;
        if(left_depth > right_depth)
        {
            larger = left_depth;
            diff = left_depth - right_depth;
        }
        else
        {
            larger = right_depth;
            diff = right_depth - left_depth;
        }

        if(diff > 1)
        {
            isBalanced_ = false;
        }

        return larger;
    }
};

int main()
{  
    std::string input = "1,2,2,3,3,null,null,4,4";
    util::Helper helper;
    TreeNode* root = helper.convertStr2Tree(input);

    Solution s;
    std::cout << s.isBalanced(root) << std::endl;
    return 0;
}