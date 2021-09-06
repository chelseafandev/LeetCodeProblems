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
    bool isBalanced(TreeNode *root)
    {
        bool bRet = false;
        recursiveCall(root, 0);
        return bRet;

    }

private:
    void recursiveCall(TreeNode *root, int h)
    {
        if(root == nullptr)
        {
            std::cout << h << std::endl;
            return;
        }
            
        
        int added = h + 1;
        recursiveCall(root->left, added);
        recursiveCall(root->right, added);
    }
};

int main()
{
    TreeNode *left = new TreeNode(9, nullptr, nullptr);
    TreeNode *right = new TreeNode(20, new TreeNode(15), new TreeNode(7));
    TreeNode *root = new TreeNode(3, left, right);
    
    Solution s;
    std::cout << s.isBalanced(root) << std::endl;
    return 0;
}