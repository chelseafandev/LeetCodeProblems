/*
Merge two sorted linked lists and return it as a sorted list. 
The list should be made by splicing together the nodes of the first two lists.

Example 1:
Input: l1 = [1,2,4], l2 = [1,3,4]
Output: [1,1,2,3,4,4]

Example 2:\
Input: l1 = [], l2 = []
Output: []

Example 3:
Input: l1 = [], l2 = [0]
Output: [0]

Constraints:

The number of nodes in both lists is in the range [0, 50].
-100 <= Node.val <= 100
Both l1 and l2 are sorted in non-decreasing order.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <iostream>
#include <algorithm>
#include <vector>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        std::vector<int> v1, v2;
        getVector(l1, v1);
        getVector(l2, v2);

        if (v1.empty() && v2.empty())
        {
            return nullptr;
        }

        std::vector<int>::iterator itr;
        for (itr = v2.begin(); itr != v2.end(); itr++)
        {
            v1.push_back(*itr);
        }

        std::sort(v1.begin(), v1.end());

        ListNode *retNode = new ListNode(v1.at(0));
        ListNode *cur = retNode;

        int nLen = v1.size();
        for (int i = 1; i < nLen; i++)
        {
            ListNode *addNode = new ListNode(v1.at(i));
            cur->next = addNode;
            cur = addNode;
        }

        return retNode;
    }

private:
    void getVector(ListNode *l, std::vector<int> &v)
    {
        ListNode *cur = l;
        if (cur == nullptr)
        {
            return;
        }

        v.push_back(cur->val);
        while (cur->next != nullptr)
        {
            v.push_back(cur->next->val);
            cur = cur->next;
        }
    }
};

int main()
{
    std::vector<int> input1 = {1, 2, 4, 8, 10};
    std::vector<int> input2 = {1, 3, 4, 5, 9, 14};
    std::vector<int>::iterator itr;
    ListNode *l1 = new ListNode(input1.at(0));
    ListNode *curNode = l1;
    for (itr = input1.begin(); itr != input1.end(); itr++)
    {
        if (itr == input1.begin())
        {
            continue;
        }
        ListNode *addedNode = new ListNode(*itr);
        curNode->next = addedNode;
        curNode = addedNode;
    }

    ListNode *l2 = new ListNode(input2.at(0));
    curNode = l2;
    for (itr = input2.begin(); itr != input2.end(); itr++)
    {
        if (itr == input2.begin())
        {
            continue;
        }
        ListNode *addedNode = new ListNode(*itr);
        curNode->next = addedNode;
        curNode = addedNode;
    }

    Solution s;
    ListNode *ret = s.mergeTwoLists(l1, l2);
    ListNode *cur = ret;
    std::cout << cur->val;
    while (cur->next != nullptr)
    {
        cur = cur->next;
        std::cout << cur->val;
    }

    return 0;
}