/*
Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path such that 
adding up all the values along the path equals targetSum. A leaf is a node with no children.


Example 1:
Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
Output: true

Example 2:
Input: root = [1,2,3], targetSum = 5
Output: false

Example 3:
Input: root = [1,2], targetSum = 0
Output: false
 

Constraints:
The number of nodes in the tree is in the range [0, 5000].
-1000 <= Node.val <= 1000
-1000 <= targetSum <= 1000
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
        result_ = false;
    }

    bool hasPathSum(TreeNode *root, int targetSum)
    {
        int partialSum = 0;
        recursiveCall(root, targetSum, partialSum);

        return result_;
    }

private:
    bool result_;

    void recursiveCall(TreeNode *root, int targetSum, int partialSum)
    {
        if(result_)
            return;

        if(root == nullptr)
            return;

        if(root->left == nullptr && root->right == nullptr)
        {
            std::cout << "total = " << root->val + partialSum << std::endl;
            if(root->val + partialSum == targetSum)
                result_ = true;
            
            return;
        }

        int added = root->val + partialSum;

        recursiveCall(root->left, targetSum, added);
        recursiveCall(root->right, targetSum, added);
    }
};

int main()
{
    TreeNode *left1_1 = new TreeNode(11, new TreeNode(7), new TreeNode(2));
    
    TreeNode *left1_2 = new TreeNode(13, nullptr, nullptr);
    TreeNode *right1_2 = new TreeNode(4, nullptr, new TreeNode(1));
    
    TreeNode *left2 = new TreeNode(4, left1_1, nullptr);
    TreeNode *right2 = new TreeNode(8, left1_2, right1_2);

    TreeNode *root = new TreeNode(5, left2, right2);

    int targetSum = 22;

    Solution s;
    
    if(s.hasPathSum(root, targetSum))
        std::cout << "true!" << std::endl;
    else
        std::cout << "false!" << std::endl;

    return 0;
}