/*
Given the head of a singly linked list, reverse the list, and return the reversed list.

Example 1:
Input: head = [1,2,3,4,5]
Output: [5,4,3,2,1]

Example 2:
Input: head = [1,2]
Output: [2,1]

Example 3:
Input: head = []
Output: []

Constraints:

The number of nodes in the list is the range [0, 5000].
-5000 <= Node.val <= 5000
*/

#include <iostream>
#include <vector>

#include "Common/Helper.h"

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if (head == nullptr)
            return nullptr;

        std::vector<int> v;
        ListNode *cur = head;
        do{
            v.push_back(cur->val);
            cur = cur->next;
        } while(cur != nullptr);

        ListNode *result = nullptr;
        ListNode *prev = nullptr;
        std::vector<int>::reverse_iterator ritr;
        for(ritr = v.rbegin(); ritr != v.rend(); ritr++)
        {
            ListNode *added = new ListNode(*ritr);

            if(prev != nullptr)
                prev->next = added;
            else
                result = added;
                
            prev = added;
        }

        return result;
    }
};

int main()
{
    std::string input = "";
    util::Helper helper;
    ListNode *head = helper.convertStr2List(input);
    helper.printListNode(head);

    Solution s;
    ListNode *result = s.reverseList(head);
    helper.printListNode(result);

    return 0;
}