/*
Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.
A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.

Constraints:
1 <= nums.length <= 10^4
-10^4 <= nums[i] <= 10^4
nums is sorted in a strictly increasing order.
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

class Solution
{
public:
    TreeNode *sortedArrayToBST(std::vector<int> &nums)
    {
        // 정렬된 vector가 인자로 넘어온다는 걸 잘 이용하자
        // vector의 중간 값은 항상 BST root가 된다(!)
        // 재귀 호출을 사용하여 왼쪽 서브 트리를 구성할때는 vector의 중간 값 기준으로 좌측의 sub vector를 전달하고, 오른쪽 서브 트리를 구성할때는 vector의 중간 값 기준으로 우측 sub vector를 전달한다
        
        if (nums.size() == 0)
            return nullptr;

        if (nums.size() == 1)
            return new TreeNode(nums[0]);

        // root val 결정
        int idx = nums.size() / 2;
        TreeNode* newNode = new TreeNode(nums[idx]);

        // 왼쪽 서브 트리를 구성할 sub vector
        std::vector<int> left_sub_vector;
        for(int i = 0; i < idx; i++)
        {
            left_sub_vector.push_back(nums[i]);
        }

        // 오른쪽 서브 트리를 구성할 sub vector
        std::vector<int> right_sub_vector;
        for(int j = idx + 1; j < nums.size(); j++)
        {
            right_sub_vector.push_back(nums[j]);
        }

        newNode->left = sortedArrayToBST(left_sub_vector);
        newNode->right = sortedArrayToBST(right_sub_vector);

        return newNode;
    }
};

int main()
{
    std::vector<int> input = {-10, -3, 0, 5, 9};
    Solution s;
    TreeNode *output = s.sortedArrayToBST(input);
    return 0;
}
