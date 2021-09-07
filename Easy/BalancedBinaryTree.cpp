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

#include <iostream>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

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
    /* 
    // example1
    TreeNode *left = new TreeNode(9, nullptr, nullptr);
    TreeNode *right = new TreeNode(20, new TreeNode(15), new TreeNode(7));
    TreeNode *root = new TreeNode(3, left, right);
    */

    /*
    // example2
    TreeNode *leftOfleft = new TreeNode(3, new TreeNode(4), new TreeNode(4));
    TreeNode *left = new TreeNode(2, leftOfleft, new TreeNode(3));
    TreeNode *root = new TreeNode(3, left, new TreeNode(2));
    */

    /*
    // example3
    TreeNode *root = nullptr;
    */

    // example4
    TreeNode *rightOfright = new TreeNode(1, nullptr, new TreeNode(4));
    TreeNode *right = new TreeNode(10, new TreeNode(2), rightOfright);

    TreeNode *leftOfleft = new TreeNode(3, new TreeNode(8), nullptr);
    TreeNode *left = new TreeNode(9, leftOfleft, nullptr);
    TreeNode *root = new TreeNode(7, left, right);

    Solution s;
    std::cout << s.isBalanced(root) << std::endl;
    return 0;
}