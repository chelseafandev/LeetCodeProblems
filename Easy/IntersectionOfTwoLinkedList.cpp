/*
Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect.
If the two linked lists have no intersection at all, return null.

For example, the following two linked lists begin to intersect at node c1:

It is guaranteed that there are no cycles anywhere in the entire linked structure.

Note that the linked lists must retain their original structure after the function returns.

Example 1:
Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], skipA = 2, skipB = 3
Output: Intersected at '8'
Explanation: The intersected node's value is 8 (note that this must not be 0 if the two lists intersect).
From the head of A, it reads as [4,1,8,4,5]. From the head of B, it reads as [5,6,1,8,4,5]. 
There are 2 nodes before the intersected node in A; There are 3 nodes before the intersected node in B.

Example 2:
Input: intersectVal = 2, listA = [1,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1
Output: Intersected at '2'
Explanation: The intersected node's value is 2 (note that this must not be 0 if the two lists intersect).
From the head of A, it reads as [1,9,1,2,4]. From the head of B, it reads as [3,2,4]. 
There are 3 nodes before the intersected node in A; There are 1 node before the intersected node in B.

Example 3:
Input: intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2
Output: No intersection
Explanation: From the head of A, it reads as [2,6,4]. From the head of B, it reads as [1,5].
Since the two lists do not intersect, intersectVal must be 0, while skipA and skipB can be arbitrary values.
Explanation: The two lists do not intersect, so return null.

Constraints:

The number of nodes of listA is in the m.
The number of nodes of listB is in the n.
0 <= m, n <= 3 * 10^4
1 <= Node.val <= 10^5
0 <= skipA <= m
0 <= skipB <= n
intersectVal is 0 if listA and listB do not intersect.
intersectVal == listA[skipA + 1] == listB[skipB + 1] if listA and listB intersect.
*/
#include <iostream>
#include <vector>
#include <stack>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *retNode = nullptr;

        std::stack<int> stackA, stackB;
        ListNode *cur = headA;
        if (cur == nullptr)
        {
            return nullptr;
        }

        while (cur != nullptr)
        {
            stackA.push(cur->val);
            cur = cur->next;
        }

        cur = headB;
        if (cur == nullptr)
        {
            return nullptr;
        }

        while (cur != nullptr)
        {
            stackB.push(cur->val);
            cur = cur->next;
        }

        int nLen = 0;
        if (stackA.size() > stackB.size())
        {
            nLen = stackB.size();
        }
        else
        {
            nLen = stackA.size();
        }

        std::vector<int> candidate;
        for (int i = 0; i < nLen; i++)
        {
            if (stackA.top() == stackB.top())
            {
                candidate.push_back(stackA.top());
                stackA.pop();
                stackB.pop();
            }
            else
            {
                break;
            }
        }

        if (candidate.empty())
        {
            return nullptr;
        }
        else
        {

            std::vector<int>::reverse_iterator ritr = candidate.rbegin();
            retNode = new ListNode(*ritr);
            ListNode *cur = retNode;
            for (ritr = candidate.rbegin() + 1; ritr != candidate.rend(); ritr++)
            {
                ListNode *added = new ListNode(*ritr);
                cur->next = added;
                cur = cur->next;
            }
        }

        return retNode;
    }
};

int main()
{
    std::vector<int> input1 = {4, 1, 8, 4, 5};
    std::vector<int> input2 = {5, 6, 1, 8, 4, 5};
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
    ListNode *ret = s.getIntersectionNode(l1, l2);
    ListNode *cur = ret;
    std::cout << cur->val;
    while (cur->next != nullptr)
    {
        std::cout << " → ";
        cur = cur->next;
        std::cout << cur->val;
    }
    return 0;
}