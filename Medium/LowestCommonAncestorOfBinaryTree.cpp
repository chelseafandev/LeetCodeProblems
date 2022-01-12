/*
Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

Example 1:
Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.

Example 2:
Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
Output: 5
Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.

Example 3:
Input: root = [1,2], p = 1, q = 2
Output: 1

Constraints:
The number of nodes in the tree is in the range [2, 10^5].
-10^9 <= Node.val <= 10^9
All Node.val are unique.
p != q
p and q will exist in the tree.
*/

#include <iostream>
#include <deque>

#include "Common/Helper.h"

class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        p_val_ = p->val;
        q_val_ = q->val;

        std::deque<int> path;
        find_path(root, path);

        // 전략
        // p와 q 노드에 도달하는 path 정보(from root to node p, q)를 저장해두고 양쪽 path에서 중복되는 노드 정보를 찾는다. 중복되는 노드들 중 가장 마지막 노드가 LCA다!
        // 노드 p까지 도달하는 path를 기준으로 노드 q까지 도달하는 path를 비교한다.
        int lca_val = 0;
        while (!p_path_.empty())
        {
            // q is empty
            if (q_path_.empty())
            {
                break;
            }

            // not equal
            if (p_path_.front() != q_path_.front())
            {
                break;
            }

            // equal
            lca_val = p_path_.front(); // update lca value
            p_path_.pop_front();
            q_path_.pop_front();
        }

        return new TreeNode(lca_val);
    }

private:
    // root에서부터 노드 p, q까지 도달하는 path를 구하는 함수
    // 재귀 호출을 활용하여 path를 tracking한다
    void find_path(TreeNode *root, std::deque<int> &path)
    {
        if (root == nullptr)
        {
            return;
        }

        path.push_back(root->val);
        if (root->val == p_val_)
        {
            p_path_ = path;
        }
        else if (root->val == q_val_)
        {
            q_path_ = path;
        }

        find_path(root->left, path);
        find_path(root->right, path);
        path.pop_back();
    }

    int p_val_;
    std::deque<int> p_path_;

    int q_val_;
    std::deque<int> q_path_;
};

int main()
{
    // std::string input = "3,5,1,6,2,0,8,null,null,7,4";
    // std::string input = "-1,0,3,-2,4,null,null,8";
    std::string input = "37,-34,-48,null,-100,-101,48,null,null,null,null,-54,null,-71,-22,null,null,null,8";
    util::Helper h;
    TreeNode *root = h.convert_string_to_tree(input);
    Solution s;
    auto result = s.lowestCommonAncestor(root, new TreeNode(-71), new TreeNode(8));
    std::cout << "find LCA: " << result->val << std::endl;
    return 0;
}