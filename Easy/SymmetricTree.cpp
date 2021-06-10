/*
Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

Example 1:
Input: root = [1,2,2,3,4,4,3]
Output: true

Example 2:
Input: root = [1,2,2,null,3,null,3]
Output: false


Constraints:
The number of nodes in the tree is in the range [1, 1000].
-100 <= Node.val <= 100
*/
#include <iostream>
#include <vector>
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

class Solution
{
public:
    bool isSymmetric(TreeNode *root)
    {
        std::vector<int> left_result;
        std::vector<int> right_result;

        left_result = dfs(root->left, true);
        right_result = dfs(root->right, false);

        if (left_result.size() != right_result.size())
        {
            return false;
        }

        int result_size = left_result.size();
        for (int i = 0; i < result_size; i++)
        {
            if (left_result[i] != right_result[i])
            {
                return false;
            }
        }

        return true;
    }

    std::vector<int> dfs(TreeNode *root, bool isLeft)
    {
        std::vector<int> result;

        if (root == nullptr)
        {
            return result;
        }

        std::stack<TreeNode *> dfs_stack;
        dfs_stack.push(root);
        while (!dfs_stack.empty())
        {
            TreeNode *top = dfs_stack.top();
            dfs_stack.pop();
            if (top == nullptr)
            {
                std::cout << "push_back(top is nullptr): " << 101 << std::endl;
                result.push_back(101);
            }
            else
            {
                std::cout << "push_back: " << top->val << std::endl;
                result.push_back(top->val);
                if (isLeft)
                {
                    std::cout << "[left]" << std::endl;
                    dfs_stack.push(top->left);
                    dfs_stack.push(top->right);
                }
                else
                {
                    std::cout << "[right]" << std::endl;
                    dfs_stack.push(top->right);
                    dfs_stack.push(top->left);
                }
            }
        }

        std::cout << std::endl;
        return result;
    }
};

int main()
{
    //TreeNode *leftSubTree = new TreeNode(2, new TreeNode(3), new TreeNode(4));
    //TreeNode *rightSubTree = new TreeNode(2, new TreeNode(4), new TreeNode(3));
    TreeNode *leftSubTree = new TreeNode(2, nullptr, new TreeNode(3));
    TreeNode *rightSubTree = new TreeNode(2, nullptr, new TreeNode(3));
    TreeNode *p = new TreeNode(1, leftSubTree, rightSubTree);

    Solution s;
    std::cout << s.isSymmetric(p) << std::endl;
    return 0;
}