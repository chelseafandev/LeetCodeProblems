/*
Given the root of a binary tree, invert the tree, and return its root.

Example 1:
Input: root = [4,2,7,1,3,6,9]
Output: [4,7,2,9,6,3,1]

Example 2:
Input: root = [2,1,3]
Output: [2,3,1]

Example 3:
Input: root = []
Output: []

Constraints:
The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100
*/

#include "Common/Helper.h"

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        
    }
};

int main()
{
    std::string input = "4,2,7,1,3,6,9";
    util::Helper h;
    TreeNode* root = h.convert_string_to_tree(input);
    Solution s;
    auto result = s.invertTree(root);
    h.print_tree(result, 0);
    return 0;
}