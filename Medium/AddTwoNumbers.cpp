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
#include <list>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

double getDoubleVal(ListNode *l)
{
    std::vector<int> vecInt;
    ListNode *lNext = l->next;
    if (lNext == nullptr)
    {
        return (double)l->val;
    }
    else
    {
        vecInt.push_back(l->val);
        while (lNext != nullptr)
        {
            vecInt.push_back(lNext->val);
            lNext = lNext->next;
        }
    }

    std::string int2Str = "";
    std::vector<int>::reverse_iterator itr;
    for (itr = vecInt.rbegin(); itr != vecInt.rend(); itr++)
    {
        int2Str += std::to_string(*itr);
    }

    return std::stod(int2Str);
}

ListNode *getList(double num)
{
    std::cout << "num: " << num << std::endl;
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
    double num1, num2;
    num1 = getDoubleVal(l1);
    num2 = getDoubleVal(l2);

    // 큰 수와 작은 수를 더하는 경우 부동소수점 오류 발생할 수 있음
    return getList(num1 + num2);
}

int main()
{
    std::vector<int> input1 = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1};
    std::vector<int> input2 = {5, 6, 4};
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

    ListNode *ret = addTwoNumbers(l1, l2);
    ListNode *cur = ret;
    std::cout << cur->val;
    while (cur->next != nullptr)
    {
        cur = cur->next;
        std::cout << cur->val;
    }
    return 0;
}