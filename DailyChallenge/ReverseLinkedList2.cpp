/*
Given the head of a singly linked list and two integers left and right where left <= right, 
reverse the nodes of the list from position left to position right, and return the reversed list.
 

Example 1:
Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]

Example 2:
Input: head = [5], left = 1, right = 1
Output: [5]
 

Constraints:

The number of nodes in the list is n.
1 <= n <= 500
-500 <= Node.val <= 500
1 <= left <= right <= n
*/
#include <iostream>
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
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        std::vector<int> bag;
        std::vector<int> reverse_bag;
        std::vector<int> merge_bag;

        int target = 1;
        ListNode *cur = head;
        while (cur != nullptr)
        {
            if (target >= left && target <= right)
            {
                reverse_bag.push_back(cur->val);
            }
            else
            {
                bag.push_back(cur->val);
            }

            target++;
            cur = cur->next;
        }

        std::vector<int>::iterator itr = bag.begin();
        std::vector<int>::reverse_iterator ritr = reverse_bag.rbegin();

        int size = bag.size() + reverse_bag.size();
        int cnt = 0;
        while (cnt < size)
        {
            cnt++;
            if (cnt < left)
            {
                merge_bag.push_back(*itr);
                itr++;
            }
            else if (cnt >= left && cnt <= right)
            {
                merge_bag.push_back(*ritr);
                ritr++;
            }
            else
            {
                merge_bag.push_back(*itr);
                itr++;
            }
        }

        itr = merge_bag.begin();
        ListNode *result = new ListNode(*itr);
        ListNode *curNode = result;
        for (itr = merge_bag.begin(); itr != merge_bag.end(); itr++)
        {
            if (itr == merge_bag.begin())
            {
                continue;
            }

            ListNode *addedNode = new ListNode(*itr);
            curNode->next = addedNode;
            curNode = addedNode;
        }

        return result;
    }
};

int main()
{
    int left = 2;
    int right = 4;
    std::vector<int> input1 = {1, 2, 3, 4, 5};
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
    ListNode *ret = s.reverseBetween(l1, left, right);
    ListNode *cur = ret;
    std::cout << cur->val;
    while (cur->next != nullptr)
    {
        cur = cur->next;
        std::cout << cur->val;
    }

    return 0;
}