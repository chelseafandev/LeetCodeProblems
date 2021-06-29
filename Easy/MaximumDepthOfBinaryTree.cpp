/*
Given the root of a binary tree, return its maximum depth.
A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: 3

Example 2:
Input: root = [1,null,2]
Output: 2

Example 3:
Input: root = []
Output: 0

Example 4:
Input: root = [0]
Output: 1
 

Constraints:
The number of nodes in the tree is in the range [0, 10^4].
-100 <= Node.val <= 100
*/
#include <iostream>
#include <stack>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

struct TreeNodeWithDepth
{
    int depth;
    TreeNode *node;
};

class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        int max_depth = 0;
        std::stack<TreeNodeWithDepth *> stack_dfs;

        if (root != nullptr)
        {
            TreeNodeWithDepth *newNode = new TreeNodeWithDepth();
            newNode->depth = 1;
            newNode->node = root;
            stack_dfs.push(newNode);
        }

        while (!stack_dfs.empty())
        {
            TreeNodeWithDepth *top = stack_dfs.top();
            stack_dfs.pop();

            if (top->node->left != nullptr)
            {
                TreeNodeWithDepth *newNode = new TreeNodeWithDepth();
                newNode->depth = top->depth + 1;
                newNode->node = top->node->left;
                stack_dfs.push(newNode);
            }

            if (top->node->right != nullptr)
            {
                TreeNodeWithDepth *newNode = new TreeNodeWithDepth();
                newNode->depth = top->depth + 1;
                newNode->node = top->node->right;
                stack_dfs.push(newNode);
            }

            if (max_depth < top->depth)
            {
                max_depth = top->depth;
            }
        }

        return max_depth;
    }
};

int main()
{
    // [3,9,20,null,null,15,7]
    TreeNode *leftSubTree = new TreeNode(9, nullptr, nullptr);
    TreeNode *rightSubTree = new TreeNode(20, new TreeNode(17), new TreeNode(7));
    TreeNode *p = new TreeNode(3, leftSubTree, rightSubTree);

    Solution s;
    std::cout << s.maxDepth(p) << std::endl;
    return 0;
}