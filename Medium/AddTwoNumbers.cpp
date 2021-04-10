/*
You are given two non-empty linked lists representing two non-negative integers. 
The digits are stored in reverse order, and each of their nodes contains a single digit. 
Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example1:
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.

Constraints:
The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

double getSum(ListNode *l1, ListNode *l2)
{
    double Ret = 0;

    std::vector<int> v1, v2;
    ListNode *l1Next = l1->next;
    if (l1Next == nullptr)
    {
        Ret += (double)l1->val;
    }
    else
    {
        v1.push_back(l1->val);
        while (l1Next != nullptr)
        {
            v1.push_back(l1Next->val);
            l1Next = l1Next->next;
        }

        // reverse string to forward string
        std::reverse(v1.begin(), v1.end());
    }

    ListNode *l2Next = l2->next;
    if (l2Next == nullptr)
    {
        Ret += (double)l2->val;
    }
    else
    {
        v2.push_back(l2->val);
        while (l2Next != nullptr)
        {
            v2.push_back(l2Next->val);
            l2Next = l2Next->next;
        }

        // reverse string to forward string
        std::reverse(v2.begin(), v2.end());
    }

    return 1.0;
}

ListNode *getList(double num)
{
    ListNode *retNode = nullptr;
    std::string strNum = std::to_string(num);
    int value = 0;
    if (num < 10)
    {
        value = num;
        ListNode *retNode = new ListNode(value);
        return retNode;
    }
    else
    {
        int idx = 0;
        std::string::iterator itr;
        for (itr = strNum.begin(); itr != strNum.end(); itr++)
        {
            if (strNum.at(idx) == '.')
            {
                break;
            }
            idx++;
        }

        int LastIdx = idx - 1;
        ListNode *curNode = nullptr;
        value = strNum.at(LastIdx) - '0';
        retNode = new ListNode(value);
        curNode = retNode;

        for (int i = LastIdx - 1; i >= 0; i--)
        {
            value = strNum.at(i) - '0';
            ListNode *addedNode = new ListNode(value);
            curNode->next = addedNode;
            curNode = addedNode;
        }
    }

    return retNode;
}

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    return getList(getSum(l1, l2));
}

int main()
{
    ListNode *l1_3 = new ListNode(3);
    ListNode *l1_2 = new ListNode(4, l1_3);
    ListNode *l1_1 = new ListNode(2, l1_2);

    ListNode *l2_3 = new ListNode(4);
    ListNode *l2_2 = new ListNode(6, l1_3);
    ListNode *l2_1 = new ListNode(5, l1_2);

    ListNode *ret = addTwoNumbers(l1_1, l2_1);

    //std::cout << ret->val << std::endl;
    //std::cout << ret->next->val << std::endl;
    //std::cout << ret->next->next->val << std::endl;

    return 0;
}