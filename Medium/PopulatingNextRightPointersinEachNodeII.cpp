/*
Given a binary tree

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}

Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
Initially, all next pointers are set to NULL.

Example 1:
Input: root = [1,2,3,4,5,null,7]
Output: [1,#,2,3,#,4,5,7,#]
Explanation: Given the above binary tree (Figure A), your function should populate each next pointer to point to its next right node, just like in Figure B. The serialized output is in level order as connected by the next pointers, with '#' signifying the end of each level.

Example 2:
Input: root = []
Output: []

Constraints:
The number of nodes in the tree is in the range [0, 6000].
-100 <= Node.val <= 100


Follow-up:
You may only use constant extra space.
The recursive approach is fine. You may assume implicit stack space does not count as extra space for this problem.
*/

#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include "Common/Helper.h"

class Solution
{
public:
    typedef std::map<int, std::vector<SpecialNode*>> map_type;

    struct QueueData
    {
        int level;
        SpecialNode* node;
    };

    // 50ms, 18.4MB
    SpecialNode* connect(SpecialNode* root)
    {
        map_type nodes_per_level;
        make_nodes_per_level_map(nodes_per_level, root, 0);

        for (const auto& nodes : nodes_per_level)
        {
            for (int i = 0; i < nodes.second.size() - 1; i++)
            {
                (nodes.second)[i]->next = (nodes.second)[i+1];
            }
        }

        return root;
    }
    
    // bfs 활용
    // 18ms, 17.7MB
    SpecialNode* connect_version2(SpecialNode* root)
    {
        if (root == nullptr)
        {
            return root;
        }

        std::queue<QueueData> q;
        QueueData data;
        data.level = 0;
        data.node = root;
        q.push(data);
        QueueData prev = data;

        // bfs
        while(!q.empty())
        {
            auto popped = q.front();
            q.pop();

            if (popped.node->left != nullptr)
            {
                QueueData added;
                added.level = popped.level + 1;
                added.node = popped.node->left;
                q.push(added);
            }

            if (popped.node->right != nullptr)
            {
                QueueData added;
                added.level = popped.level + 1;
                added.node = popped.node->right;
                q.push(added);
            }

            if (prev.level != 0 && prev.level == popped.level)
            {
                // set prev and next
                prev.node->next = popped.node;
                prev = popped;
            }
            else
            {
                // set prev
                prev = popped;
            }
        }

        return root;
    }

private:
    void make_nodes_per_level_map(map_type& nodes_per_level, SpecialNode* root, int level)
    {
        if (root == nullptr)
        {
            return;
        }

        if (nodes_per_level.find(level) != nodes_per_level.end())
        {
            nodes_per_level[level].push_back(root);
        }
        else
        {
            std::vector<SpecialNode*> tmp;
            tmp.push_back(root);
            nodes_per_level.insert(std::make_pair(level, tmp));
        }

        level++;
        make_nodes_per_level_map(nodes_per_level, root->left, level);
        make_nodes_per_level_map(nodes_per_level, root->right, level);
    }
};

int main()
{
    std::string input = "1,2,3,4,5,null,7";
    util::Helper h;
    SpecialNode* root = h.convert_string_to_tree_for_special_node(input);
    Solution s;
    s.connect(root);
    return 0;
}