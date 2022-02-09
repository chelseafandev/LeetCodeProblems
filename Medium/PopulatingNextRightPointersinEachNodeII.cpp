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

    // depth와 node로 구성된 구조체 정의
    struct QueueData
    {
        int depth;
        SpecialNode* node;
    };

    // 50ms, 18.4MB
    SpecialNode* connect(SpecialNode* root)
    {
        map_type nodes_per_depth;
        make_nodes_per_depth_map(nodes_per_depth, root, 0);

        for (const auto& nodes : nodes_per_depth)
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

        // bfs를 수행하며 next를 구성하기 위해 각 노드의 depth를 함께 저장하고 있는 QueueData 구조체를 활용
        std::queue<QueueData> q;
        QueueData data;
        data.depth = 0;
        data.node = root;
        q.push(data);

        // connection 규칙
        // - 현재 pop한 노드는 (동일한 depth 내에있는) 이전 노드(prev)의 next로 저장한다.
        // - connection 작업이 끝난 현재 pop한 노드는 이전 노드(prev)가 된다.
        QueueData prev = data;

        // bfs
        while(!q.empty())
        {
            auto popped = q.front();
            q.pop();

            if (popped.node->left != nullptr)
            {
                QueueData added;
                added.depth = popped.depth + 1;
                added.node = popped.node->left;
                q.push(added);
            }

            if (popped.node->right != nullptr)
            {
                QueueData added;
                added.depth = popped.depth + 1;
                added.node = popped.node->right;
                q.push(added);
            }

            // connection
            if (prev.depth != 0 && prev.depth == popped.depth)
            {
                prev.node->next = popped.node;   
            }

            // set prev
            prev = popped;
        }

        return root;
    }

private:
    void make_nodes_per_depth_map(map_type& nodes_per_depth, SpecialNode* root, int depth)
    {
        if (root == nullptr)
        {
            return;
        }

        if (nodes_per_depth.find(depth) != nodes_per_depth.end())
        {
            nodes_per_depth[depth].push_back(root);
        }
        else
        {
            std::vector<SpecialNode*> tmp;
            tmp.push_back(root);
            nodes_per_depth.insert(std::make_pair(depth, tmp));
        }

        depth++;
        make_nodes_per_depth_map(nodes_per_depth, root->left, depth);
        make_nodes_per_depth_map(nodes_per_depth, root->right, depth);
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