/*
Given the root of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root. 

The length of a path between two nodes is represented by the number of edges between them.


Example 1:
Input: root = [1,2,3,4,5]
Output: 3
Explanation: 3 is the length of the path [4,2,1,3] or [5,2,1,3].

Example 2:
Input: root = [1,2]
Output: 1


Constraints:
The number of nodes in the tree is in the range [1, 10^4].
-100 <= Node.val <= 100
*/

#include <iostream>

#include "Common/Helper.h"

class Solution
{
public:
    Solution() 
    {
        diameter_ = 0;
    }

    int diameterOfBinaryTree(TreeNode *root)
    {
        get_diameter(root);
        return diameter_;
    }

private:
    int get_diameter(TreeNode* node)
    {
        if (node == nullptr)
        {
            return 0;
        }

        int left_height = get_diameter(node->left);
        int right_height = get_diameter(node->right);
        diameter_ = diameter_ > left_height + right_height ? diameter_ : left_height + right_height;
        return (left_height > right_height ? left_height : right_height) + 1;
    }

    int diameter_;
};

int main()
{
    util::Helper helper;
    std::string root = "1,2,3,4,5,6,7,8,9,10";
    TreeNode* input = helper.convertStr2Tree(root);

    Solution s;
    int reulst = s.diameterOfBinaryTree(input);
    std::cout << "result: " << reulst << std::endl;
    return 0;
}