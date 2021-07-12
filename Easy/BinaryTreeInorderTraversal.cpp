/*
Given the root of a binary tree, return the inorder traversal of its nodes' values.

 
Example 1:
Input: root = [1,null,2,3]
Output: [1,3,2]

Example 2:
Input: root = []
Output: []

Example 3:
Input: root = [1]
Output: [1]

Example 4:
Input: root = [1,2]
Output: [2,1]

Example 5:
Input: root = [1,null,2]
Output: [1,2]
 

Constraints:
The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
*/
#include <iostream>
#include <vector>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    std::vector<int> inorderTraversal(TreeNode* root)
    {
        std::vector<int> output;

        if(root != nullptr)
        {
            recursiveTraveral(root, output);
        }

        return output;
    }

private:
    void recursiveTraveral(TreeNode* root, std::vector<int>& output)
    {
        if(root != nullptr)
        {
            recursiveTraveral(root->left, output);
            output.push_back(root->val);
            recursiveTraveral(root->right, output);
        }
    }
};

int main()
{
    TreeNode *leftSubTree = new TreeNode(9, nullptr, nullptr);
    TreeNode *rightSubTree = new TreeNode(20, new TreeNode(17), new TreeNode(7));
    TreeNode *p = new TreeNode(3, leftSubTree, rightSubTree);

    std::vector<int> result;
    std::vector<int>::iterator itr;
    Solution s;
    result = s.inorderTraversal(p);

    for(itr = result.begin(); itr != result.end(); itr++)
    {
        std::cout << *itr << " " << std::endl;
    }

    return 0;
}