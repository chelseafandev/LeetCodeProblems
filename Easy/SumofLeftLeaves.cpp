/*
Given the root of a binary tree, return the sum of all left leaves.
A leaf is a node with no children. A left leaf is a leaf that is the left child of another node.


Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: 24
Explanation: There are two left leaves in the binary tree, with values 9 and 15 respectively.

Example 2:
Input: root = [1]
Output: 0
 

Constraints:
The number of nodes in the tree is in the range [1, 1000].
-1000 <= Node.val <= 1000
*/

#include "../Common/Helper.h"
#include <iostream>

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root)
    {
        int sum = 0;
        find_left_leaf(root, false, sum);
        
        std::cout << "sum : " << sum << std::endl;
        return sum;
    }

private:
    void find_left_leaf(TreeNode* root, bool is_left, int& sum)
    {
        if (root == nullptr)
        {
            return;
        }
        
        if (root->left == nullptr && root->right == nullptr)
        {
            if (is_left == false)
            {
                return;
            }

            sum += root->val;
            return;
        }

        find_left_leaf(root->left, true, sum);
        find_left_leaf(root->right, false, sum);
    }
};

int main()
{
    std::string input = "3,9,20,null,null,15,7";
    util::Helper h;
    auto root = h.convert_string_to_tree(input);
    h.print_tree(root, 0);

    Solution s;
    std::cout << s.sumOfLeftLeaves(root) << std::endl;
    return 0;
}