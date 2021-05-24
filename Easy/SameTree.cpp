/*
Given the roots of two binary trees p and q, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

Example 1:
Input: p = [1,2,3], q = [1,2,3]
Output: true

Example 2:
Input: p = [1,2], q = [1,null,2]
Output: false

Example 3:
Input: p = [1,2,1], q = [1,1,2]
Output: false

Constraints:

The number of nodes in both trees is in the range [0, 100].
-10^4 <= Node.val <= 10^4
*/
#include <iostream>
#include <vector>

#define NULL_NODE 10001

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
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        std::vector<int> p2v, q2v;
        makeTree2Vec(p, p2v);
        makeTree2Vec(q, q2v);

        int p2vSize = p2v.size();
        int q2vSize = q2v.size();

        if(p2vSize != q2vSize)
        {
            return false;
        }
        else
        {
            for(int i = 0; i < p2vSize; i++)
            {
                if(p2v[i] != q2v[i])
                    return false;
            }
        }

        return true;
    }
private:
    void makeTree2Vec(TreeNode *node, std::vector<int> &result)
    {
        TreeNode *cursor = node;
        if(cursor != nullptr)
        {
            result.push_back(cursor->val);
            makeTree2Vec(cursor->left, result);
            makeTree2Vec(cursor->right, result);
        }
        else
        {
            result.push_back(NULL_NODE);
        }
    }
};

int main()
{
    TreeNode *p = new TreeNode(1, new TreeNode(2), new TreeNode(1));
    TreeNode *q = new TreeNode(1, nullptr, new TreeNode(1));
    
    Solution s;
    if(s.isSameTree(p, q))
    {
        std::cout << "isSameTree(p, q) is true!" << std::endl;
    }
    else
    {
        std::cout << "isSameTree(p, q) is false!" << std::endl;
    }

    return 0;
}