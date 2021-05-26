/*
Given the head of a sorted linked list, delete all duplicates such that each element appears only once. 
Return the linked list sorted as well.

Example 1:
Input: head = [1,1,2]
Output: [1,2]

Example 2:
Input: head = [1,1,2,3,3]
Output: [1,2,3]
 

Constraints:

The number of nodes in the list is in the range [0, 300].
-100 <= Node.val <= 100
The list is guaranteed to be sorted in ascending order.
*/
#include <iostream>
#include <vector>

struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution
{
public:
    ListNode* deleteDuplicates(ListNode *head)
    {
        bool postiveCheck[101];
        for (int i = 0; i < 101; i++)
        {
            postiveCheck[i] = false;
        }

        bool negativeCheck[101];
        for (int i = 0; i < 101; i++)
        {
            negativeCheck[i] = false;
        }

        int tmpVal = 0;
        int convertTmpVal = 0;
        ListNode *cur = head;
        while (cur != nullptr)
        {
            tmpVal = cur->val;
            if (tmpVal >= 0)
            {
                if (!postiveCheck[tmpVal])
                {
                    postiveCheck[tmpVal] = true;
                }
            }
            else
            {
                convertTmpVal = -1*(tmpVal);
                if (!negativeCheck[convertTmpVal])
                {
                    negativeCheck[convertTmpVal] = true;
                }
            }
            cur = cur->next;
        }

        ListNode *retNode = nullptr;
        ListNode *curNode = nullptr;
        for (int i = 100; i >= 0; i--)
        {
            if (negativeCheck[i])
            {
                ListNode *addedNode = new ListNode(-1*i);
                if (curNode == nullptr)
                {
                    curNode = addedNode;
                    retNode = addedNode;
                }
                else
                {
                    curNode->next = addedNode;
                    curNode = addedNode;
                }
            }
        }

        for (int i = 0; i < 101; i++)
        {
            if (postiveCheck[i])
            {
                ListNode *addedNode = new ListNode(i);
                if (curNode == nullptr)
                {
                    curNode = addedNode;
                    retNode = addedNode;
                }
                else
                {
                    curNode->next = addedNode;
                    curNode = addedNode;
                }
            }
        }

        return retNode;
    }
};

int main()
{
    std::vector<int> input1 = {-10, -5, -5, 0 , 1, 2, 3, 3, 3, 4, 5, 6, 6, 99};
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

    Solution s;
    ListNode *ret = s.deleteDuplicates(l1);
    ListNode *cur = ret;
    std::cout << cur->val << " -> ";
    while (cur->next != nullptr)
    {
        cur = cur->next;
        if(cur->next == nullptr)
        {
            std::cout << cur->val;
        }
        else
        {
            std::cout << cur->val << " -> ";
        }
    }
    std::cout << std::endl;
    
    return 0;
}