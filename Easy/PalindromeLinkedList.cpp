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
    bool isPalindrome_version2(ListNode *head)
    {
        
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