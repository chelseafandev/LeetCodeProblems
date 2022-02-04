/*
Given the head of a singly linked list, return true if it is a palindrome.

Example 1:
Input: head = [1,2,2,1]
Output: true

Example 2:
Input: head = [1,2]
Output: false


Constraints:
The number of nodes in the list is in the range [1, 10^5].
0 <= Node.val <= 9
 

Follow up: Could you do it in O(n) time and O(1) space?
*/

#include "Common/Helper.h"
#include <stack>

class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        std::stack<int> stack_val;

        int size = 0;
        ListNode *cur = head;
        while(cur != nullptr)
        {
            size++;
            cur = cur->next;
        }

        if(size == 1)
            return true;

        cur = head;
        int count = size / 2;
        for(int i = 0; i < count; i++)
        {
            stack_val.push(cur->val);
            cur = cur->next;
        }

        if(size % 2 != 0)
        {
            cur = cur->next;
        }

        while(cur != nullptr)
        {
            int top = stack_val.top();
            if(top != cur->val)
            {
                return false;
            }
            stack_val.pop();
            cur = cur->next;
        }

        return true;
    }

    // Follow up: Could you do it in O(n) time and O(1) space?
    bool isPalindrome_version2(ListNode* head)
    {
        ListNode* slow_ptr = head;
        ListNode* fast_ptr = head;

        ListNode* second_half = head;
        ListNode* prev_of_slow_ptr = head;

        // To handle odd size list
        ListNode* midnode = nullptr;

        // initialize result
        bool res = true;

        if (head != nullptr && head->next != nullptr)
        {
            // Get the middle of the list. Move slow_ptr by 1 and fast_ptr by 2, slow_ptr will have the middle node
            while (fast_ptr != nullptr && fast_ptr->next != nullptr)
            {
                fast_ptr = fast_ptr->next->next;

                // We need previous of the slow_ptr for linked lists with odd elements
                prev_of_slow_ptr = slow_ptr;
                slow_ptr = slow_ptr->next;
            }

            // fast_ptr would become nullptr when there are even elements in list. And not nullptr for odd elements.
            // We need to skip the middle node for odd case and store it somewhere so that we can restore the original list
            if (fast_ptr != nullptr)
            {
                midnode = slow_ptr;
                slow_ptr = slow_ptr->next;
            }

            // Now reverse the second half and compare it with first half
            second_half = slow_ptr;

            // nullptr terminate first half
            prev_of_slow_ptr->next = nullptr;

            // Reverse the second half
            reverse(&second_half);

            // compare
            res = compareLists(head, second_half);

            // Construct the original list back
            reverse(&second_half); // Reverse the second half again

            // If there was a mid node (odd size case) which was not part of either first half or second half.
            if (midnode != nullptr)
            {
                prev_of_slow_ptr->next = midnode;
                midnode->next = second_half;
            }
            else
            {
                prev_of_slow_ptr->next = second_half;
            }
        }

        return res;
    }

private:
    // Function to reverse the linked list
    // Note that this function may change the head
    void reverse(ListNode **head_ref)
    {
        ListNode* prev = nullptr;
        ListNode* current = *head_ref;
        ListNode* next;

        while (current != nullptr)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        *head_ref = prev;
    }

    // Function to check if two input lists have same data
    bool compareLists(ListNode* head1, ListNode* head2)
    {
        ListNode* temp1 = head1;
        ListNode* temp2 = head2;

        while (temp1 && temp2)
        {
            if (temp1->val == temp2->val)
            {
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
            else
            {
                return 0;
            }
        }

        // Both are empty return 1
        if (temp1 == nullptr && temp2 == nullptr)
            return 1;

        // Will reach here when one is nullptr and other is not
        return 0;
    }
};

int main()
{
    std::string input = "1,2,3,2,1";
    util::Helper helper;
    ListNode *head = helper.convert_string_to_list(input);
    
    Solution s;
    // std::cout << std::boolalpha << s.isPalindrome(head) << std::endl;
    std::cout << std::boolalpha << s.isPalindrome_version2(head) << std::endl;
    return 0;
}