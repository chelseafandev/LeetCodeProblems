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

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        std::vector<int> vec1, vec2, result;
        setInputData(l1, vec1);
        setInputData(l2, vec2);

        int v1Len = vec1.size();
        int v2Len = vec2.size();
        int nLen = 0;
        int nIdx = 0;
        int nRemain = 0;
        if (v1Len > v2Len)
        {
            nLen = v2Len;
            nRemain = v1Len - v2Len;
        }
        else
        {
            nLen = v1Len;
            nRemain = v2Len - v1Len;
        }

        bool carryExist = false;
        int partialSum = 0;
        for (nIdx = 0; nIdx < nLen; nIdx++)
        {
            if (carryExist)
            {
                partialSum = vec1.at(nIdx) + vec2.at(nIdx) + 1;
            }
            else
            {
                partialSum = vec1.at(nIdx) + vec2.at(nIdx);
            }

            if (partialSum > 9)
            {
                carryExist = true;
                partialSum %= 10;
            }
            else
            {
                carryExist = false;
            }

            result.push_back(partialSum);
        }

        for (int i = nIdx; i < nIdx + nRemain; i++)
        {
            if (v1Len > v2Len)
            {
                if (carryExist)
                {
                    partialSum = vec1.at(i) + 1;
                }
                else
                {
                    partialSum = vec1.at(i);
                }
                if (partialSum > 9)
                {
                    carryExist = true;
                    partialSum %= 10;
                }
                else
                {
                    carryExist = false;
                }

                result.push_back(partialSum);
            }
            else
            {
                if (carryExist)
                {
                    partialSum = vec2.at(i) + 1;
                }
                else
                {
                    partialSum = vec2.at(i);
                }
                if (partialSum > 9)
                {
                    carryExist = true;
                    partialSum %= 10;
                }
                else
                {
                    carryExist = false;
                }

                result.push_back(partialSum);
            }
        }

        // 같은 자리수임에도 불구하고 마지막에 carry가 하나 있다면
        if(carryExist)
        {
            result.push_back(1);
        }

        std::cout << "result vector: ";
        std::vector<int>::iterator itr;
        for (itr = result.begin(); itr != result.end(); itr++)
        {
            std::cout << *itr;
        }
    }

private:
    void setInputData(ListNode *l, std::vector<int> &vec)
    {
        ListNode *lNext = l->next;
        if (lNext == nullptr)
        {
            vec.push_back(l->val);
            return;
        }
        else
        {
            vec.push_back(l->val);
            while (lNext != nullptr)
            {
                vec.push_back(lNext->val);
                lNext = lNext->next;
            }
        }
    }
};

int main()
{
    std::vector<int> input1 = {2, 4, 8};
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

    Solution s;
    s.addTwoNumbers(l1, l2);
    return 0;
}